#include <stdio.h>
#include <stdlib.h>

struct box3 {
    int factor1;
    int factor2;
    struct box3 *next;
}start,b1,b2,b3,b4;

int evalList(struct box3 *start){
    if(start == NULL){
        return 0;
    }
    int sum = 0;

    while (start->next != NULL){
        start = start->next;
        sum += start->factor1 * start->factor2;
    }
    return sum;
}

int main() {
    start.next = &b1;

    b1.factor1 = -1;
    b1.factor2 = -4;
    b1.next = &b2;

    b2.factor1 = -3;
    b2.factor2 = 2;
    b2.next = &b3;

    b3.factor1 = 1;
    b3.factor2 = 5;
    b3.next = &b4;

    b4.factor1 = 2;
    b4.factor2 = 4;

    int sum = evalList(&start);
    printf("sum:%d\n", sum);
    return  0;
}

