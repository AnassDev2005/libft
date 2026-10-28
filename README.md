*This project has been created as part of the 42 curriculum by anes-sal.*

# Libft

## Description

Libft is a C static library that recreates common library functions and adds
string, output, and linked-list utilities. The project develops an understanding
of pointers, byte operations, allocation, callbacks, and memory ownership.

This repository follows the supplied **Libft subject, version 19.3**. All
**43 functions are mandatory**: 23 in Part 1, 11 in Part 2, and 9 in Part 3.
The linked-list functions are included by `make`; this version has no bonus part.
The build creates `libft.a` at the repository root.

### Library contents

| Part | Functions | Purpose |
| --- | --- | --- |
| 1 | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Classify ASCII characters; return exactly 1 or 0 |
| 1 | `ft_toupper`, `ft_tolower` | Convert ASCII letter case |
| 1 | `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` | Measure, find, and compare strings |
| 1 | `ft_strlcpy`, `ft_strlcat` | Copy or append within a destination capacity; return the attempted length |
| 1 | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` | Operate on a specified number of bytes |
| 1 | `ft_atoi` | Convert a decimal integer prefix to `int` |
| 1 | `ft_calloc`, `ft_strdup` | Allocate zeroed memory or duplicate a string |
| 2 | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa` | Allocate substrings, joined/trimmed/split strings, or an integer representation |
| 2 | `ft_strmapi`, `ft_striteri` | Apply a callback to each character with its index |
| 2 | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write characters, strings, lines, or integers to a file descriptor |
| 3 | `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back` | Create and link list nodes |
| 3 | `ft_lstsize`, `ft_lstlast` | Count nodes or find the last node |
| 3 | `ft_lstdelone`, `ft_lstclear` | Release one node or a list, using a content destructor |
| 3 | `ft_lstiter`, `ft_lstmap` | Visit contents or create a mapped list |

`libft.h` declares the public functions and the `t_list` structure. Each node
contains a `void *content` and a `struct s_list *next`. For this subject,
`ft_lstsize` returns **`unsigned int`**.

### Contracts and memory ownership

- Strings must be NUL terminated; byte functions require buffers large enough
  for the requested operation. Part 1 follows the C locale/ASCII behavior used
  by this project, with the subject's exact 1/0 classification returns.
- `ft_memcpy` requires non-overlapping ranges; `ft_memmove` also supports overlap.
  `ft_strncmp` and `ft_memcmp` guarantee the comparison sign, not a particular
  positive or negative magnitude from the system implementation.
- `ft_atoi` handles optional leading whitespace and one sign, then stops at the
  first non-digit. Standard behavior does not define out-of-`int` conversions.
  On this GCC/glibc target (32-bit `int`, 64-bit `long`), the implementation
  reproduces the tested libc return values: signed-long range checking followed
  by conversion to `int`. No extra header or libc conversion call is used.
  This compatibility extension compares return values, not `errno` side effects.
- Allocating functions return `NULL` on allocation failure. The caller frees
  successful results. For `ft_split`, free each word, then the pointer array.
  Empty results are still allocated. A successful zero-size `ft_calloc` returns
  a distinct pointer that may be freed, as required by the subject.
- `ft_lstnew` stores the supplied content pointer without copying it.
  `ft_lstdelone` and `ft_lstclear` use the supplied `del` callback for content.
  Choose a callback that matches the content's ownership. `ft_lstmap` creates
  new nodes, frees partial mapped results if node allocation fails, and leaves
  the source nodes intact. Its callback determines whether content is copied.

## Instructions

### Compilation

Requirements: a C compiler available as `cc`, Make, and the `ar` archiver. No
separate installation step or external library is needed to use Libft.

```sh
make
```

The Makefile compiles all 43 sources using `cc -Wall -Wextra -Werror`, then uses
`ar rcs` to create `libft.a`. Repeating `make` does not rebuild an up-to-date
library. Changing `libft.h` rebuilds its dependent objects.

| Command | Result |
| --- | --- |
| `make` / `make all` / `make libft.a` | Build the complete library |
| `make clean` | Remove project object files |
| `make fclean` | Remove object files and `libft.a` |
| `make re` | Clean and rebuild the library |

### Usage

Save this example as `main.c` next to the library while testing:

```c
#include "libft.h"

int	main(void)
{
	ft_putendl_fd("Hello, Libft!", 1);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o program
./program
```

Expected output: `Hello, Libft!` followed by a newline. When building elsewhere,
add `-I/path/to/libft` for the header and `-L/path/to/libft` for the archive.
Place `-lft` after the source or object files that use it. Keep example programs
and test binaries outside the submitted project files.

### Verification and audit notes

The audit compared Part 1 with system libc and BSD implementations, exercised
Parts 2 and 3 against the supplied contracts, injected allocation failures, and
checked the Makefile and header. The final checks passed: 886,744 Part 1
assertions per configuration, 670,744 Part 2/list assertions, and 19
build/header/style checks. A further 173,194 `ft_atoi` inputs per configuration
matched the host libc return values, including overflow observations.

ASan and UBSan checks passed. LeakSanitizer was unavailable inside the audit
sandbox; an allocation tracker checked cleanup in the Part 2/list tests.
These are finite tests on the documented target, not a guarantee for every
possible input or platform.

```sh
make
make
norminette ft_*.c libft.h
```

Norminette checks style; the build checks compilation. Neither replaces behavior
and memory tests. On the audit machine, Norminette is also available as
`/home/anass/.local/share/nvim/42-tools/bin/norminette`.

### Submission files

The required submission consists of `Makefile`, `README.md`, `libft.h`, and the
43 root-level `ft_*.c` files. Keep personal study notes, test programs, and the
compilation-course folder outside the submitted revision. The subject requires
project files at the repository root and prohibits unused files.

## Resources

- The supplied **Libft subject v19.3**, especially pages 7–17, is the authority
  for this repository's function list, prototypes, and README requirements.
- [C language committee draft N1570](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf),
  sections 7.4, 7.22, and 7.24: character functions, allocation/conversion, and
  byte/string operations.
- [OpenBSD `strlcpy` / `strlcat` manual](https://man.openbsd.org/strlcpy.3):
  bounded copying, appending, and return values.
- [FreeBSD `strnstr` manual](https://man.freebsd.org/cgi/man.cgi?query=strnstr&sektion=3):
  bounded substring search.
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html):
  targets, prerequisites, and incremental builds.
- [42 Norminette](https://github.com/42School/norminette): the coding-style checker.

### AI usage

ChatGPT/Codex assisted with this review by reading the supplied subject,
reviewing all three function groups, generating and running separate tests,
checking memory cleanup and build behavior, correcting the Makefile header
dependency, zero-size `ft_calloc` allocation, and `ft_atoi` overflow handling,
removing an unused header include, and preparing this README and separate
audit/study documents.
The test results are recorded separately from claims about undefined inputs.
The student must understand and be able to explain the submitted implementation.
