#include <stdio.h>
int main(int argc, char *argv[]){
    char c;
    char temp[] = "DIGIT";
    char *p;
    int end = 0;
    while((c = getchar()) != EOF){
        if(c >= 'A' && c <= 'Z'){//if inChar is uppercase letter
            c += 32;//change to lower case
            putchar(c);
        }else if (c >= 'a' && c <= 'z'){//if inChar is lowercase letter
            c = 'L'; //print 'L'
            putchar(c);
        }else if (c >= '0' && c <= '9'){
            p = temp;
            while (*p != '\0'){ 
                putchar(*p);
                p++;
            }
        }else{
            printf("\nError: Terminate at %c.\n",c);
            return 0;
        }
    }
    printf("\n");
    return 0;
}
