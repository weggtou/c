#include <stdio.h>

void reverse_out(char *p);
int main(){
  char *p = "C programming";
  reverse_out(p);
}

void reverse_out(char*p){
  int i = 0;
  while(p[i]!='\0')i++;
  for(;i>=0;i--){
    printf("%c",p[i]);
  }
}