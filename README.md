*This project has been created as part of the 42 curriculum by anes-sal.*

# Libft

## Description

Libft is a reusable C library built as part of the 42 curriculum. Its goal is to
practice implementing common library routines, working with pointers, managing
dynamic memory, and building a static library with Make.

The project contains 34 core functions for character checks, memory operations,
string manipulation, conversions, and output to file descriptors. It also includes
9 functions for singly linked lists. All 43 functions are mandatory in the
Libft v19.3 subject. All library function names begin with `ft_`.

The build produces `libft.a`, which other C programs can link against. The public
header is [libft.h](libft.h). Each function has its own `.c` source file in the
repository root.

## Instructions

### Requirements

- A Unix-like environment with the standard C library and `<unistd.h>`.
- A C compiler available as `cc`, such as GCC or Clang.
- `make` and the `ar` archive utility.

No external libraries or package installation are required beyond these tools.
Run the following commands from the repository root.

### Compilation

```sh
make
```

This builds all 43 mandatory functions into `libft.a`: 23 libc-style functions,
11 additional functions, and 9 linked-list functions. The compiler is `cc`, with
`-Wall -Wextra -Werror`. The archive is created with `ar` in the repository root.
There is no separate bonus target in this version of the project.

The Makefile tracks source and header dependencies and avoids unnecessary
recompilation or archive updates when the build is already up to date.

| Command | Effect |
| --- | --- |
| `make` or `make all` | Build the complete mandatory library. |
| `make libft.a` | Build the library archive directly. |
| `make clean` | Remove all object files. |
| `make fclean` | Remove object files and `libft.a`. |
| `make re` | Clean and rebuild the complete library. |

### Linking and execution

Libft is a library and has no standalone executable. Include `libft.h` in a
calling program and link that program with `libft.a`. No system-wide installation
is needed.

For example, save this program outside the submission repository as
`/tmp/libft_example.c`:

```c
#include "libft.h"
#include <stdlib.h>

int main(void)
{
    char *message;

    message = ft_strjoin("Hello, ", "Libft!");
    if (!message)
        return (1);
    ft_putendl_fd(message, 1);
    free(message);
    return (0);
}
```

From the library repository root, compile and run it with:

```sh
make
cc -Wall -Wextra -Werror -I. /tmp/libft_example.c libft.a -o /tmp/libft_example
/tmp/libft_example
```

Expected output:

```text
Hello, Libft!
```

To use the library from another project, provide the header directory and archive
path when compiling:

```sh
cc -Wall -Wextra -Werror -I/path/to/libft app.c /path/to/libft/libft.a -o app
```

### Checks and submission

Run `norminette` from the repository root to check the C sources and header when
the tool is installed. Check function behavior and allocation failures with
separate test programs kept outside the submitted repository.

Submit the 43 `ft_*.c` files, `libft.h`, `Makefile`, and `README.md`. Keep compiled
artifacts, standalone demonstration programs, and study notes out of the submitted
files. Only committed and pushed files reach the assigned evaluation repository.

## Library details

### Character operations

These functions operate on ASCII character values.

| Functions | Purpose |
| --- | --- |
| `ft_isalpha` | Check whether a value is an alphabetic character. |
| `ft_isdigit` | Check whether a value is a decimal digit. |
| `ft_isalnum` | Check whether a value is alphabetic or a decimal digit. |
| `ft_isascii` | Check whether a value belongs to the ASCII range. |
| `ft_isprint` | Check whether a value is a printable ASCII character. |
| `ft_toupper`, `ft_tolower` | Convert ASCII letter case; leave other values unchanged. |

### Memory operations

| Function | Purpose |
| --- | --- |
| `ft_memset` | Fill a specified number of bytes with a byte value. |
| `ft_bzero` | Set a specified number of bytes to zero. |
| `ft_memcpy` | Copy bytes between memory regions that do not overlap. |
| `ft_memmove` | Copy bytes while supporting overlapping regions. |
| `ft_memchr` | Find the first matching byte within a memory region. |
| `ft_memcmp` | Compare two memory regions byte by byte. |
| `ft_calloc` | Allocate zeroed memory for an array, checking for size multiplication overflow. |

### Strings and conversions

Strings use the C convention of a terminating NUL byte (`'\0'`).

