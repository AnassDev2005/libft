#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libft.h"

static void    report(const char *who, const char *name, int status)
{
    if (WIFSIGNALED(status))
        printf("%-6s %-18s -> CRASH (signal %d: %s)\n", who, name,
            WTERMSIG(status), strsignal(WTERMSIG(status)));
    else
        printf("%-6s %-18s -> no crash\n", who, name);
}

static void    try_glibc(const char *name, void *d, const void *s, size_t n)
{
    pid_t    pid;
    int        status;

    pid = fork();
    if (pid == 0)
    {
        memcpy(d, s, n);
        _exit(0);
    }
    waitpid(pid, &status, 0);
    report("glibc", name, status);
}

static void    try_mine(const char *name, void *d, const void *s, size_t n)
{
    pid_t    pid;
    int        status;

    pid = fork();
    if (pid == 0)
    {
        ft_memcpy(d, s, n);
        _exit(0);
    }
    waitpid(pid, &status, 0);
    report("ft_", name, status);
}

int    main(void)
{
    char            buf[16] = "0123456789abcde";
    void *volatile    nul = NULL;

    printf("--- glibc memcpy ---\n");
    try_glibc("(dest, NULL, 5)", buf, nul, 5);
    try_glibc("(NULL, src, 5)", nul, buf, 5);
    try_glibc("(NULL, NULL, 5)", nul, nul, 5);
    try_glibc("(dest, NULL, 0)", buf, nul, 0);
    try_glibc("(buf, buf, 5)", buf, buf, 5);

    printf("\n--- your ft_memcpy ---\n");
    try_mine("(dest, NULL, 5)", buf, nul, 5);
    try_mine("(NULL, src, 5)", nul, buf, 5);
    try_mine("(NULL, NULL, 5)", nul, nul, 5);
    try_mine("(dest, NULL, 0)", buf, nul, 0);
    try_mine("(buf, buf, 5)", buf, buf, 5);
    return (0);
}
