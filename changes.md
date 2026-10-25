# Complete change record

Recorded on 2026-10-25 for `anes-sal`, using the Libft v19.3 subject supplied in
this conversation.

This file records the build configuration, documentation, study material, source
corrections, formatting changes, verification, backups, and Git operations carried
out during this conversation. The final appendix contains the complete textual
staged patch against Git HEAD, including every changed source line.

## 1. Scope and attribution

The work happened in several steps:

1. Created a Makefile without modifying the C sources or header at that stage.
2. Created the required README and checked source/header coverage.
3. Read all 48 project files then present and created a detailed question bank.
4. Reviewed the project against the complete v19.3 subject you supplied.
5. Applied the requested corrections, checked them, preserved study files outside
   the submission repository, and staged the resulting submission changes.
6. Explained how to run the temporary Norminette installation.
7. Created this `changes.md` file at your request.

The initial Makefile and README incorrectly treated linked lists as a bonus part.
After you supplied v19.3, that assumption was corrected: all 43 functions are
mandatory and belong in the default build.

Some changes visible in the staged patch were already your changes when the final
correction pass began:

- `ft_bzero.c` already delegated to `ft_memset` through a one-line wrapper.
- `ft_memcpy.c` already used `const unsigned char *` for its source pointer.
- `libft.h` already had your correction from `ft_print` to `ft_isprint`.
- You had already removed the `str` and `str2` globals from `ft_memmove.c`.
- Your current `main.c` already demonstrated `ft_strlen` instead of the earlier
  string-copy/concatenation example.
- `a.out` was already deleted from the working directory.

Those changes were preserved. The patch appendix records the complete staged
result relative to HEAD, so it includes those existing edits as well as my work.
The original status and unstaged patch are preserved in the backup described below.

## 2. Makefile

Created [Makefile](Makefile) and then corrected it for the supplied subject.

| Area | Final change |
| --- | --- |
| Output | `NAME = libft.a`, created in the build directory with `ar`. |
| Compiler | `CC = cc`. |
| Compiler flags | `-Wall -Wextra -Werror`; existing support for `CPPFLAGS` is retained. |
| Archiver | `AR = ar` with `ARFLAGS = rcs`. |
| Cleanup command | `RM = rm -f`. |
| Source list | Explicitly lists all 43 required `.c` files. |
| Object list | Derives object names with `$(SRCS:.c=.o)`. |
| Dependencies | Every object depends on its source, `libft.h`, and `Makefile`. |
| Default build | `make` and `make all` build all mandatory parts, including linked lists. |
| Archive rule | `make libft.a` builds the same complete archive. |
| `clean` | Removes all object files while keeping the archive. |
| `fclean` | Runs cleanup and removes the archive. |
| `re` | Completes recursive `fclean` before starting recursive `all`. |
| Phony rules | Declares `all`, `clean`, `fclean`, and `re` phony. |
| Incremental behavior | An unchanged second build does not recompile objects or update the archive. |

The initial version separated 34 functions from 9 linked-list functions using
`BONUS_SRCS`, `BONUS_OBJS`, a `bonus` target, and a `.bonus` stamp. The correction
merged the list sources into `SRCS` and removed those bonus variables, the stamp
rule, the bonus recipe, bonus cleanup entries, and the phony bonus declaration.

The nine list sources now built by ordinary `make` are:

```text
ft_lstnew.c
ft_lstadd_front.c
ft_lstsize.c
ft_lstlast.c
ft_lstadd_back.c
ft_lstdelone.c
ft_lstclear.c
ft_lstiter.c
ft_lstmap.c
```

Standalone examples were never included in the library source list. No `libtool`,
`-std=c99` flag, or `restrict` qualifiers were introduced.

## 3. Public header

Updated [libft.h](libft.h):

- Added the standard 42 comment header with the existing `anes-sal` author style.
- Changed the inclusion guard from `LIBFT` to `LIBFT_H`.
- Kept `<stddef.h>`, `<stdlib.h>`, and `<unistd.h>`; removed the unused `<stdio.h>`
  include from the library header.
- Moved the existing `t_list` declaration above the function declarations without
  changing its `content` and `next` fields.
- Preserved your corrected `ft_isprint` declaration.
- Added `void ft_putnbr_fd(int n, int fd);`.
- Aligned the public declarations and wrapped `ft_lstmap`'s declaration to satisfy
  the Norm.
- Kept the v19.3 `unsigned int` return type for `ft_lstsize`.
- Checked that all 43 implemented public functions are declared.

## 4. C source changes, file by file

Sixteen C files were modified during the final corrections. Together with
`libft.h`, that is 17 modified C/header files. Existing 42 headers in edited files
had their update timestamps refreshed; missing headers were added where listed.

| File | Changes |
| --- | --- |
| [ft_atoi.c](ft_atoi.c) | Corrected whitespace, changed the index to `size_t`, accumulated negatively to handle `INT_MIN`, and reformatted the function. |
| [ft_bzero.c](ft_bzero.c) | Expanded your one-line wrapper into the required function/bracing layout, preserving `ft_memset(s, 0, n)`. |
| [ft_calloc.c](ft_calloc.c) | Added explicit zero-size allocation handling, retained multiplication-overflow protection and zeroing, and corrected formatting. |
| [ft_isalpha.c](ft_isalpha.c) | Added its missing standard 42 header; retained the existing classification logic. |
| [ft_isdigit.c](ft_isdigit.c) | Added its missing standard 42 header; retained the existing classification logic. |
| [ft_isprint.c](ft_isprint.c) | Added its missing standard 42 header; retained the existing classification logic. |
| [ft_itoa.c](ft_itoa.c) | Reworked digit counting and unsigned magnitude handling, retained zero/sign/terminator handling, and shortened the public function. |
| [ft_lstmap.c](ft_lstmap.c) | Replaced repeated tail searches and the separate first-node case with one loop and a pointer to the next output link. Preserved failure cleanup. |
| [ft_memcpy.c](ft_memcpy.c) | Aligned local declarations. Preserved your existing const-correct source pointer and byte-copy loop. |
| [ft_memmove.c](ft_memmove.c) | Corrected spacing around the address comparison and removed surplus trailing blank lines. Preserved your removal of both globals and the existing copy algorithm. |
| [ft_memset.c](ft_memset.c) | Added its missing standard 42 header; retained the existing byte-filling logic. |
| [ft_split.c](ft_split.c) | Reorganized the implementation into five short functions, used `size_t` counters, checked pointer-array sizing, copied each word independently, and removed repeated full-input length scans. |
| [ft_strdup.c](ft_strdup.c) | Corrected tabs, declaration alignment, keyword spacing, and braces; wrote the terminator as `'\0'`. Retained null-input and allocation-failure handling. |
| [ft_striteri.c](ft_striteri.c) | Removed the commented-out `change` callback and demonstration `main`; retained the iterator's implementation. |
| [ft_strlen.c](ft_strlen.c) | Added its missing standard 42 header; retained the existing length loop. |
| [ft_substr.c](ft_substr.c) | Corrected function layout, indentation, declarations, spacing, braces, and the terminator spelling. Preserved start/length clamping and allocation behavior. |

### ft_atoi details

The original whitespace condition accepted ASCII codes 7 and 8, which are bell
and backspace. It now skips ASCII codes 9 through 13 and the space character.
Regression checks confirm that bell/backspace followed by `42` no longer produce
the value 42.

The original positive `int` accumulator overflowed while building the magnitude
of `-2147483648`. The new loop subtracts digits into a negative accumulator:

```c
result = result * 10 - (nptr[i] - '0');
```

The final sign operation preserves the negative minimum without first trying to
represent its positive magnitude in `int`. The index is now `size_t`. Leading
whitespace, one optional sign, and stopping at the first nondigit remain part of
the conversion behavior. No new public error-reporting interface was added.