| Function | Purpose |
| --- | --- |
| `ft_strlen` | Count characters before the terminating NUL byte. |
| `ft_strlcpy` | Copy a string into a bounded destination; return the source length. |
| `ft_strlcat` | Append within a destination size limit; return the total length attempted. |
| `ft_strchr`, `ft_strrchr` | Find the first or last occurrence of a character. |
| `ft_strncmp` | Compare up to a specified number of characters. |
| `ft_strnstr` | Find a substring within a limited portion of a string. |
| `ft_strdup` | Allocate a copy of a string. |
| `ft_atoi` | Convert an initial numeric portion of a string to an `int`. |
| `ft_substr` | Allocate a substring using a starting index and maximum length. |
| `ft_strjoin` | Allocate a string containing two strings joined together. |
| `ft_strtrim` | Allocate a copy with characters from a given set removed from both ends. |
| `ft_split` | Split a string on one delimiter character into an allocated, NULL-terminated array of strings. |
| `ft_itoa` | Allocate a decimal string representation of an `int`. |
| `ft_strmapi` | Allocate a new string by applying a callback to each character and its index. |
| `ft_striteri` | Apply a callback to each character and its index, allowing changes in place. |

### Output to file descriptors

These functions write to the supplied file descriptor, such as `1` for standard
output or `2` for standard error.

| Function | Purpose |
| --- | --- |
| `ft_putchar_fd` | Write one character. |
| `ft_putstr_fd` | Write a string. |
| `ft_putendl_fd` | Write a string followed by a newline. |
| `ft_putnbr_fd` | Write an integer in decimal form. |

### Part 3: mandatory singly linked lists

The list type stores a generic content pointer and a pointer to the next node:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Purpose |
| --- | --- |
| `ft_lstnew` | Allocate a node containing the supplied content pointer. |
| `ft_lstadd_front` | Insert a node at the beginning of a list. |
| `ft_lstsize` | Count the nodes; this implementation returns `unsigned int`. |
| `ft_lstlast` | Return the last node. |
| `ft_lstadd_back` | Append a node to the end of a list. |
| `ft_lstdelone` | Apply a deletion callback to a node's content, then free the node. |
| `ft_lstclear` | Delete every node and set the caller's list pointer to `NULL`. |
| `ft_lstiter` | Apply a callback to each node's content. |
| `ft_lstmap` | Build a new list from callback results, using a deletion callback to clean up if node allocation fails. |

### Memory ownership and callbacks

Check allocating functions for a `NULL` return before using their results. Memory
returned by `ft_calloc`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`,
`ft_itoa`, and `ft_strmapi` belongs to the caller and must be released with `free`.
For `ft_split`, free every returned string and then free the pointer array.

`ft_lstnew` stores the supplied content pointer without copying the pointed-to
data. Choose a deletion callback that matches how that content was allocated.
For example, `free` is suitable for separately allocated heap content. The callback
passed to `ft_lstmap` must return content whose ownership is compatible with the
provided deletion callback. In this implementation, mapping requires both
callbacks to be non-NULL.

Callers must provide valid buffers, appropriate sizes, and valid callback
arguments. Individual functions differ in their handling of NULL inputs; consult
the source for their exact behavior.

## Resources

- [Linux manual: string operations](https://man7.org/linux/man-pages/man3/string.3.html)
  provides references for string length, searching, comparison, and duplication.
- [OpenBSD manual: strlcpy and strlcat](https://man.openbsd.org/strlcpy.3)
  explains destination sizes, return values, and truncation detection.
- [Linux manual: malloc, calloc, and free](https://man7.org/linux/man-pages/man3/malloc.3.html)
  covers allocation, allocation failures, and releasing memory.
- [Linux manual: write](https://www.man7.org/linux/man-pages/man2/write.2.html)
  describes output through file descriptors.
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)
  explains targets, prerequisites, recipes, and incremental compilation.

For the exact campus submission and evaluation requirements, consult the Libft
subject provided through the 42 intranet.

### AI use

OpenAI Codex assisted with these project tasks:

- Reviewing the source files against the supplied Libft v19.3 subject and checking
  function declarations, permitted external functions, and submission contents.
- Creating and correcting the `Makefile` so the default build includes all 43
  mandatory functions and supports dependency tracking and cleanup.
- Correcting `ft_atoi` whitespace handling and signed-minimum conversion,
  `ft_calloc` zero-size allocation, and `ft_itoa` magnitude handling.
- Refactoring `ft_split` and `ft_lstmap` into short functions with linear traversal
  and allocation-failure cleanup, and correcting source/header formatting and
  public declarations for Norm compliance.
- Writing and updating this README, selecting references, and creating study
  questions kept outside the submission repository.
- Running Norminette, compilation and build checks, behavioral checks, overflow
  instrumentation, and allocation-failure probes using temporary test files.

AI-assisted implementation changes should be studied and independently reviewed
so the author can explain the algorithms, ownership rules, and failure paths.
