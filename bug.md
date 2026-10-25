# Libft bug review

Reviewed all 48 existing project files: the 43 library sources, `ff.c`,
`libft.h`, `Makefile`, `README.md`, and the `a.out` executable. Source references
below use the original file line numbers. No implementation files were changed.

There are **four reproduced behavior/API bugs in three source/header files**.
Additional findings below describe performance, large-input, portability, and
formatting concerns separately, so they are not confused with failures observed
on this machine.

## Confirmed bugs

### B1 — `libft.h`: missing `ft_putnbr_fd` declaration

- **Priority:** High — breaks compilation for callers.
- **Location:** lines 52–54, where the other output functions are declared.
- **Problem:** `ft_putnbr_fd` exists in `ft_putnbr_fd.c` and is built into the
  archive, but the public header never declares it.
- **Reproduction:** compile the following with
  `cc -Wall -Wextra -Werror -I. -x c -fsyntax-only -`, supplying it on stdin:

  ```c
  #include "libft.h"
  int main(void)
  {
      ft_putnbr_fd(42, 1);
      return (0);
  }
  ```

- **Observed:** compilation fails with an implicit-function-declaration error.
- **Suggested fix:** add `void ft_putnbr_fd(int n, int fd);` to `libft.h`.

### B2 — `ft_atoi.c`: accepts two characters that are not whitespace

- **Priority:** Medium — incorrect conversion result.
- **Location:** line 24.
- **Problem:** the whitespace test accepts ASCII values 7 through 13. In the C
  locale, the control-character whitespace range is 9 through 13, plus space.
  Bell (`'\a'`, 7) and backspace (`'\b'`, 8) must stop conversion here.
- **Reproduction:** `ft_atoi("\a42")` and `ft_atoi("\b42")`.
- **Observed:** both return `42`; the system `atoi` returns `0` for both.
- **Suggested fix:** change the lower bound from `7` to `9`.

### B3 — `ft_atoi.c`: signed overflow for the valid value `INT_MIN`

- **Priority:** High — undefined behavior on valid input.
- **Location:** accumulator declaration at line 19, accumulation at line 38,
  and sign application at line 41.
- **Problem:** the magnitude is accumulated in a positive `int`. For
  `"-2147483648"` on this machine, that magnitude exceeds `INT_MAX` before the
  negative sign is applied. If the accumulator wraps to `INT_MIN`, multiplying
  it by `-1` also overflows.
- **Reproduction:** call `ft_atoi("-2147483648")` after compiling with
  `-fsanitize=undefined -fsanitize-undefined-trap-on-error`.
- **Observed:** the test process terminates with `SIGILL` from an undefined
  behavior trap. An unsanitized build appearing to return the right value does
  not make the arithmetic defined.
- **Suggested fix:** accumulate in the negative range with appropriate bounds
  checks, or use an accumulator that can represent the entire magnitude of any
  `int`, then convert safely.
- **Scope:** this finding concerns a representable `int`. Inputs outside the
  `int` range are not counted as separate libc-compatibility bugs here.

### B4 — `ff.c`: converts a pointer address instead of reading the integer

- **Priority:** Medium — incorrect result in the standalone experiment.
- **Location:** lines 3–4.
- **Problem:** `(long)(int *)f` converts the address to an integer. It never
  reads the pointed-to value. Returning that `long` as `int` can also discard
  address bits.
- **Reproduction:** compile and run `ff.c`; `main` passes the address of an
  integer whose value is `12`.
- **Observed:** one run printed `1961210148`, rather than `12`. The result
  depends on the address. Compiling with `-Wconversion -Werror` also rejects the
  narrowing conversion at line 4.
- **Suggested fix:** if the intent is to read that integer, use
  `return (*(int *)f);` with a valid pointer to an `int`.
- **Scope:** this file is untracked and is not included in the library build.
  Disassembly of `a.out` also shows `ff` returning pointer bits, so that existing
  executable exhibits the same underlying mistake.

## Other problems and limits found in the source

These findings were identified by reading the implementation. The huge-buffer
and alternate-platform cases were not executed and are not failures observed
in the ordinary-input tests.

### S1 — counters cannot traverse every valid string size