### ft_calloc details

When either dimension is zero, the function now requests one byte with
`malloc(1)`. This provides a distinct freeable allocation when allocation
succeeds, independently of how an allocator treats `malloc(0)`.

For nonzero dimensions, the function checks multiplication before computing the
total, returns NULL on overflow or allocation failure, and clears the allocated
bytes through `ft_bzero`.

### ft_itoa details

- `num_len` now takes an `int` and counts digits using division without negating
  the negative minimum.
- The length begins at one so zero receives a digit, with another position
  reserved for a minus sign when needed.
- The public function stores the magnitude in `unsigned int`.
- For negative input, unsigned subtraction computes the magnitude without signed
  negation of `INT_MIN` or reliance on `long` being wider than `int`.
- The result is allocated once, terminated, and filled from right to left.
- Zero is explicitly written as `'0'`, and negative results receive `'-'`.
- Allocation failure still returns NULL before any output-buffer access.

### ft_split details

The old `len_word` helper was replaced by allocation/copy helpers. The current
file has exactly these five functions:

| Function | Responsibility |
| --- | --- |
| `count_words` | Count word starts with `size_t` counters. |
| `free_all` | Free only initialized word allocations, then the outer array. |
| `copy_word` | Measure one word, allocate it, copy its bytes, and terminate it. |
| `fill_words` | Skip delimiters, store words, advance through the input, and append the NULL sentinel. |
| `ft_split` | Validate the source, check array-size arithmetic, allocate the pointer array, and dispatch extraction. |

The array-size guard accounts for both pointer multiplication and the additional
NULL slot. Each word remains an independent allocation. Failure releases the
previous words and outer array. Empty input and delimiter-only input still return
a successful empty pointer array when allocation succeeds. A NUL delimiter still
produces the complete nonempty input as one word.

The former `ft_substr(s, i, len)` call scanned the entire original input for every
word. The new implementation measures/copies individual words and advances using
the new word's length, keeping traversal linear in the input size.

### ft_lstmap details

- Initialized an output head and a `t_list **tail` pointing at the next output
  link to fill.
- Removed the duplicated first-node allocation path and the local `current` and
  `node` variables.
- Used one loop over the source, allocating one output node per callback result.
- Replaced repeated `ft_lstadd_back` calls with direct next-link updates.
- On node allocation failure, deleted the current unlinked content, cleared the
  partial output list, and returned NULL.
- Kept the requirement for non-NULL mapping/deletion callbacks and the existing
  behavior for NULL content returned by a mapping callback.

The structural traversal is now linear; total cost also includes the mapping and
deletion callbacks. Every new helper introduced in these changes is `static`.

### Other reviewed source files

The other 27 C files were reviewed and tested but were not edited during the final
correction pass:

```text
ft_isalnum.c       ft_isascii.c       ft_lstadd_back.c
ft_lstadd_front.c  ft_lstclear.c      ft_lstdelone.c
ft_lstiter.c       ft_lstlast.c       ft_lstnew.c
ft_lstsize.c       ft_memchr.c        ft_memcmp.c
ft_putchar_fd.c   ft_putendl_fd.c    ft_putnbr_fd.c
ft_putstr_fd.c    ft_strchr.c        ft_strjoin.c
ft_strlcat.c      ft_strlcpy.c       ft_strmapi.c
ft_strncmp.c      ft_strnstr.c       ft_strrchr.c
ft_strtrim.c      ft_tolower.c       ft_toupper.c
```

## 5. README creation and corrections

Created [README.md](README.md) with:

- The required italicized first line naming `anes-sal`.
- Description, Instructions, Resources, and detailed library sections.
- Coverage of all 43 public functions, the list structure, callbacks, and memory
  ownership, including freeing every `ft_split` word and then its pointer array.
- Compilation, cleanup, linking, and execution instructions.
- References for strings, bounded copying, allocation, file-descriptor output,
  and GNU Make.
- An AI-use disclosure describing the tasks and project parts assisted.

During the v19.3 corrections, the README was updated to:

- Identify all 43 functions as mandatory: 23 libc-style, 11 additional, and 9 list
  functions.
- Replace bonus build instructions with the complete default build.
- Rename the list section to mandatory Part 3.
- Remove the obsolete `ft_memcpy` const-warning note after your source correction.
- Remove the obsolete header-missing-declaration notes after the header fixes.
- Replace the outdated description of the old `main.c` example with a complete
  standalone example saved outside the submission repository.
- Demonstrate `ft_strjoin`, `ft_putendl_fd`, allocation checking, and `free`, with
  expected output `Hello, Libft!`.
- Add checks/submission guidance and update the AI disclosure to include the
  actual C implementation changes and validation performed.

## 6. Question bank and preserved examples

Created `qcm.md` initially at the repository root after reading all 48 project
files present at that time. It contains:

- 349 unique multiple-choice questions with four choices per question.
- At least five questions for every original project file.
- Extra questions for complex files, including 23 for `ft_split.c`, 12 for
  `ft_itoa.c`, 10 for `ft_lstmap.c`, and 14 for the then-current Makefile.
- Separate sets of at least five questions for the original static helpers
  `count_words`, `len_word`, `free_all`, and `num_len`.
- Questions about bounds, byte representations, signedness, overflow, pointer
  lifetimes, ownership, allocation failures, callbacks, complexity, linked-list
  cycles, linking, headers, documentation, and Make behavior.
- No answer key, keeping the artifact focused on questions.

Minor wording corrections clarified the callback function-pointer types,
plain-character signedness, and a callback freeing the current source node.

When the submission was cleaned up, the bank and demonstrations were preserved
outside the repository rather than discarded. The question bank refers to the
earlier implementation, including its old bugs and bonus organization. A matching
earlier source snapshot is saved with it; the questions were not rewritten to
describe the corrected implementation.

The durable archive is:

```text
/home/anass/Projects/Libft/libft-study-materials/
    README.md                 Explanation of the archived study material
    qcm.md                    The complete 349-question bank
    main.c                    Your saved ft_strlen demonstration
    test.c                    Your saved integer/character-limits program
    source-for-questions/     48 files from the earlier implementation
    before-fixes/             Files saved immediately before final corrections
```

Its [question bank](../libft-study-materials/qcm.md) and
[archive explanation](../libft-study-materials/README.md) are available beside
the repository.

`before-fixes/` also contains `changes-before.patch` and `status-before.txt`, which
record the Git changes already present when the final correction pass began.

## 7. Removed submission entries and Git operations

| Entry | What happened |
| --- | --- |
| `main.c` | Moved out of the repository, preserved in the study archive, and staged for removal from the tracked submission. |
| `test.c` | Moved out of the repository, preserved in the study archive, and staged for removal from the tracked submission. |
| `qcm.md` | Moved out and preserved. It was untracked, so it has no tracked-file deletion in the patch. |
| `a.out` | Already absent from the working directory; its existing deletion was staged. The original binary remains available in Git history. |
| `Makefile` | Added to the Git index. |
| `README.md` | Added to the Git index. |
| Corrected C files/header | Their resulting versions were staged. |

Before this log was added, the resulting index contained exactly 46 submission
files: 43 C sources, `libft.h`, `Makefile`, and `README.md`. Relative to HEAD, the
staged patch has 22 paths: 2 additions, 17 modifications, and 3 deletions.

No commit or push was performed. No branch or remote configuration was changed.
The existing staged changes are preserved while this log is created. This
`changes.md` is an additional local document requested after that staging step.

## 8. Tools, temporary files, and backups

Norminette was not initially installed. After the sandbox blocked package access,
the approved download installed Norminette **3.3.60** into:

```text
/tmp/libft-norminette-v193
```

