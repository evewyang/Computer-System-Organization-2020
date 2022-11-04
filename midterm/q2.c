#include <stdio.h>
int main (int argc, char *argv[]){
    if(argc != 3){
        printf("Error: agrc != 3.\n");
        return 0;
    }
    //print chars in arg[1] not in arg[2]
    char *str = argv[1];
    char *except = argv[2];
    int i = 0;
    int isSame;
    while (str[i] != '\0') {
        isSame = 0;
        int k = 0;
        while (except[k] != '\0') {
            if(str[i] == except[k]){
                isSame = 1;
                break;
            } 
            k++;
        }
        if (isSame == 0){
            putchar(str[i]);
        }
        isSame = 0; 
        i++;
    }
    printf("\n");
    //print chars in arg[2] not in arg[1]
    char *str1 = argv[1];
    char *except1 = argv[2];
    int j = 0;
    while (except1[j] != '\0') {
        isSame = 0;
        int k = 0;
        while (str1[k] != '\0') {
            if(except1[j] == str1[k]){
                isSame = 1;
                break;
            } 
            k++;
        }
        if (isSame == 0){
            putchar(except1[j]);
        }
        isSame = 0; 
        j++;
    }
    printf("\n");
}