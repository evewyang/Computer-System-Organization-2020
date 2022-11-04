#include <stdio.h>

int main(int argc, char *argv[]){
    char *str = argv[1];
    char *except = argv[2];
    int i = 0;
    while (str[i] != '\0'){
        if (str[i] >= 'a' && str[i] <= 'z'){
            i++;
            continue;
        }
        printf("Error: illegal char.\n");
        return 0;
    }

    int isSame;
    int j = 0;
    while (str[j] != '\0') {
        isSame = 0;
        int k = 0;
        while (except[k] != '\0') {
            if(str[j] == except[k]){
                isSame = 1;
                break;//end this loop when equal
            } 
            k++;
        }
        if (isSame == 0){
            putchar(str[j]);
        }
        isSame = 0; 
        j++;
    }
    printf("\n");
    return 0;
}