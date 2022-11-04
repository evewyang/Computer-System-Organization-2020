#include <stdio.h>
void plusminus(int *x,int *y){
    int oldx, oldy;
    oldx = *x;
    oldy = *y;
    *x = oldx + oldy;
    *y = oldx - oldy;
}

int main(){
    int x, y;
    x = 10;
    y = 6; 
    printf("Before plusminus(int *x,int *y): x = %d,y = %d\n",x,y);
    printf("Sets x to old x + old y, sets y to old x - old y\n");
    plusminus(&x, &y);
    printf("After plusminus(int *x,int *y): x = %d,y = %d\n",x,y);
    return 0;
}