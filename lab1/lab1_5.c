#include <stdio.h>
#include <stdlib.h>
int isPrime(int n){
    if (n == 1){//special case n = 1: not prime 
        return 1;
    }
    if (n == 2){//special case n = 2 : prime 
        return 1;
    }
    int i = 2;//assume n is larger than 1
    while (i <= n/2) {
        if (n % i==0){
            return 0;//full division, then not prime
        }
        i++;
    }
    
    return 1;//no full division happened, then it is prime 
}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Error: agrc != 3.\n");
        return 0;
    }
    int arg1 = atoi(argv[1]);//assume both contain only digits 
    int arg2 = atoi(argv[2]);
    if(arg1 <= arg2){
        int n = arg1;
        while(arg1 <= n && n <= arg2){
            if(isPrime(n) == 1){
                printf("%d is prime.\n",n);
            }else{
                printf("%d is not prime.\n",n);
            }
            n++;
        }
        return 0;
    }
    printf("Error: arg1< arg2.\n");
    return 0;

}