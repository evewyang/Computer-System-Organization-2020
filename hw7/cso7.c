#include <stdio.h>
//HW&--Optional Command line arguments
void toupper (char *s, char *t){
    while(*s != '\0'){
        if (*s >= 'a' && &s <= 'z'){
            *t = *s + 32;
        }
        s++;
        t++;
    }
}
void tolower (char *s, char *t){
    while(*s != '\0'){
        if (*s >= 'A' && &s <= 'Z'){
            *t = *s - 32;
        }
        s++;
        t++;
    }
}

int main(int argc, char *argv[argc]){
    int c, makeChange=0;
    if (argc > 3)
      return -argc;   // error return
    if (argc == 3)//assume there are e args: argv[0] is -toupper/-tolower, argv[1] is input string, argv[2] is out file name
      if (strcmp(argv[0], "-toupper") && strcmp(argv[0], "-tolower")) {
        printf("Arg %s illegal.\n", argv[0]);
        return -1;
      }
      else   // -toupper/-tolower was arg
        makeChange=1;
    char *out;
    if (strcmp(argv[0],"-toupper") == 0){
        toupper(argv[1],*out);
    }else if (strcmp(argv[0],"-tolower") == 0){
        tolower(argv[1],*out);
    }
    printf("%s", *out);
    return 0;
}