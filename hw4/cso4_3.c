#include <stdio.h>
void *strcpy(char *s, char*t, int n){
    char *p = s;
    while((*s=*t) != '\0' && n!=0){
        s++;
        t++;
        n--;
    }
    *s='\0';
    return p;
}

int main(){
    char t[] ="Computer System Org";
    char s[100];
    int n = 10;//destination should be "Computer S"
    strcpy(s,t,n);
    char *q = s;
    //print outcome s:
    while(*q!='\0'){
        printf("%c",*q);
        q++;
    }
    printf("\n");
    return 0;
}