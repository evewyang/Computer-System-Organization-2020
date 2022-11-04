#include <stdio.h>
#include <stdlib.h>

int test_1(int x){
    //return true/1 if any bit of x is equal to 1
    return !!(x & -1); //-1 = 1111 1111 ... 1111
    //if there is at least one binary 1, the return value will be 1->true 
} 
int test_2(int x){
    //return true if any bit of x is equal to 0;
    return !!((~x) & -1); //take 
}

int test_3(int x){
    //return true if the least significant byte of x contains bit of 1
    return !!(x & 0xFF); //isolate the least significant byte  
    //e.g. 1111 1111 0000 0001       vs         0000 ... 0000 1111 1111
    //only look at:  0000 0001      and         1111 1111 (FF)
    //take "&": bit by bit comparison. if x lowest byte contains one 1, return true
}
int test_4(int x){ 
    //return true if the most significant byte of x contains bit of 0
    return !!((~x) & 0xFF000000);
}

int main(){
    int a = 0;//0
    // int a1 = !8 + 1;//8 not 0, !8 = 0, a1 = 1
    int b = 2;
    int c1 = 0xFF;//0000...0000 1111 1111
    int c2 = 0xFFFFFF00;
    // int input = sizeof(int) << 3;//00000100 ->left shift 3->00100000 = 2^5 =32
    // int d = 0xFF << (input - 8); 
    printf("%d\n",test_1(a));// 0 in binary is 0000: so return 0
    printf("%d\n",test_2(b));// 2 in binary is 0010: so return 1
    printf("%d\n",test_3(c1));
    printf("%d\n",test_4(c1));
    printf("%d\n",test_3(c2));
    printf("%d\n",test_4(c2));
    return 1;
}