#include <stdio.h>
#include <string.h>
void entab(char s[],char t[]){
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

void detab(char s[], char t[]){
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

int tab(int argc, char *argv[argc]){
    if (argc != 3){
        return -argc;
    }
    if (argc == 3){
      if (strcmp(argv[2], "-en") && strcmp(argv[2],"-de")) {
        printf("Arg %s illegal.\n", argv[1]);
        return -1;
      }
    }
    printf("file open...\n");
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL){
        printf("file is null\n");
    }
    char c;

    char buf[1024] = {'\0'};
    fgets(buf, 1024, fp);

    printf("Enter while loop. buf:%s\n", buf);

    char newtab[1024] = {'\0'};
    if (strcmp(argv[2],"-en") == 0){
        entab(buf, newtab);
    }else if (strcmp(argv[2],"-de") == 0){
        detab(buf, newtab);
    }
    printf("%s", newtab);
    printf("\n");
    
    return 0;
}