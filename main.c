#include "syscall.h"
#include "mystdio.h"

void _start() {
    my_fprintf(STDOUT, "Hello, world!\n");
    my_syscall(SYS_EXIT, 0, 0, 0, 0, 0, 0);

    char buf[64];
    my_read(STDIN, buf, sizeof(buf));
    my_fprintf(STDOUT, buf);
}

int __stack_chk_fail(void) {

}