| File and location | Problem | Suggested fix |
| --- | --- | --- |
| `ft_strchr.c:17,24` | The `int` index overflows while searching a string that requires advancing past `INT_MAX`, such as a longer string without the requested character. | Use `size_t` or advance a pointer. |
| `ft_atoi.c:18,26,39` | The `int` index can overflow when scanning more than `INT_MAX` leading whitespace characters or digits, including a long sequence of zeroes. | Use `size_t` or advance the input pointer. |
| `ft_strmapi.c:17,29` | The traversal index is `unsigned int`. On this machine it wraps after `UINT_MAX`, so an input longer than that can cause repeated processing or nontermination. | Traverse with `size_t`; convert the index only when passing it to the callback. |
| `ft_striteri.c:17,25` | The same unsigned-index wrap can repeatedly process a sufficiently long string. | Use a `size_t` traversal index and convert at the callback boundary. |
| `ft_strtrim.c:33` | `start` is `size_t`, but `ft_substr` accepts `unsigned int`. A removable prefix longer than `UINT_MAX` truncates the start position and can return the wrong substring. | Pass `s1 + start` to `ft_substr` with start `0`, or copy using `size_t` positions. |

### S2 — `ft_strjoin.c`: allocation-size addition is unchecked

- **Location:** line 26.
- **Problem:** `len1 + len2 + 1` can wrap `size_t` if the combined size is not
  representable. A successful, undersized allocation would then be overwritten
  by the copy loops. The inputs may overlap or even be the same string, so two
  separately allocated input buffers are not required for the sum to overflow.
- **Suggested fix:** reject the request when
  `len1 > (size_t)-1 - len2 - 1` before adding the lengths.
- **Scope:** a boundary arithmetic issue; it was not reproduced with physically
  allocated enormous strings on this 64-bit machine.

### P1 — `ft_lstmap.c`: quadratic list construction

- **Location:** line 44, calling `ft_lstadd_back` for every new node.
- **Problem:** `ft_lstadd_back` calls `ft_lstlast`, which traverses the new list
  from its head each time. Mapping `n` nodes performs about `n(n-1)/2` link
  traversals in addition to the mapping work.
- **Impact:** correct results, but unnecessarily slow for large lists.
- **Suggested fix:** keep a tail pointer and append each new node directly.
  Preserve the existing allocation-failure cleanup.

### P2 — portability assumptions

| File and location | Platform-dependent problem | Suggested fix |
| --- | --- | --- |
| `ft_itoa.c:24,52` | Negating the converted `INT_MIN` overflows on platforms where `long` has the same range as `int`. It works on the tested Linux x86-64 platform because `long` is wider. | Obtain the magnitude using unsigned arithmetic without negating a signed minimum. |
| `ft_putnbr_fd.c:23` | The same `long`-width assumption affects printing `INT_MIN`. | Use unsigned magnitude arithmetic. |
| `ft_memmove.c:23` | Casting pointers to `size_t` assumes that the type can represent pointer values and that their numeric ordering reflects memory order. C does not guarantee those properties for `size_t`. | For a flat-address implementation, use `uintptr_t` where available; otherwise use a strategy appropriate to the target's pointer representation. |

### R1 — optional robustness for descriptor output

- **Files:** `ft_putchar_fd.c:17`, `ft_putstr_fd.c:19`,
  `ft_putendl_fd.c:19–20`, and `ft_putnbr_fd.c:24,31`.
- **Observation:** output functions discard `write` return values. A short
  write can truncate a string, and interruption can lose a character or digit.
  `ft_putendl_fd` inherits this behavior through its helper calls.
- **Suggested improvement:** if reliable output under those conditions is
  required, retry interrupted writes and advance through successfully written
  bytes until completion or a permanent error. The current `void` interfaces
  cannot report a permanent error to the caller.
- **Scope:** the tested blocking-pipe output was correct. This is a robustness
  extension, not a claimed failure against an unavailable project subject.

### F1 — formatting observations to check with Norminette

- `ft_lstmap.c`: the function body spans 31 lines between its outer braces
  (lines 17–47); check it against the applicable function-length rule.
- `ft_itoa.c:33–34`: no blank line separates the two function definitions.
- `ft_bzero.c:11–12`: no blank line separates the file banner and the include.
- Norminette is not installed here, so these are source observations rather
  than output from a completed Norminette run.

## Result for every existing file

“No issue found” means no issue was identified by this review and its tests;
it is not a proof that every possible input is correct. References point to
the findings above.