The install used `pip --target` with caching disabled. It did not install into
global Python packages or modify the shell startup files or PATH. The command
provided for using that copy is:

```sh
PYTHONPATH=/tmp/libft-norminette-v193 python3 -m norminette
```

Append a filename to check one file. This installation is temporary because it is
under `/tmp`; it is separate from the library and its build requirements.

The pre-fix review and final checks used temporary copies and probe programs.
These directories were created during the work:

| Path | Purpose |
| --- | --- |
| `/tmp/libft-v193-audit-td3c1ffm` | Pre-fix source copy, archive/shared-library builds, header probe, allocation probes, and integer-overflow probes. |
| `/tmp/libft-v193-before-fixes-x9ar4i51` | Immediate pre-correction backup and the temporary study-material archive. |
| `/tmp/libft-v193-validation-1gz2wwpv` | Corrected-source copies, build outputs, final allocation/integer probes, and the README example. |
| `/tmp/libft-finalize-v193.py` | Script that verified the validated file hashes, created the durable study archive, and staged the explicit submission paths. |

Earlier Makefile-only checks used automatically cleaned temporary directories.
Temporary pointer files were also written under `/tmp` to locate the backup,
review, validation, and archive directories. The durable study archive contains
the saved study files and pre-fix originals, independently of those pointer files.

The source root and Git metadata were not used for test binaries or a committed
test suite. The library acquired no third-party runtime dependency.

## 9. Verification performed

### Initial checks and confirmed defects

- The first Makefile validation stopped at the then-existing const-discard warning
  in `ft_memcpy`. Build-target checks were also run with `-Werror` omitted at that
  earlier stage; the final checks use all required flags.
- The later pre-fix audit confirmed that default `make` contained only 34 of 43
  required object members and that the old bonus target added the missing nine.
- A header probe confirmed the undeclared `ft_isprint` and `ft_putnbr_fd` issues
  before the subsequent corrections.
- Archive inspection found the old `str` and `str2` globals before your removal.
- A pre-fix run performed 12,235 deterministic checks and found the bell/backspace
  `ft_atoi` mismatches.
- Signed-overflow trap instrumentation reproduced the valid `INT_MIN` parsing
  defect.
- An allocator wrapper demonstrated the zero-size portability problem when
  `malloc(0)` returns NULL.
- Manual Norm findings were followed by a real Norminette run and corrections.

### Final results

| Check | Result |
| --- | --- |
| Norminette 3.3.60 | All 43 C sources and `libft.h` passed: 44 files. |
| Default compilation | Passed with `cc -Wall -Wextra -Werror`. |
| Required archive members | Exactly all 43 required object files were present. |
| Public declarations | A strict client naming every public function compiled; the archive exported all 43 expected function symbols. |
| Global variables | No exported object/data symbols in the final archive. |
| External dependencies | Only `malloc`, `free`, and `write`, apart from references to the project's own functions. |
| Repeated `make` | Object timestamps and archive timestamp stayed unchanged. |
| Header dependency | A forced header-change dry run scheduled all 43 objects for compilation. |
| `clean` | Removed objects while preserving the archive. |
| `fclean` | Removed objects and archive. |
| Parallel `re` | Cleanup and rebuild completed successfully. |
| Optimized behavior tests | 18,848 deterministic checks passed across all 43 public functions and the README example. |
| README example | Strictly compiled, linked, and printed `Hello, Libft!` followed by a newline. |
| Allocation failures | Tested split allocation failures, list-map node failures, and first-allocation failures in other allocating functions; no tracked leaks remained. |
| Zero-size allocation | Passed with a wrapped allocator that returns NULL specifically for `malloc(0)`. |
| Integer boundaries | `ft_atoi` and `ft_itoa` passed signed-overflow trap instrumentation for `INT_MIN`, `INT_MAX`, neighboring values, zero, and representative signed inputs. |
| Whitespace regressions | Bell/backspace rejection and permitted ASCII-whitespace conversion passed. |
| Documentation | Required README sections, first line, function coverage, and example were checked. |
| Diff checks | Staged changes passed `git diff --cached --check`. |
| Final consistency | Working source files matched the validated copies, and there were no unstaged edits before this log was created. |

Behavior checks included character boundaries, arbitrary byte values, overlapping
memory moves, embedded NUL bytes, truncation, empty strings, substring bounds,
delimiter handling, callback behavior, list operations, content ownership, and
file-descriptor output.

Failure probes checked all four allocation positions for a three-word split and
each output-node allocation position for a three-node map, as well as successful
cleanup. They also verified that overflowing `calloc` dimensions are rejected
before calling the allocator.

The system's usual UBSan runtime could not link because its shared library was
missing. Signed-overflow instrumentation therefore used
`-fsanitize=signed-integer-overflow -fsanitize-undefined-trap-on-error`, which
passed after correction. No system sanitizer runtime was installed. These checks
were targeted regression tests and allocator tracking; they are not an official
42 evaluation result or a full Valgrind/AddressSanitizer run.

## 10. Exact staged patch

The following is the complete textual staged diff captured when this log was
created, against HEAD `13d3b9e9658fcb8cd4c8f485884b25c083630f33`. Unchanged context
lines are omitted; every addition and deletion is retained. It was captured with:

```sh
git diff --cached --no-ext-diff --no-color --full-index --unified=0
```

It includes your pre-existing edits identified in section 1. Binary removal is
recorded as a binary deletion without embedding the old executable's contents.
Archived `qcm.md` is described above because it was untracked and is outside this
Git diff. This newly requested `changes.md` is also outside the captured patch.

