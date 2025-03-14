#ifndef SYSCALL_H
#define SYSCALL_H

#include "sys_defs.h"

#define my_syscall(num, arg1, arg2, arg3, arg4, arg5, arg6) ({ \
    register long r10 asm("r10") = (long)(arg4);              \
    register long r8  asm("r8")  = (long)(arg5);              \
    register long r9  asm("r9")  = (long)(arg6);              \
    long ret;                                                 \
    asm volatile (                                            \
        "syscall"                                             \
        : "=a"(ret)                                           \
        : "a"(num), "D"(arg1), "S"(arg2), "d"(arg3),          \
          "r"(r10), "r"(r8), "r"(r9)                          \
        : "rcx", "r11", "memory"                              \
    );                                                        \
    ret;                                                      \
})

extern int __stack_chk_fail(void);

#endif // SYSCALL_H