| File | Result |
| --- | --- |
| `Makefile` | No issue found. Clean build, rebuild, and up-to-date checks passed; the archive contains all 43 library objects. |
| `README.md` | No internal usage/documentation issue found. Exact subject-version and submission requirements were not independently verified. |
| `a.out` | Existing generated x86-64 ELF executable; disassembly shows the pointer-return mistake described in B4. Untracked and unused by `make`. |
| `ff.c` | B4: returns pointer bits instead of the pointed-to integer. |
| `ft_atoi.c` | B2: incorrect whitespace; B3: `INT_MIN` overflow; S1: large-input index overflow. |
| `ft_bzero.c` | No functional issue found; F1 formatting observation. |
| `ft_calloc.c` | No issue found, including multiplication overflow and allocation failure. |
| `ft_isalnum.c` | No issue found. |
| `ft_isalpha.c` | No issue found. |
| `ft_isascii.c` | No issue found. |
| `ft_isdigit.c` | No issue found. |
| `ft_isprint.c` | No issue found. |
| `ft_itoa.c` | No functional issue found on this machine; P2 portability and F1 formatting observations. |
| `ft_lstadd_back.c` | No functional issue found; its linear traversal contributes to P1 when repeatedly called by `ft_lstmap`. |
| `ft_lstadd_front.c` | No issue found. |
| `ft_lstclear.c` | No issue found with a valid deletion callback. |
| `ft_lstdelone.c` | No issue found with a valid deletion callback. |
| `ft_lstiter.c` | No issue found. |
| `ft_lstlast.c` | No issue found. |
| `ft_lstmap.c` | P1: quadratic construction; F1: function-length observation. Allocation-failure cleanup passed. |
| `ft_lstnew.c` | No issue found, including allocation failure. |
| `ft_lstsize.c` | No counting issue found. Its `unsigned int` return type agrees with the supplied header. |
| `ft_memchr.c` | No issue found. |
| `ft_memcmp.c` | No issue found. |
| `ft_memcpy.c` | No issue found for nonoverlapping valid buffers. |
| `ft_memmove.c` | Overlap tests passed; P2 portability observation. |
| `ft_memset.c` | No issue found. |
| `ft_putchar_fd.c` | Output tests passed; R1 optional I/O robustness. |
| `ft_putendl_fd.c` | Output tests passed; R1 optional I/O robustness. |
| `ft_putnbr_fd.c` | Output tests passed, including `INT_MIN`; B1 is in the public header; P2 and R1 observations apply. |
| `ft_putstr_fd.c` | Output tests passed; R1 optional I/O robustness. |
| `ft_split.c` | No issue found, including empty input, repeated delimiters, NUL delimiter, and every allocation-failure position in the tested split. |
| `ft_strchr.c` | Ordinary-input tests passed; S1: signed index overflow for very long strings. |
| `ft_strdup.c` | No issue found, including allocation failure. |
| `ft_striteri.c` | Ordinary-input tests passed; S1: index wrap for very long strings. |
| `ft_strjoin.c` | Ordinary-input tests passed; S2: unchecked allocation-size addition. |
| `ft_strlcat.c` | No issue found, including zero size and a destination without a NUL within the size limit. |
| `ft_strlcpy.c` | No issue found, including zero size and truncation. |
| `ft_strlen.c` | No issue found. |
| `ft_strmapi.c` | Ordinary-input and allocation-failure tests passed; S1: index wrap for very long strings. |
| `ft_strncmp.c` | No issue found. |
| `ft_strnstr.c` | No issue found, including empty needle and search-length boundaries. |
| `ft_strrchr.c` | No issue found, including searching for the terminating NUL. |
| `ft_strtrim.c` | Ordinary-input tests passed; S1: narrowing of a very large start position. |
| `ft_substr.c` | No issue found, including start beyond the string and `SIZE_MAX` requested length. |
| `ft_tolower.c` | No issue found. |
| `ft_toupper.c` | No issue found. |
| `libft.h` | B1: missing `ft_putnbr_fd` prototype. |

## Validation performed

- Tests and builds ran in an isolated copy under `/tmp`, leaving existing
  project files and the untracked `ff.c` and `a.out` untouched.
- `make -j4`, `make -j4 re`, and `make -q` passed. `ar t libft.a` listed 43
  objects.
- A temporary C harness completed **1,129,270 checks across all 43 library
  functions**, including deterministic randomized memory/string comparisons,
  character checks against the C library, conversion checks, list operations,
  and descriptor output. The already identified bad whitespace cases and
  `INT_MIN` parsing were reproduced separately from this passing suite.
- The harness used GCC undefined-behavior instrumentation with traps, avoiding
  the unavailable sanitizer runtime libraries.
- **31 allocation scenarios** tested success and injected allocation failures
  across the allocating functions, including split cleanup and list-map
  cleanup. Tracked allocations were all released and allocation guards remained
  intact. A NULL mapping result was treated as valid list content.
- Ordinary AddressSanitizer/UndefinedBehaviorSanitizer linking was attempted
  but failed because `libasan` and `libubsan` runtime files are missing. The
  checks above do not replace a full AddressSanitizer run.
- Norminette and the exact campus project subject were unavailable. No
  subject-specific signature or bonus-target violation is asserted without
  that subject; in particular, the supplied header and source agree on the
  `unsigned int` return type of `ft_lstsize`.
- NULL arguments outside a function's stated/normal input contract were not
  counted as bugs merely because some other functions choose to tolerate them.