````diff
diff --git a/Makefile b/Makefile
new file mode 100644
index 0000000000000000000000000000000000000000..87590377eb34df97da812c63491188a8b2fae061
--- /dev/null
+++ b/Makefile
@@ -0,0 +1,75 @@
+NAME = libft.a
+
+CC = cc
+CFLAGS = -Wall -Wextra -Werror
+AR = ar
+ARFLAGS = rcs
+RM = rm -f
+
+HEADERS = libft.h
+
+SRCS = ft_isalpha.c \
+	ft_isdigit.c \
+	ft_isalnum.c \
+	ft_isascii.c \
+	ft_isprint.c \
+	ft_strlen.c \
+	ft_memset.c \
+	ft_bzero.c \
+	ft_memcpy.c \
+	ft_memmove.c \
+	ft_strlcpy.c \
+	ft_strlcat.c \
+	ft_toupper.c \
+	ft_tolower.c \
+	ft_strchr.c \
+	ft_strrchr.c \
+	ft_strncmp.c \
+	ft_memchr.c \
+	ft_memcmp.c \
+	ft_strnstr.c \
+	ft_atoi.c \
+	ft_calloc.c \
+	ft_strdup.c \
+	ft_substr.c \
+	ft_strjoin.c \
+	ft_strtrim.c \
+	ft_split.c \
+	ft_itoa.c \
+	ft_strmapi.c \
+	ft_striteri.c \
+	ft_putchar_fd.c \
+	ft_putstr_fd.c \
+	ft_putendl_fd.c \
+	ft_putnbr_fd.c \
+	ft_lstnew.c \
+	ft_lstadd_front.c \
+	ft_lstsize.c \
+	ft_lstlast.c \
+	ft_lstadd_back.c \
+	ft_lstdelone.c \
+	ft_lstclear.c \
+	ft_lstiter.c \
+	ft_lstmap.c
+
+OBJS = $(SRCS:.c=.o)
+
+all: $(NAME)
+
+$(NAME): $(OBJS)
+	$(AR) $(ARFLAGS) $@ $(OBJS)
+
+%.o: %.c $(HEADERS) Makefile
+	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
+
+clean:
+	$(RM) $(OBJS)
+
+fclean: clean
+	$(RM) $(NAME)
+
+re:
+	$(MAKE) fclean
+	$(MAKE) all
+
+.PHONY: all clean fclean re
diff --git a/README.md b/README.md
new file mode 100644
index 0000000000000000000000000000000000000000..fa996e0db3263f944a7d70b02f444cd23625687d
--- /dev/null
+++ b/README.md
@@ -0,0 +1,248 @@
+*This project has been created as part of the 42 curriculum by anes-sal.*
+
+# Libft
+
+## Description
+
+Libft is a reusable C library built as part of the 42 curriculum. Its goal is to
+practice implementing common library routines, working with pointers, managing
+dynamic memory, and building a static library with Make.
+
+The project contains 34 core functions for character checks, memory operations,
+string manipulation, conversions, and output to file descriptors. It also includes
+9 functions for singly linked lists. All 43 functions are mandatory in the
+Libft v19.3 subject. All library function names begin with `ft_`.
+
+The build produces `libft.a`, which other C programs can link against. The public
+header is [libft.h](libft.h). Each function has its own `.c` source file in the
+repository root.
+
+## Instructions
+
+### Requirements
+
+- A Unix-like environment with the standard C library and `<unistd.h>`.
+- A C compiler available as `cc`, such as GCC or Clang.
+- `make` and the `ar` archive utility.
+
+No external libraries or package installation are required beyond these tools.
+Run the following commands from the repository root.
+
+### Compilation
+
+```sh
+make
+```
+
+This builds all 43 mandatory functions into `libft.a`: 23 libc-style functions,
+11 additional functions, and 9 linked-list functions. The compiler is `cc`, with
+`-Wall -Wextra -Werror`. The archive is created with `ar` in the repository root.
+There is no separate bonus target in this version of the project.
+
+The Makefile tracks source and header dependencies and avoids unnecessary
+recompilation or archive updates when the build is already up to date.
+
+| Command | Effect |
+| --- | --- |
+| `make` or `make all` | Build the complete mandatory library. |
+| `make libft.a` | Build the library archive directly. |
+| `make clean` | Remove all object files. |
+| `make fclean` | Remove object files and `libft.a`. |
+| `make re` | Clean and rebuild the complete library. |
+
+### Linking and execution
+
+Libft is a library and has no standalone executable. Include `libft.h` in a
+calling program and link that program with `libft.a`. No system-wide installation
+is needed.
+
+For example, save this program outside the submission repository as
+`/tmp/libft_example.c`:
+
+```c
+#include "libft.h"
+#include <stdlib.h>
+
+int main(void)
+{
+    char *message;
+
+    message = ft_strjoin("Hello, ", "Libft!");
+    if (!message)
+        return (1);
+    ft_putendl_fd(message, 1);
+    free(message);
+    return (0);
+}
+```
+
+From the library repository root, compile and run it with:
+
+```sh
+make
+cc -Wall -Wextra -Werror -I. /tmp/libft_example.c libft.a -o /tmp/libft_example
+/tmp/libft_example
+```
+
+Expected output:
+
+```text
+Hello, Libft!
+```
+
+To use the library from another project, provide the header directory and archive
+path when compiling:
+
+```sh
+cc -Wall -Wextra -Werror -I/path/to/libft app.c /path/to/libft/libft.a -o app
+```
+
+### Checks and submission
+
+Run `norminette` from the repository root to check the C sources and header when
+the tool is installed. Check function behavior and allocation failures with
+separate test programs kept outside the submitted repository.
+
+Submit the 43 `ft_*.c` files, `libft.h`, `Makefile`, and `README.md`. Keep compiled
+artifacts, standalone demonstration programs, and study notes out of the submitted
+files. Only committed and pushed files reach the assigned evaluation repository.
+
+## Library details
+
+### Character operations
+
+These functions operate on ASCII character values.
+
+| Functions | Purpose |
+| --- | --- |
+| `ft_isalpha` | Check whether a value is an alphabetic character. |
+| `ft_isdigit` | Check whether a value is a decimal digit. |
+| `ft_isalnum` | Check whether a value is alphabetic or a decimal digit. |
+| `ft_isascii` | Check whether a value belongs to the ASCII range. |
+| `ft_isprint` | Check whether a value is a printable ASCII character. |
+| `ft_toupper`, `ft_tolower` | Convert ASCII letter case; leave other values unchanged. |
+
+### Memory operations
+
+| Function | Purpose |
+| --- | --- |
+| `ft_memset` | Fill a specified number of bytes with a byte value. |
+| `ft_bzero` | Set a specified number of bytes to zero. |
+| `ft_memcpy` | Copy bytes between memory regions that do not overlap. |
+| `ft_memmove` | Copy bytes while supporting overlapping regions. |
+| `ft_memchr` | Find the first matching byte within a memory region. |
+| `ft_memcmp` | Compare two memory regions byte by byte. |
+| `ft_calloc` | Allocate zeroed memory for an array, checking for size multiplication overflow. |
+
+### Strings and conversions
+
+Strings use the C convention of a terminating NUL byte (`'\0'`).
+
+| Function | Purpose |
+| --- | --- |
+| `ft_strlen` | Count characters before the terminating NUL byte. |
+| `ft_strlcpy` | Copy a string into a bounded destination; return the source length. |
+| `ft_strlcat` | Append within a destination size limit; return the total length attempted. |
+| `ft_strchr`, `ft_strrchr` | Find the first or last occurrence of a character. |
+| `ft_strncmp` | Compare up to a specified number of characters. |
+| `ft_strnstr` | Find a substring within a limited portion of a string. |
+| `ft_strdup` | Allocate a copy of a string. |
+| `ft_atoi` | Convert an initial numeric portion of a string to an `int`. |
+| `ft_substr` | Allocate a substring using a starting index and maximum length. |
+| `ft_strjoin` | Allocate a string containing two strings joined together. |
+| `ft_strtrim` | Allocate a copy with characters from a given set removed from both ends. |
+| `ft_split` | Split a string on one delimiter character into an allocated, NULL-terminated array of strings. |
+| `ft_itoa` | Allocate a decimal string representation of an `int`. |
+| `ft_strmapi` | Allocate a new string by applying a callback to each character and its index. |
+| `ft_striteri` | Apply a callback to each character and its index, allowing changes in place. |
+
+### Output to file descriptors
+
+These functions write to the supplied file descriptor, such as `1` for standard
+output or `2` for standard error.
+
+| Function | Purpose |
+| --- | --- |
+| `ft_putchar_fd` | Write one character. |
+| `ft_putstr_fd` | Write a string. |
+| `ft_putendl_fd` | Write a string followed by a newline. |
+| `ft_putnbr_fd` | Write an integer in decimal form. |
+
+### Part 3: mandatory singly linked lists
+
+The list type stores a generic content pointer and a pointer to the next node:
+
+```c
+typedef struct s_list
+{
+    void            *content;
+    struct s_list   *next;
+}   t_list;
+```
+
+| Function | Purpose |
+| --- | --- |
+| `ft_lstnew` | Allocate a node containing the supplied content pointer. |
+| `ft_lstadd_front` | Insert a node at the beginning of a list. |
+| `ft_lstsize` | Count the nodes; this implementation returns `unsigned int`. |
+| `ft_lstlast` | Return the last node. |
+| `ft_lstadd_back` | Append a node to the end of a list. |
+| `ft_lstdelone` | Apply a deletion callback to a node's content, then free the node. |
+| `ft_lstclear` | Delete every node and set the caller's list pointer to `NULL`. |
+| `ft_lstiter` | Apply a callback to each node's content. |
+| `ft_lstmap` | Build a new list from callback results, using a deletion callback to clean up if node allocation fails. |
+
+### Memory ownership and callbacks
+
+Check allocating functions for a `NULL` return before using their results. Memory
+returned by `ft_calloc`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`,
+`ft_itoa`, and `ft_strmapi` belongs to the caller and must be released with `free`.
+For `ft_split`, free every returned string and then free the pointer array.
+
+`ft_lstnew` stores the supplied content pointer without copying the pointed-to
+data. Choose a deletion callback that matches how that content was allocated.
+For example, `free` is suitable for separately allocated heap content. The callback
+passed to `ft_lstmap` must return content whose ownership is compatible with the
+provided deletion callback. In this implementation, mapping requires both
+callbacks to be non-NULL.
+
+Callers must provide valid buffers, appropriate sizes, and valid callback
+arguments. Individual functions differ in their handling of NULL inputs; consult
+the source for their exact behavior.
+
+## Resources
+
+- [Linux manual: string operations](https://man7.org/linux/man-pages/man3/string.3.html)
+  provides references for string length, searching, comparison, and duplication.
+- [OpenBSD manual: strlcpy and strlcat](https://man.openbsd.org/strlcpy.3)
+  explains destination sizes, return values, and truncation detection.
+- [Linux manual: malloc, calloc, and free](https://man7.org/linux/man-pages/man3/malloc.3.html)
+  covers allocation, allocation failures, and releasing memory.
+- [Linux manual: write](https://www.man7.org/linux/man-pages/man2/write.2.html)
+  describes output through file descriptors.
+- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
+  explains targets, prerequisites, recipes, and incremental compilation.
+
+For the exact campus submission and evaluation requirements, consult the Libft
+subject provided through the 42 intranet.
+
+### AI use
+
+OpenAI Codex assisted with these project tasks:
+
+- Reviewing the source files against the supplied Libft v19.3 subject and checking
+  function declarations, permitted external functions, and submission contents.
+- Creating and correcting the `Makefile` so the default build includes all 43
+  mandatory functions and supports dependency tracking and cleanup.
+- Correcting `ft_atoi` whitespace handling and signed-minimum conversion,
+  `ft_calloc` zero-size allocation, and `ft_itoa` magnitude handling.
+- Refactoring `ft_split` and `ft_lstmap` into short functions with linear traversal
+  and allocation-failure cleanup, and correcting source/header formatting and
+  public declarations for Norm compliance.
+- Writing and updating this README, selecting references, and creating study
+  questions kept outside the submission repository.
+- Running Norminette, compilation and build checks, behavioral checks, overflow
+  instrumentation, and allocation-failure probes using temporary test files.
+
+AI-assisted implementation changes should be studied and independently reviewed
+so the author can explain the algorithms, ownership rules, and failure paths.
diff --git a/a.out b/a.out
deleted file mode 100755
index 464af5015503ec6607f2eb79442bc962833e44bb..0000000000000000000000000000000000000000
Binary files a/a.out and /dev/null differ
diff --git a/ft_atoi.c b/ft_atoi.c
index dfe81f030865fd54fdfc0fc7d939cbe528333056..698fb37a9d7a8931774f04995bd18fbf083d0f85 100644
--- a/ft_atoi.c
+++ b/ft_atoi.c
@@ -9 +9 @@
-/*   Updated: 2026/10/21 10:28:43 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -15,4 +15,5 @@
-int ft_atoi(const char *nptr){
-    int sign;
-    int i;
-    int result;
+int	ft_atoi(const char *nptr)
+{
+	size_t	i;
+	int		sign;
+	int		result;
@@ -20,17 +21,17 @@ int ft_atoi(const char *nptr){
-    result = 0;
-    i = 0;
-    sign = 1;
-    while((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == 32){
-        i++;
-    }
-    if(nptr[i] == '-' || nptr[i] == '+'){
-        if(nptr[i] == '-'){
-            sign *= -1;
-        }
-        i++;
-    }
-    while(nptr[i] >= '0' && nptr[i] <= '9'){
-        result = result * 10  + (nptr[i] - '0');
-        i++;
-    }
-    return (result * sign);
+	i = 0;
+	sign = 1;
+	result = 0;
+	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
+		i++;
+	if (nptr[i] == '-' || nptr[i] == '+')
+	{
+		if (nptr[i] == '-')
+			sign = -1;
+		i++;
+	}
+	while (nptr[i] >= '0' && nptr[i] <= '9')
+	{
+		result = result * 10 - (nptr[i] - '0');
+		i++;
+	}
+	return (result * -sign);
diff --git a/ft_bzero.c b/ft_bzero.c
index cccd1a4d8b419cc883b002eb0b11c8dc6eaedc99..f9389dfc44767eb539b48ec539da9ad26a5a6b85 100644
--- a/ft_bzero.c
+++ b/ft_bzero.c
@@ -9 +9 @@
-/*   Updated: 2026/10/20 09:23:53 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -11,0 +12,3 @@
+
+#include "libft.h"
+
diff --git a/ft_calloc.c b/ft_calloc.c
index 8d3e241c1caf1d4ef2e187388e84937d76c66145..f7e1842f5d04469557b3b0af9fcbbb545fa06732 100644
--- a/ft_calloc.c
+++ b/ft_calloc.c
@@ -9 +9 @@
-/*   Updated: 2026/10/21 11:13:14 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -15,3 +15,4 @@
-void *ft_calloc(size_t nmemb , size_t size){
-    void *p ;
-    size_t total;
+void	*ft_calloc(size_t nmemb, size_t size)
+{
+	void	*p;
+	size_t	total;
@@ -19,8 +20,10 @@ void *ft_calloc(size_t nmemb , size_t size){
-    if(size != 0 && nmemb > ((size_t) - 1) / size)
-        return (NULL);
-    total = nmemb * size;
-    p = malloc(total);
-    if(!p)
-        return (NULL);
-    ft_bzero(p , total);
-    return(p);
+	if (nmemb == 0 || size == 0)
+		return (malloc(1));
+	if (nmemb > (size_t)-1 / size)
+		return (NULL);
+	total = nmemb * size;
+	p = malloc(total);
+	if (!p)
+		return (NULL);
+	ft_bzero(p, total);
+	return (p);
diff --git a/ft_isalpha.c b/ft_isalpha.c
index 3fd7c08cb69c2bc4b4fd03d8332c002e1b947d26..fab7cf433523468f772316a647605d3e580b6339 100644
--- a/ft_isalpha.c
+++ b/ft_isalpha.c
@@ -0,0 +1,12 @@
+/* ************************************************************************** */
+/*                                                                            */
+/*                                                        :::      ::::::::   */
+/*   ft_isalpha.c                                       :+:      :+:    :+:   */
+/*                                                    +:+ +:+         +:+     */
+/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
+/*                                                +#+#+#+#+#+   +#+           */
+/*   Created: 2026/10/25 00:13:15 by anes-sal          #+#    #+#             */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
+/*                                                                            */
+/* ************************************************************************** */
+
diff --git a/ft_isdigit.c b/ft_isdigit.c
index ec2622a7a5e1730b176ea800c7f1b5bc56b3803d..76d99d098729b6c512def7eedc2a559f12b2df19 100644
--- a/ft_isdigit.c
+++ b/ft_isdigit.c
@@ -0,0 +1,12 @@
+/* ************************************************************************** */
+/*                                                                            */
+/*                                                        :::      ::::::::   */
+/*   ft_isdigit.c                                       :+:      :+:    :+:   */
+/*                                                    +:+ +:+         +:+     */
+/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
+/*                                                +#+#+#+#+#+   +#+           */
+/*   Created: 2026/10/25 00:13:15 by anes-sal          #+#    #+#             */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
+/*                                                                            */
+/* ************************************************************************** */
+
diff --git a/ft_isprint.c b/ft_isprint.c
index f2da8cb50719e3b4df0403fb2d549323ca6792ff..913055a71ef5bfb198e2d75458730f9f28606e11 100644
--- a/ft_isprint.c
+++ b/ft_isprint.c
@@ -0,0 +1,12 @@
+/* ************************************************************************** */
+/*                                                                            */
+/*                                                        :::      ::::::::   */
+/*   ft_isprint.c                                       :+:      :+:    :+:   */
+/*                                                    +:+ +:+         +:+     */
+/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
+/*                                                +#+#+#+#+#+   +#+           */
+/*   Created: 2026/10/25 00:13:15 by anes-sal          #+#    #+#             */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
+/*                                                                            */
+/* ************************************************************************** */
+
diff --git a/ft_itoa.c b/ft_itoa.c
index 7e3733bae8b5fd30eb50447e2546bd404dd6ea44..762d0b82f383e099a5a3794c58a3ea50e6a0aeed 100644
--- a/ft_itoa.c
+++ b/ft_itoa.c
@@ -9 +9 @@
-/*   Updated: 2026/10/22 12:07:59 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -15 +15 @@
-static int	num_len(long n)
+static int	num_len(int n)
@@ -17 +17 @@ static int	num_len(long n)
-	int	i;
+	int	len;
@@ -19,3 +19 @@ static int	num_len(long n)
-	i = 0;
-	if (n == 0)
-		i++;
+	len = 1;
@@ -22,0 +21,2 @@ static int	num_len(long n)
+		len++;
+	while (n / 10 != 0)
@@ -24,7 +24,2 @@ static int	num_len(long n)
-		n = -n;
-		i++;
-	}
-	while (n > 0)
-	{
-		n = n / 10;
-		i++;
+		n /= 10;
+		len++;
@@ -32 +27 @@ static int	num_len(long n)
-	return (i);
+	return (len);
@@ -33,0 +29 @@ static int	num_len(long n)
+
@@ -36,4 +32,3 @@ char	*ft_itoa(int n)
-	char	*num;
-	int		i;
-	int		len;
-	long	ln;
+	char			*num;
+	int				len;
+	unsigned int	magnitude;
@@ -41,2 +36 @@ char	*ft_itoa(int n)
-	ln = (long)n;
-	len = num_len(ln);
+	len = num_len(n);
@@ -46,2 +40,5 @@ char	*ft_itoa(int n)
-	i = len - 1;
-	if (ln == 0)
+	num[len] = '\0';
+	magnitude = (unsigned int)n;
+	if (n < 0)
+		magnitude = 0u - magnitude;
+	if (n == 0)
@@ -49 +46 @@ char	*ft_itoa(int n)
-	if (ln < 0)
+	while (magnitude != 0)
@@ -51,8 +48,2 @@ char	*ft_itoa(int n)
-		num[0] = '-';
-		ln = -ln;
-	}
-	while (ln > 0)
-	{
-		num[i] = (ln % 10) + '0';
-		ln = ln / 10;
-		i--;
+		num[--len] = magnitude % 10 + '0';
+		magnitude /= 10;
@@ -60 +51,2 @@ char	*ft_itoa(int n)
-	num[len] = 0;
+	if (n < 0)
+		num[0] = '-';
diff --git a/ft_lstmap.c b/ft_lstmap.c
index 449cc53fc1ede5d61f233686d6c92abf15d55e1c..13ef5322cf0b4cfbc1e34dbc9f7bc65c3718bb63 100644
--- a/ft_lstmap.c
+++ b/ft_lstmap.c
@@ -9 +9 @@
-/*   Updated: 2026/10/24 18:02:56 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -18,2 +18 @@ t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
-	t_list	*current;
-	t_list	*node;
+	t_list	**tail;
@@ -22 +21 @@ t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
-	if (!lst || !f || !del)
+	if (!f || !del)
@@ -25,4 +24,2 @@ t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
-	current = lst;
-	content = f(current->content);
-	head = ft_lstnew(content);
-	if (!head)
+	tail = &head;
+	while (lst)
@@ -30,9 +27,3 @@ t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
-		del(content);
-		return (NULL);
-	}
-	current = current->next;
-	while (current)
-	{
-		content = f(current->content);
-		node = ft_lstnew(content);
-		if (!node)
+		content = f(lst->content);
+		*tail = ft_lstnew(content);
+		if (!*tail)
@@ -44,2 +35,2 @@ t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
-		ft_lstadd_back(&head, node);
-		current = current->next;
+		tail = &(*tail)->next;
+		lst = lst->next;
diff --git a/ft_memcpy.c b/ft_memcpy.c
index d54034722e800f9d67ea999ad5e2afeb4711c481..04a96bc21a0e32cf42b1be2b32eb2a4ca72aa455 100644
--- a/ft_memcpy.c
+++ b/ft_memcpy.c
@@ -9 +9 @@
-/*   Updated: 2026/10/20 09:41:38 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -17,3 +17,3 @@ void	*ft_memcpy(void *dest, const void *src, size_t n)
-	unsigned char	*p;
-	unsigned char	*s;
-	size_t			i;
+	unsigned char		*p;
+	const unsigned char	*s;
+	size_t				i;
diff --git a/ft_memmove.c b/ft_memmove.c
index 6d42b0cade524d32efc874ba47f5dafab7831956..51ea90ed5cc975122b6f1a1bcd92776d6291db6d 100644
--- a/ft_memmove.c
+++ b/ft_memmove.c
@@ -9 +9 @@
-/*   Updated: 2026/10/24 18:34:19 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -23 +23 @@ void	*ft_memmove(void *dest, const void *src, size_t n)
-	if ((size_t)p >(size_t)s)
+	if ((size_t)p > (size_t)s)
@@ -43,2 +42,0 @@ void	*ft_memmove(void *dest, const void *src, size_t n)
-char str[] = "abcd";
-char str2[] = "efg";
diff --git a/ft_memset.c b/ft_memset.c
index 89e426a3b1631077f1c3b4439b6061a33e028131..8202696f445998792fceb1e7ba225cda7087443f 100644
--- a/ft_memset.c
+++ b/ft_memset.c
@@ -0,0 +1,12 @@
+/* ************************************************************************** */
+/*                                                                            */
+/*                                                        :::      ::::::::   */
+/*   ft_memset.c                                        :+:      :+:    :+:   */
+/*                                                    +:+ +:+         +:+     */
+/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
+/*                                                +#+#+#+#+#+   +#+           */
+/*   Created: 2026/10/25 00:13:15 by anes-sal          #+#    #+#             */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
+/*                                                                            */
+/* ************************************************************************** */
+
diff --git a/ft_split.c b/ft_split.c
index 521b0e9c0c17bf821b6b1c6d044d1a2e0e8c37a9..9fd76e18550cf1a9d300b7a1bf9393cd970ac15c 100644
--- a/ft_split.c
+++ b/ft_split.c
@@ -9 +9 @@
-/*   Updated: 2026/10/22 11:45:37 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -15 +15 @@
-static int	count_words(char const *s, char c)
+static size_t	count_words(char const *s, char c)
@@ -17,2 +17,2 @@ static int	count_words(char const *s, char c)
-	int	i;
-	int	count;
+	size_t	i;
+	size_t	count;
@@ -30 +30,2 @@ static int	count_words(char const *s, char c)
-static int	len_word(char const *s, char c)
+
+static char	**free_all(char **words, size_t count)
@@ -32 +33 @@ static int	len_word(char const *s, char c)
-	int	i;
+	size_t	i;
@@ -35 +36 @@ static int	len_word(char const *s, char c)
-	while (*(s + i) && *(s + i) != c)
+	while (i < count)
@@ -36,0 +38 @@ static int	len_word(char const *s, char c)
+		free(words[i]);
@@ -39 +41,18 @@ static int	len_word(char const *s, char c)
-	return (i);
+	free(words);
+	return (NULL);
+}
+
+static char	*copy_word(char const *s, char c)
+{
+	size_t	len;
+	char	*word;
+
+	len = 0;
+	while (s[len] && s[len] != c)
+		len++;
+	word = malloc(len + 1);
+	if (!word)
+		return (NULL);
+	ft_memcpy(word, s, len);
+	word[len] = '\0';
+	return (word);
@@ -41 +60,2 @@ static int	len_word(char const *s, char c)
-static char	**free_all(char **str, int j)
+
+static char	**fill_words(char **words, char const *s, char c)
@@ -43 +63 @@ static char	**free_all(char **str, int j)
-	int	i;
+	size_t	i;
@@ -46 +66 @@ static char	**free_all(char **str, int j)
-	while (i < j)
+	while (*s)
@@ -48,2 +68,10 @@ static char	**free_all(char **str, int j)
-		free(str[i]);
-		i++;
+		if (*s == c)
+			s++;
+		else
+		{
+			words[i] = copy_word(s, c);
+			if (!words[i])
+				return (free_all(words, i));
+			s += ft_strlen(words[i]);
+			i++;
+		}
@@ -51,2 +79,2 @@ static char	**free_all(char **str, int j)
-	free(str);
-	return (NULL);
+	words[i] = NULL;
+	return (words);
@@ -53,0 +82 @@ static char	**free_all(char **str, int j)
+
@@ -56,5 +85,2 @@ char	**ft_split(char const *s, char c)
-	char	**str;
-	int		words;
-	int		len;
-	int		i;
-	int		j;
+	size_t	count;
+	char	**words;
@@ -64,3 +90,2 @@ char	**ft_split(char const *s, char c)
-	words = count_words(s, c);
-	str = malloc(sizeof(char *) * (words + 1));
-	if (!str)
+	count = count_words(s, c);
+	if (count >= (size_t)-1 / sizeof(*words))
@@ -68,18 +93,4 @@ char	**ft_split(char const *s, char c)
-	i = 0;
-	j = 0;
-	while (s[i] && j < words)
-	{
-		if (s[i] == c)
-			i++;
-		else
-		{
-			len = len_word(s + i, c);
-			str[j] = ft_substr(s, i, len);
-			if (!str[j])
-				return (free_all(str, j));
-			i += len;
-			j++;
-		}
-	}
-	str[j] = NULL;
-	return (str);
+	words = malloc(sizeof(*words) * (count + 1));
+	if (!words)
+		return (NULL);
+	return (fill_words(words, s, c));
diff --git a/ft_strdup.c b/ft_strdup.c
index 415f3366d7e46492db0353cacdab29d5d46834df..775c7ae8e78954546c1f5fd30a5195cf90d40963 100644
--- a/ft_strdup.c
+++ b/ft_strdup.c
@@ -9 +9 @@
-/*   Updated: 2026/10/21 20:44:13 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -15,4 +15,5 @@
-char *ft_strdup(const char *s){
-    size_t len;
-    char *p;
-    size_t i;
+char	*ft_strdup(const char *s)
+{
+	size_t	len;
+	char	*p;
+	size_t	i;
@@ -20,13 +21,14 @@ char *ft_strdup(const char *s){
-    if(!s)
-        return (NULL);
-    len = ft_strlen(s);
-    p = malloc(len + 1);
-    if(!p)
-        return (NULL);
-    i = 0;
-    while(s[i]){
-        p[i] = s[i];
-        i++;
-    }
-    p[i] = 0;
-    return (p);
+	if (!s)
+		return (NULL);
+	len = ft_strlen(s);
+	p = malloc(len + 1);
+	if (!p)
+		return (NULL);
+	i = 0;
+	while (s[i])
+	{
+		p[i] = s[i];
+		i++;
+	}
+	p[i] = '\0';
+	return (p);
diff --git a/ft_striteri.c b/ft_striteri.c
index 591ee9c320109f708a569131a7db72b9dde86793..fb3763bf5597c45ab64ae56523408760b8b2a8c4 100644
--- a/ft_striteri.c
+++ b/ft_striteri.c
@@ -9 +9 @@
-/*   Updated: 2026/10/22 12:48:18 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -28,10 +27,0 @@ void	ft_striteri(char *s, void (*f)(unsigned int, char *))
-/* void	change(unsigned int i, char *c) */
-/* { */
-/* 	if (i % 2 == 0) */
-/* 		*c = 'X'; */
-/* } */
-/* int main(){ */
-/*     char s[] = "hello"; */
-/*     ft_striteri(s , change); */
-/*     printf("%s" , s); */
-/* } */
diff --git a/ft_strlen.c b/ft_strlen.c
index 19ae01b808bd8974ee7d223d10913b2a486c710d..a431ab83a80f8894146d962af136da7ab68ec54f 100644
--- a/ft_strlen.c
+++ b/ft_strlen.c
@@ -0,0 +1,12 @@
+/* ************************************************************************** */
+/*                                                                            */
+/*                                                        :::      ::::::::   */
+/*   ft_strlen.c                                        :+:      :+:    :+:   */
+/*                                                    +:+ +:+         +:+     */
+/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
+/*                                                +#+#+#+#+#+   +#+           */
+/*   Created: 2026/10/25 00:13:15 by anes-sal          #+#    #+#             */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
+/*                                                                            */
+/* ************************************************************************** */
+
diff --git a/ft_substr.c b/ft_substr.c
index 6e20d7933940cf985bdbd8e3ac9d6b215a58de8f..770c8be8910c8e75c358c0b4dda27d7d80bc3cb8 100644
--- a/ft_substr.c
+++ b/ft_substr.c
@@ -9 +9 @@
-/*   Updated: 2026/10/21 12:12:59 by anes-sal         ###   ########.fr       */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
@@ -15,22 +15,5 @@
-char *ft_substr(char const *s , unsigned int start , size_t len){
-    size_t i;
-    char *str;
-    size_t slen;
-
-    if(!s)
-        return (NULL);
-    slen = ft_strlen(s);
-    if(start >= slen)
-        len = 0;
-    else if(slen - start < len)
-        len = slen - start;
-    str = malloc(len + 1);
-    if(!str)
-        return (NULL);
-    i = 0;
-    while(i < len){
-        str[i] = s[start + i];
-        i++;
-    }
-    str[i] = 0 ;
-    return (str);
+char	*ft_substr(char const *s, unsigned int start, size_t len)
+{
+	size_t	i;
+	char	*str;
+	size_t	slen;
@@ -37,0 +21,18 @@ char *ft_substr(char const *s , unsigned int start , size_t len){
+	if (!s)
+		return (NULL);
+	slen = ft_strlen(s);
+	if (start >= slen)
+		len = 0;
+	else if (slen - start < len)
+		len = slen - start;
+	str = malloc(len + 1);
+	if (!str)
+		return (NULL);
+	i = 0;
+	while (i < len)
+	{
+		str[i] = s[start + i];
+		i++;
+	}
+	str[i] = '\0';
+	return (str);
diff --git a/libft.h b/libft.h
index abc2d7b59dc52757cf19e5c010e26458d14347a0..f3292a8c12872f15d7d12ed62b351b09d5209bc7 100644
--- a/libft.h
+++ b/libft.h
@@ -1,2 +1,15 @@
-#ifndef LIBFT
-# define LIBFT
+/* ************************************************************************** */
+/*                                                                            */
+/*                                                        :::      ::::::::   */
+/*   libft.h                                            :+:      :+:    :+:   */
+/*                                                    +:+ +:+         +:+     */
+/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
+/*                                                +#+#+#+#+#+   +#+           */
+/*   Created: 2026/10/25 00:13:15 by anes-sal          #+#    #+#             */
+/*   Updated: 2026/10/25 00:13:15 by anes-sal         ###   ########.fr       */
+/*                                                                            */
+/* ************************************************************************** */
+
+#ifndef LIBFT_H
+# define LIBFT_H
+
@@ -4 +16,0 @@
-# include <stdio.h>
@@ -8,36 +19,0 @@
-int					ft_isalpha(int c);
-int					ft_isdigit(int c);
-int					ft_isalnum(int c);
-int					ft_isascii(int c);
-int					ft_print(int c);
-size_t				ft_strlen(const char *s);
-void				*ft_memset(void *s, int c, size_t n);
-void				ft_bzero(void *s, size_t n);
-void				*ft_memcpy(void *dest, const void *src, size_t n);
-void				*ft_memmove(void *dest, const void *src, size_t n);
-size_t				ft_strlcpy(char *dst, const char *src, size_t size);
-size_t				ft_strlcat(char *dst, const char *src, size_t size);
-int					ft_tolower(int c);
-int					ft_toupper(int c);
-char				*ft_strchr(const char *s, int c);
-char				*ft_strrchr(const char *s, int c);
-int					ft_strncmp(const char *s1, const char *s2, size_t n);
-void				*ft_memchr(const void *s, int c, size_t n);
-int					ft_memcmp(const void *s1, const void *s2, size_t n);
-char				*ft_strnstr(const char *big, const char *little,
-						size_t len);
-int					ft_atoi(const char *nptr);
-void				*ft_calloc(size_t nmemb, size_t size);
-char				*ft_strdup(const char *s);
-
-char				*ft_substr(char const *s, unsigned int start, size_t len);
-char				*ft_strjoin(char const *s1, char const *s2);
-char				*ft_strtrim(char const *s1, char const *set);
-char				**ft_split(char const *s, char c);
-char				*ft_itoa(int n);
-char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
-void				ft_striteri(char *s, void (*f)(unsigned int, char *));
-void				ft_putchar_fd(char c, int fd);
-void				ft_putstr_fd(char *s, int fd);
-void				ft_putendl_fd(char *s, int fd);
-
@@ -49,2 +25,37 @@ typedef struct s_list
-t_list	*ft_lstnew(void *content);
-void	ft_lstadd_front(t_list **lst, t_list *new);
+
+int				ft_isalpha(int c);
+int				ft_isdigit(int c);
+int				ft_isalnum(int c);
+int				ft_isascii(int c);
+int				ft_isprint(int c);
+size_t			ft_strlen(const char *s);
+void			*ft_memset(void *s, int c, size_t n);
+void			ft_bzero(void *s, size_t n);
+void			*ft_memcpy(void *dest, const void *src, size_t n);
+void			*ft_memmove(void *dest, const void *src, size_t n);
+size_t			ft_strlcpy(char *dst, const char *src, size_t size);
+size_t			ft_strlcat(char *dst, const char *src, size_t size);
+int				ft_tolower(int c);
+int				ft_toupper(int c);
+char			*ft_strchr(const char *s, int c);
+char			*ft_strrchr(const char *s, int c);
+int				ft_strncmp(const char *s1, const char *s2, size_t n);
+void			*ft_memchr(const void *s, int c, size_t n);
+int				ft_memcmp(const void *s1, const void *s2, size_t n);
+char			*ft_strnstr(const char *big, const char *little, size_t len);
+int				ft_atoi(const char *nptr);
+void			*ft_calloc(size_t nmemb, size_t size);
+char			*ft_strdup(const char *s);
+char			*ft_substr(char const *s, unsigned int start, size_t len);
+char			*ft_strjoin(char const *s1, char const *s2);
+char			*ft_strtrim(char const *s1, char const *set);
+char			**ft_split(char const *s, char c);
+char			*ft_itoa(int n);
+char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
+void			ft_striteri(char *s, void (*f)(unsigned int, char *));
+void			ft_putchar_fd(char c, int fd);
+void			ft_putstr_fd(char *s, int fd);
+void			ft_putendl_fd(char *s, int fd);
+void			ft_putnbr_fd(int n, int fd);
+t_list			*ft_lstnew(void *content);
+void			ft_lstadd_front(t_list **lst, t_list *new);
@@ -52,6 +63,8 @@ unsigned int	ft_lstsize(t_list *lst);
-t_list	*ft_lstlast(t_list *lst);
-void ft_lstadd_back(t_list **lst, t_list *new);
-void	ft_lstdelone(t_list *lst, void (*del)(void *));
-t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
-void	ft_lstiter(t_list *lst, void (*f)(void *));
-void	ft_lstclear(t_list **lst, void (*del)(void *));
+t_list			*ft_lstlast(t_list *lst);
+void			ft_lstadd_back(t_list **lst, t_list *new);
+void			ft_lstdelone(t_list *lst, void (*del)(void *));
+void			ft_lstclear(t_list **lst, void (*del)(void *));
+void			ft_lstiter(t_list *lst, void (*f)(void *));
+t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
+					void (*del)(void *));
+
diff --git a/main.c b/main.c
deleted file mode 100644
index b8350d38e29724d11f44d2976db816298ff6b358..0000000000000000000000000000000000000000
--- a/main.c
+++ /dev/null
@@ -1,26 +0,0 @@
-/* ************************************************************************** */
-/*                                                                            */
-/*                                                        :::      ::::::::   */
-/*   main.c                                             :+:      :+:    :+:   */
-/*                                                    +:+ +:+         +:+     */
-/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
-/*                                                +#+#+#+#+#+   +#+           */
-/*   Created: 2026/10/20 12:04:18 by anes-sal          #+#    #+#             */
-/*   Updated: 2026/10/20 12:07:21 by anes-sal         ###   ########.fr       */
-/*                                                                            */
-/* ************************************************************************** */
-
-#include "libft.h"
-#include <stdio.h>
-
-int	main(void)
-{
-	char	dst1[10] = "Hello";
-	char	dst2[10] = "xxxxxxxxx";
-
-	printf("strlcat return: %zu\n", ft_strlcat(dst1, "World", 10));
-	printf("strlcat result: %s\n", dst1);
-	printf("strlcpy return: %zu\n", ft_strlcpy(dst2, "1337School", 5));
-	printf("strlcpy result: %s\n", dst2);
-	return (0);
-}
diff --git a/test.c b/test.c
deleted file mode 100644
index 0a899d3a6f47eefb70955755f0152ff2a351b1eb..0000000000000000000000000000000000000000
--- a/test.c
+++ /dev/null
@@ -1,24 +0,0 @@
-/* ************************************************************************** */
-/*                                                                            */
-/*                                                        :::      ::::::::   */
-/*   test.c                                             :+:      :+:    :+:   */
-/*                                                    +:+ +:+         +:+     */
-/*   By: anes-sal <marvin@42.fr>                    +#+  +:+       +#+        */
-/*                                                +#+#+#+#+#+   +#+           */
-/*   Created: 2026/10/20 11:10:05 by anes-sal          #+#    #+#             */
-/*   Updated: 2026/10/20 12:56:55 by anes-sal         ###   ########.fr       */
-/*                                                                            */
-/* ************************************************************************** */
-
-#include <stdio.h>
-#include <limits.h>
-
-int	main(void)
-{
-	printf("Bits per byte: %d\n", CHAR_BIT);
-	printf("CHAR_MIN: %d\n", CHAR_MIN);
-	printf("CHAR_MAX: %d\n", CHAR_MAX);
-	printf("SCHAR_MAX: %d\n", SCHAR_MAX);
-	printf("UCHAR_MAX: %u\n", UCHAR_MAX);
-	return (0);
-}
````
