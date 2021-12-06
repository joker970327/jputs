// #include <stdio.h>

int jputs(char* input){
    int n = 0;
    int ret = 0;

    for(n=0;*(input + n) != '\0';++n){
        ;
    }

    
    __asm__ __volatile__ (
        "mov $1, %%rdi\n"
        "mov %[buf], %%rsi\n"
        "mov %[len], %%rdx\n"
        "mov $1, %%rax\n"
        "syscall\n"

        :
        :[buf]"g"(input), [len]"g"(n)
    );

    return n;
    // return ret;
}

int main()
{
    int retj = 0;
    retj = jputs("Hello World!");
    // printf("%d\n", retj);

    return 0;
}