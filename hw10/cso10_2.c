#include <stdio.h>
#include <stdlib.h>
int any_odd_one(unsigned x){
    return (x & 0x55555555) && 1;//0x5555 = 0101 0101 0101 0101 isolates odd bits
}
int any_even_one(unsigned y){
    return (y & 0xAAAAAAAA) && 1; //!!(y & 0xAAAAAAAA) 
}

int main (){
    unsigned a = 2; //0010
    unsigned b = 3; //0011
    printf("(2)_2 = 0010: %d\n", any_odd_one(a));
    printf("(3)_2 = 0011: %d\n", any_odd_one(b));
    // printf("(2)_2 = 0010: %d\n", any_even_one(a));
    // printf("(3)_2 = 0011: %d\n", any_even_one(b));

}