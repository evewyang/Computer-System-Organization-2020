#include <stdio.h>
#define SIZE 1000

int vowel(char *str){
    int count = 0;
    while(*str != '\0'){
        if (*str == 'a' || *str == 'A' || *str == 'e' || *str == 'E' || *str == 'i' 
        || *str == 'I' || *str =='o' || *str=='O' || *str == 'u' || *str == 'U'){
            *str = '*';
            count++;
        }
        str++;
    }
    return count;
}

int main(){
    char in[SIZE];
    scanf("%s",in);
    int out = vowel(in);
    printf("number of vowels: %d\n",out);
    printf("%s",in);
    printf("\n");
    return 0;
}