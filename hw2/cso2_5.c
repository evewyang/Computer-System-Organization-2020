#include <stdio.h>
void escape(char s[],char t[]){
    int si = 0,ti = 0;
    while(s[si] != '\0'){
        if (s[si] == '\t'){
            t[ti++] = '\\';
            t[ti++] = 't';
        }else if (s[si] == '\n'){
            t[ti++] = '\\';
            t[ti++] = 'n';
        }else{
            t[ti++] = s[si];
        }
        si++;
    }
}

void unescape(char s[], char t[]){
    int si = 0, ti = 0;
    int next;
    while(s[si] != '\0'){
        if (s[si] == '\\'){
            next = si + 1;
            if (s[next] == 't'){
                t[ti++] = '\t';
            }else if (s[next] == 'n'){
                t[ti++] = '\n';
            }
            si = si + 2;
            continue;
        }
        t[ti++] = s[si];
        si++;
    }
}

int main(){
    char in[7] = {'a','\t','\t','b','c','d','\n'}; 
    char out[100];
    char backin[100];
    escape(in,out);
    unescape(out, backin);
    for (int k = 0; out[k] !='\0';k++){
        printf("%c", out[k]);
    }
    printf("\n");
    for (int k = 0; backin[k] !='\0';k++){
        printf("%c", backin[k]);
    }
    printf("\n");
    return 0;
}