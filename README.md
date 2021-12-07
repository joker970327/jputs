# jputs

<!-- ## How to use -->


## generate test file 
```
make 
```
生成可执行文件main
之后就可以运行main了
```
./main
> Hello World!
```
```
make clean
```
清除可执行文件以及依赖项


## 内联汇编的约束

`"g"` 是指“允许使用任何寄存器、内存或立即整数操作数，但不是通用寄存器的寄存器除外。”

原文：

> "g" : Any register, memory or immediate integer operand is allowed, except for registers that are not general registers.

链接：[GCC-Inline-Assembly-HOWTO](http://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html)

## PS:一个有趣的现象
在文件中 puts.h 中，变量 n 是计算输入字符串的长度，在内联汇编中传给 rdx 寄存器，rdx 寄存器宽度为64位。

1. 如果声明是
```c
int n = 0;
```
则不会输出字符串！！

猜测是因为宽度问题，没有自动扩展？？

2. 如果声明是

```c
long n = 0;
unsigned long n = 0;
long long n = 0;
unsigned long long n = 0;
```
以上情况中的任一种，则可以输出字符串！

3. 最有趣的，如果声明是

```c
int n = 0;
int r = 0;
```

以上连续的两个声明，则又可以输出字符串！！