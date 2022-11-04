#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *mcopy(char *s, int n){
    int str_len = strlen(s);
    int ret_len = str_len*n+1;//include the "\0"
    //leave space for memory
    char *ret = (char*)malloc(ret_len);
    //set memory blocks
    memset(ret,0,ret_len);

   for (int i = 0; i < n; i++){
       for (int j = 0; j < str_len; j++){
           ret[i*str_len+j]=s[j];
       }
   }
    return ret;
}

int main(){
    char *ret = mcopy("sdf123", 3);
    printf("%s\n",ret);
    return 0;
}
