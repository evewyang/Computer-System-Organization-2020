#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORDLENGTH 20
char word[MAXWORDLENGTH];
int  bufp = 0;

char getch() {
    return (bufp>0) ? word[--bufp] : getchar();
}
void ungetch(char c) {
    if (bufp >= MAXWORDLENGTH)
        printf("ungetch: too many chars\n");
    else
        word[bufp++] = c;
}

char *getword(char *word, int lim) {
    char c;
    char *p = word;
    while (isspace(c = getch())) 
        ;
    if (c != EOF){
        *word++ = c;
    } 
    if (!isalpha(c)) {
      *word = '\0';
      return c;
    }
    for ( ; --lim >= 0; word++){
       if (!isalnum(*word = getch())) {
        ungetch(*word);
        break;
      } 
    } 
    *word = '\0';
    return p;
}  

int main(){
    char word[MAXWORDLENGTH];
    char *command;
    char *new;
    char *name;
    char *after;
    while (1==1){
        command = getword(word, MAXWORDLENGTH);
       if(strcmp(command,"appendRear2D") == 0){
           name = getword(word, MAXWORDLENGTH);
           printf("%s\n", name);
       }else if(strcmp(command,"appendAfter2D") == 0){
           name = getword(word, MAXWORDLENGTH);
           printf("%s\n", name);
            after = getword(word, MAXWORDLENGTH);
            printf("%s\n", after); 
       }else if (strcmp(command,"Q")==0){
           printf("Quit!\n");
           return 0;
       }
       printf("out\n");
       printf("%s\n",word);
    } 
    return 0;
}