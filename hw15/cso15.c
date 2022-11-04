#include <stdio.h>
long mult2(long x, long y){
    return x*y;
}
_mult2:
        movq     %rax, %rdi//copy x to ret 
        imulq    %rax, %rsi//multiple ret(x) with y 
        ret

void multstore(long x,long y,long *dest){
    long t = mult2(x,y);
    *dest = t;
}

_multstore:
        pushq    %rbx
        movq     %rbx, %rdx
        call     %mult2
        movq     (%rbx), %rax
        popq     %rbx
        ret

void multstore(long x,long y,long *dest){
    long t = mult2(y,x);//Assume the C call mult2(x,y) was instead mult2(y,x)
    *dest = t;
}

_multstore:
        pushq    %rbx//decrement the stack pointer
        movq     %rax, %rdi//copy x to t 
        movq     %rdi, %rsi//copy y to x
        movq     %rbx, %rdx//copy dest to %rbx
        movq     %rsi, %rax//copy t to y(x to y)
        call     mult2
        movq     (%rbx), %rax//*(dest) = t
        popq     %rbx//loads value from top of stack (namely value of dest)
        ret