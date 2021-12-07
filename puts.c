#include "puts.h"

int puts(char* input){
    unsigned long n = 0;
    char *t = "\n";

    for(n=0;*(input + n) != '\0';++n);

    __asm__ __volatile__(
        "mov $1, %%rdi\n"
        "mov %[buf], %%rsi\n"
        "mov %[len], %%rdx\n"
        "mov $1, %%rax\n"
        "syscall\n"
        "mov $1, %%rdi\n"
        "mov %[nl], %%rsi\n"
        "mov $1, %%rdx\n"
        "mov $1, %%rax\n"
        "syscall\n"

        :
        : [buf] "g"(input), [len] "g"(n) ,[nl]"g"(t)
        : "%rdi", "%rsi", "%rdx", "%rax"

    );


    return n;
}