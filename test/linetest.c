#include <stdio.h>
#include <string.h>
#define MAXLINE 5
// int getline(char *line, int max);
int getLine(char s[], int lim) {
    int c, i;
    for (i=0; i<lim-1 &&(c=getchar())!=EOF && c!='\n'; ++i)
      s[i] = c;
    if (c == '\n') {
      s[i]= c;
      ++i;
    }
    s[i] = '\0';
    return i;
  }
    // find: print lines matching argv[1]
int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;
    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        while (getLine(line, MAXLINE) > 0){
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
            printf("%d\n",found);
        }    
    return found;
}
