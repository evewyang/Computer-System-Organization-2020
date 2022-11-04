#include <stdio.h>
void changeltox (char s[], int length){//array style
    for (int i = 0; i < length ; i++){//for loop
        if (s[i] == 'l'){
            s[i] = 'x';
        }   
        printf("%c",s[i]);
    }
}

int main(){
    char test[]={'*','p',' ','l'}; //test array 
    int size = (sizeof(test)/sizeof(char));
    printf("Before change:");
    int i = 0;
    while(test[i]!='\0'){
        printf("%c",test[i]);
        i++;
    }
    printf("\n");
    printf("After change:");
    changeltox(test,size);
    printf("\n");
    return 0;
}