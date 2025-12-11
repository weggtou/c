#include <stdio.h>

int main(){
  char a [] = "C language is fun.";
  char*p = a;
  printf("%s\n",p);
  printf("%c\n",*(p+11));
  p+=13;
  printf("%s\n",p);
}