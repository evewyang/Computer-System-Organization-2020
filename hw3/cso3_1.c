#include <stdio.h>
void rotate3(int *A, int *B, int *C){
    int temp;
    temp = *A;
    *A = *B;
    *B = *C;
    *C = temp;
    printf("Inside the function: a = %d,b = %d,c = %d\n",*A,*B,*C);
}
int main(){
    // int *a, *b, *c;
    // int p = 1;
    // a = &p;
    // int q = 2; 
    // b = &q;
    // int r = 3;
    // c= &r;
    // printf("Before Rotation: a = %d,b = %d,c = %d\n",*a,*b,*c);
    // rotate3(a,b,c);
    // printf("After Rotation: a = %d,b = %d,c = %d\n",*a,*b,*c);
    int a = 1, b = 2, c = 3;
    printf("Before Rotation: a = %d,b = %d,c = %d\n",a,b,c);
    rotate3(&a,&b,&c);
    printf("After Rotation: a = %d,b = %d,c = %d\n",a,b,c);
    return 0;
}