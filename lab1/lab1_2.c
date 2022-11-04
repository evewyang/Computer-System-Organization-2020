#include <stdio.h>
#define SIZE 1000
int longer(char *s, char *t) {
    int i = 0,j = 0;
    char *p, *q;
    p = s;
    q = t;
    while ( *p != '\0'){
        i++;
        //printf("%d,%d,%c\n",i,p,*p);
        p++;
        
    }
    while ( *q != '\0'){
        j++;
        //printf("%d,%d,%c\n",j,q,*q);
        q++;
        
    }
    if( i > j ){
        while ( *s != '\0'){
            printf("%c", *s);
            s++;
        }
    }else if( i < j){
        while ( *t != '\0'){
            printf("%c", *t);
            t++;
        }   
    }else{
        printf("equal");
    }
    printf("\n");
    return i + j;
}

//test case 
int main(){
    char a[] = "abcde";
    char b[] = "1234";
    printf("The 2 strings are: %s, %s\n",a,b);
    printf("The longer string is: ");
    int out = longer(a,b);
    printf("Length of the longer string: %d\n",out);
    return 0;
}