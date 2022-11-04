Wenhan Yang -- Lab 1

Content 
    lab1_1.c: int vowels(char *str)
        -changes vowels 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' to '*'.
    
    lab1_2.c: int longer(char *s, char *t)
        -compare 2 string and print out the longer one, then return the sum of thier lengths 
    
    lab1_3.c: void interleave(char *ans, char *s, char *t, int n) 
        -merge 2 equal-lengthed strings into 1 interleaved string 

    lab1_4.c: int main(int argc, char *argv[])
        -This program reads characters using getchar() and prints characters using putchar().
    
    lab1_5.c: int isPrime(int n), int atoi(char s[]), int primeTbl(int argc, char *argv[]) 
        -5.1 isPrime(n) returns 1 if n is prime and returns 0 otherwise. You may assume n is an integer greater than 1.
        -5.2 Only when arg1 <= n <= arg2, call isPrime(n) and print whether n is prime. Print error message for other cases.

    lab1_6.c: main(int argc, char *argv[])
        -accepts two command-line arguments(string) str and except. Check if char is legal & putchar() the char in str differnt from except. 

Compile & Run
    lab1_1.c, lab1_2.c, lab1_3.c, lab1_4.c: 
        gcc xxx.c
        ./a.out
    lab1_5.c:
        gcc lab1_5.c  
        ./a.out arg1 arg2 
            e.g. "./a.out 13 12" will give you "Error: arg1< arg2."
            e.g. "./a.out 12 13" will give you "12 is not prime. 13 is prime."
    lab1_6.c:
         gcc lab1_6.c
         ./a.out str except
            e.g. "./a.out abcde 1234b" will give you "acde"

    NOTE: if error in linserv says:"c99 environment needed for xxxx", use gcc -std=c99 program.c to change the environment. 