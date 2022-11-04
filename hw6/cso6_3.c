#include <stdio.h>
#define MAXVAL 10000
#define ARRAYBOUND (MAXVAL+1)//10001

struct gameValType{
    int G;
    int P;
} gameVal[ARRAYBOUND];
//sizeof(gameValType) is 8 bytes: int is 4 byte
//there are 2 ints G,P in one struct,so 4 * 2 = 8 bytes 
//NOTE: 8 is the multipul of 4

struct gameValType {
    int G[ARRAYBOUND];
    int P[ARRAYBOUND];
} gameVal;
//sizeos(gameValType) is 80008 bytes: int G, P each occupy 4 bytes,
//and there are 2 int arrays of 10001 elements, so 
//10001*4+10001*4 = 80008 bytes
//NOTE: 80008 is the multipule of 

#define NUMEMPLOYEES 2
  struct employeeType {
    int id;//4 bytes
    char gender;//1 byte
    double salary;//8 bytes
    //3 bytes is needed for padding 
  } employee[NUMEMPLOYEES] = {
      { 32, 'M', 1234. },
      { 18, 'F', 1500. }
};
//sizeof (employee) is 32: 4 + 1 + 8 + 3 = 16 bytes, 
//as there are 2 elements in emplyee, 16 * 2 = 32 bytes.
//NOTE: in above structure, double (8 bytes) is the largest structure 
//so to prevent from the penalty compiler inserts some extra padding bytes to improve the performance of the CPU.
//i.e. 4+1+8 = 13 < 8*2 = 16 so 3 bytes padding are added.  
