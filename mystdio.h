#ifndef MY_STDIO_H
#define MY_STDIO_H

#include "typedefs.h"
#include "syscall.h"

static inline int my_strlen(const char* s) {
    const char* start = s;
    for (; *s++ != '\0';);
    return s - start;
}

static inline long my_fprintf(int fd, const char* s) {
    return my_syscall(SYS_WRITE, fd, s, my_strlen(s), 0, 0, 0);
}

static inline long my_getchar(int fd, char* c) {
    return my_syscall(SYS_READ, fd, c, 1, 0, 0, 0);
}

static inline ulong my_read(int fd, char* buf, ulong bufsize) {
    if (bufsize == 0 || !buf) { return -1L; }

    char c;
    ulong i = 0;

    while (i < bufsize - 1) {
        long bytes_read = my_getchar(fd, &c);

        if (bytes_read < 0) {
            return -1;
        } else if (bytes_read == 0) {
            break;
        }

        buf[i++] = c;
        
        if (c == '\n') { break; }
    }

    buf[i] = '\0';
    return i;
}

#endif // MY_STDIO_H