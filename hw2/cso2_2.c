#include <stdio.h>
#include <curses.h>
#include <string.h>

void squeeze(char s1[],int s2){
    int i,j = 0;

    while (s1[i] != '\0'){
        if (s1[i] != s2){
            s1[j++] = s1[i];
        }
        i++;
    }
    s1[j] = '\0';
    //print the squeezed s1
    for (int k = 0; s1[k] !='\0';k++){
        printf("%c\n", s1[k]);
    }
}

int main(){
    char arr[5] = {'a','b','b','c','d'}; 
    squeeze(arr,'b');
    return 0;
}