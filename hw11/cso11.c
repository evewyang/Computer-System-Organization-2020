#include <stdio.h>
void swap3(long *xp, long *yp, long *zp) { 
    long t = *xp; 
    *xp = *yp; 
    *yp = *zp; 
    *zp = t; 
}

void swap3asm(long *xp, long *yp, long *zp){
    //first arg xp is %rdi
    //second arg yp is %rsi
    //third arg zp is %rdx
    //callee saved is %rdx, %rax 
    asm("movq   (%rdi),%rax \n\t" //long t = *xp;
        "movq   (%rsi),%rbx \n\t" // t1 = *yp;
        "movq   %rbx,(%rdi) \n\t" // *xp = t1;
        "movq   (%rdx),%rbp \n\t" //t2 = *zp;
        "movq   %rbp,(%rsi) \n\t" //*yp = t2;
        "movq   %rax,(%rdx) \n\t" //*zp = t;
    );
}