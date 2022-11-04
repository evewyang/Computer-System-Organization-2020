#include<stdio.h>
#include<ctype.h>

#define SIZE 1000
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;


int getch(void){
    return (bufp > 0)? buf[--bufp] : getchar();
}


void ungetch(int c){
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}


int getint(int *pn){
    int c,sign;

    while(isspace(c=getch())); //skip with space

    if(!isdigit(c) && c !=EOF && c!='+' && c!='-'){
        ungetch(c); //its not a number
        return -1; //end the program   
    }

    sign = (c == '-') ? -1 : 1;

    if( c == '+' || c == '-') {//if c is a sign
        c = getch();
    }

    if( !isdigit(c) )//if next not digit 
        return 0; //end program  

    for(*pn = 0; isdigit(c);c=getch())
        *pn = 10 * *pn + (c-'0');

    *pn *= sign;

    if(c!=EOF){
        ungetch(c);//push back
    }
    return c;
}

int main(void){
    int n,s,array[SIZE],getint(int *),res;
    
    for(n=0;n<SIZE && getint(&array[n]) !=EOF; (res!=0) ? n++:0 )
       printf("storing in n = %d, getint %d\n", n, array[n]);
    

    printf("storing in n = %d, getint %d\n", n, array[n]);

    for(s=0;s<=n; s++)
        printf("%d\n",array[s]);

    return 0;
     
}