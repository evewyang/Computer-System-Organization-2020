#include <stdio.h>
#define ALLOCSIZE 15000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n) {
if (allocp+n <= allocbuf+ALLOCSIZE) {
    allocp += n;
    printf("allocp-n(before):%d,allocp(after):%d\n",allocp-n,allocp);
    return allocp-n;   // previous value
} else               // not enough space
    return 0;
}
void afree (char *p) {
if (p>=allocbuf && p<allocbuf+ALLOCSIZE)
    allocp = p;
    printf("allocp:%d\n",allocp);
}

int main(){
    char *p1, *p2, *p3;
    p1 = alloc(10);
    p2 = alloc(20);
    p3 = alloc(15);
    printf("\n");
    afree(p3);
    afree(p1);
    afree(p2);
    return 0;
}

