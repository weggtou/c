#include <stdio.h>

int countLetter(char *p);
int countDigit(char *p);
int main(){
  char x[50];
  scanf("%s",x);
  char*p=x;
  printf("字母个数%d\n",countLetter(p));
  printf("字母个数%d\n",countDigit(p));
}

int countLetter(char *p){
  int cont = 0;
  while(*p!='\0'){
    cont+=(*p<=57&&*p>=48);
    p++;
  }
  return cont;
}
int countDigit(char *p){
  int cont = 0;
  while(*p!='\0'){
    cont+=((*p<=90&&*p>=65)||(*p<=122&&*p>=97));
    p++;
  }
  return cont;
}