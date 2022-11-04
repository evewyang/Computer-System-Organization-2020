#include <stdio.h>
int is_little_endian(){     
    long i = 1;             
    char *arr = &i;      
    if(arr[0]){  
        //little endian  
        //-------> higher memory
        //0X01 0X00 0X00 0X00 0X00 0X00 0X00 0X00         
        printf("%d\n", 1);
    }else{
        //big endian
        //-------> higher memory
        //0X00 0X00 0X00 0X00 0X00 0X00 0X00 0X01  
        printf("%d\n", 0);
    }
    return 1;
}
int main(){
    is_little_endian();
    return 0;
}
//is_little_endian:
    //pushq %rbx
    //movq  %rsp,%rbx
    //movq  $1,-4(%rbx)
    //movb -4(%rbx),%bl
    //jz   .L5
    //movq $0,%rax
    //ret 
//.L5:
    //movq $1,%rax
    //ret

//answer 2:
// int main()
// {
//   int x = 1;

//   char *y = (char*)&x;

//   printf("%c\n",*y+48);
// }