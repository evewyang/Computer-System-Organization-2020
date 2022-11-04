#include <stdio.h>
#include <string.h>
// #include <stdbool.h> 
void interleave(char *ans, char *s, char *t, int n){
    //IMPORTANT: assume len1 = len2
    int len1 = strlen(s);
    int len2 = strlen(t);
    if (len1 + len2 > n){
        printf("error\n");
        return;
    }  
    int p1=0, p2=0;
    int pos=0;
    // bool run = true;
    while (1==1){
        ans[pos++] = s[p1++];
        ans[pos++] = t[p2++];
        if (pos==len1+len2){
            break;
        }
    }
}

//test case
int main(){
    char ans[1000];//set ans large enough
    char s[]="abcdefg";//len1 = len2
    char t[]="1234567";
    int n = 14;//len1 + len2 = n
    printf("2 strings before interleave(): %s, %s\n",s,t);
    printf("1 string after interleave(): ");
    interleave(ans,s,t,n);
    printf("%s",ans);
    // while(*p != '\0'){
    //     printf("%c",*p);//print out the ans
    //     p++;
    // }
    printf("\n");
    return 0;
}