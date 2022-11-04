#include <stdio.h>
int main() {
  int prev = 0;
  int this;
  while ((this = getchar()) != EOF){
    if (prev != ' ' && prev != '\n' && prev != '\t'){
         if (this == ' ' || this == '\t'){
            this = '\n'; 
         }
      putchar(this);
      prev = this;
    }else{
      if (this == ' ' || this == '\n' || this == '\t'){
        continue;
      }else{
          putchar(this);
          prev = this;
      }
    }
  }
  return 0;
}
