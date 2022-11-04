#include <stdio.h>
int odd(int x){
    return x % 2;
}

int main(){
    printf("%d\n", odd(3));
    return 0;
}