#include <stdio.h>
#include <string.h>

int main(){
    char a[5] = {'A','B','1','2','F'};
    int len = sizeof(a)/sizeof(a[0]);
    printf("len is %d\n", len);
    printf("%d\n",htoi(a,len));
    return 0;
}

int hex2int(char c){
    if ((c >= 'A') && (c <= 'F')){
        return c - 'A' + 10;
    }else if ((c >= 'a') && (c <= 'f')){
        return c - 'a' + 10;
    }else if ((c >= '0') && (c <= '9')){
        return c - '0';
    }
}

int htoi(char s[], int length){
    int ans = 0;
    int power;
    for (int i = 0; i < length; i++){
        power = 1;
        for (int j = 0; j < i; j++){
            power = power * 16;
        }
        ans = ans + hex2int(s[i]) * power;
        printf("power is %d\n",power);
        printf("ans is %d\n",ans);
    } 
    
    return ans;
}