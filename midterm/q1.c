#include <stdio.h>
int whichOne(char C, char *s1, char *s2){
    if (C < '0' || C > '9'){
        fprintf(stderr, "C is not a digit");
        return -1;
    }else{
        int count1 =0, count2 = 0;
        while (*s1 != '\0'){
            if (*s1 == C){
                count1++;
            }
            s1++;
        }
        while (*s2 != '\0'){
            if (*s2 == C){
                count2++;
            }
            s2++;
        }

        if(count1 > count2){
            printf("string one is the one");
            return count1;
        }else if (count1 < count2){
            printf("string two is the one");
            return count2;
        }else{
            printf("neither string is the one");
            return 0;
        }
        
    }
}
