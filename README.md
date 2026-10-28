*This project has been created as part of the 42 curriculum by anes-sal.*

# Libft

## Description

Libft is my first C library project at 42 School.

The goal of this project is to recreate some standard C library functions and build my own functions to better understand C programming, pointers, memory management, and linked lists.

My library contains **43 functions**, divided into three parts:

- **Part 1:** 23 standard C library functions, such as `ft_strlen`, `ft_memcpy`, `ft_atoi`, and `ft_strdup`.
- **Part 2:** 11 additional functions, such as `ft_split`, `ft_strjoin`, `ft_itoa`, and `ft_strtrim`.
- **Part 3:** 9 linked-list functions, such as `ft_lstnew`, `ft_lstadd_back`, `ft_lstclear`, and `ft_lstmap`.

All 43 functions are mandatory in my version of the subject.

The project creates a static library called `libft.a`, which I can reuse in my future C projects.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This creates the `libft.a` file using `cc` with the flags `-Wall -Wextra -Werror`.

Other available commands:

| Command | Description |
|---|---|
| `make` | Compile the library |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and `libft.a` |
| `make re` | Recompile everything |

### Usage

To use Libft in another C program, include the header:

```c
#include "libft.h"
```

For example:

```c
#include "libft.h"

int main(void)
{
    ft_putendl_fd("Hello, Libft!", 1);
    return (0);
}
```

Compile the program with the library:

```bash
cc main.c -L. -lft -o program
./program
```

Expected output:

```text
Hello, Libft!
```

### Testing

I tested my functions using a separate test program to compare their behavior with the expected results.

I also use `norminette` to check that my code follows the 42 coding standard.

```bash
norminette *.c libft.h
```

## Resources

These resources helped me understand C and how the functions work:

- [Linux manual pages](https://man7.org/linux/man-pages/) — to understand standard C functions and their behavior.
- [cppreference](https://en.cppreference.com/w/c) — for C syntax and library references.
- [GNU Make documentation](https://www.gnu.org/software/make/manual/make.html) — to understand Makefiles and compilation.
- **42 Libft subject** — for the project requirements and function descriptions.

### AI Usage

I used ChatGPT to help me understand some C concepts, especially pointers, memory management, structs, and linked lists.

I also used it to review some of my functions, get testing ideas, understand errors, and improve this README.

I compiled and tested my library to check its behavior.
