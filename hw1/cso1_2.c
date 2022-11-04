#include <stdio.h>
int main() {
  int prev = 0;
  int this;
  while ((this = getchar()) != EOF){
    if (prev != ' '){
      putchar(this);
      prev = this;
    }else{
      if (this == ' '){
        continue;
      }else{
        putchar(this);
        prev = this;
      }
    }
  }
  return 0;
}
