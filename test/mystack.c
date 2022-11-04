#include <stdio.h>
#include <stdlib.h>
//   int main(int argc, char *argv[]) {
//     int n;
//     char *As; 
//     scanf("%d", &n);
//     As = (char *) malloc(n * sizeof(char));
//     for (int i = 0; i<n-1; i++)
// 	  As[i] = 'A';
//     As[n-1] = '\0';
//     printf("As is: %s\n", As);
//     return 0;
//   }

#define STACK_SIZE 64  //stack size
#define TOP_OF_STACK -1 //top of stack 

int stack_push(char* stack,int top,int value);
int stack_pop(char * stack,int top);
int stack_is_empty(int top);
int stack_is_full(int top);

//入栈
int stack_push(char* stack,int top,int value)
{
    if (stack_is_full(top)) 
    {
        printf("Stack is full\n");
        return -1;
    }

    stack[++top]=value;
    printf("Stack in：%d\n",stack[top]);
    return top;
}

//出栈
int stack_pop(char * stack,int top)
{
    if (stack_is_empty(top)) 
    {
        printf("empty stack\n");
        return -1;
    }
    printf("Stack out：%d\n",stack[top]);
    top--;
    return top;
}

int stack_is_empty(int top)
{
    return top ==  - 1;
}

int stack_is_full(int top)
{
    return top == STACK_SIZE - 1;
}


int main(int argc, char **argv) 
{
    char stack[100];//64<100
    int top = TOP_OF_STACK;  //top of stack
    top=stack_push(stack, top, 1);
    top=stack_push(stack, top, 2);
    top=stack_push(stack, top, 3);
    top=stack_push(stack, top, 4);

    top=stack_pop(stack, top);
    top=stack_pop(stack, top);
    top=stack_pop(stack, top);
    top=stack_pop(stack, top);
    top=stack_pop(stack, top);

    return 0;
}
