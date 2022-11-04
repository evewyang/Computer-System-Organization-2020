#include <stdio.h>
int mystrcmp(char *s, char *t) {
    for (; *s == *t; s++,t++){
        if (*s == '\0'){
            printf("enter if statement\n");
            return 0;
        }
    }
    return *s - *t;
}
int main(){
    // char s[] = "ab";
    // char t[] = "ab";
    // int out = mystrcmp(s,t);
    // printf("%d\n",out);
    // printf("%s %s\n",s,t);
    
    int arr[2] = {1,2};
    int temp;
    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
    printf("%d %d\n",arr[0],arr[1]);
    return 0;
}