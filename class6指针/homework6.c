#include <stdio.h>
int max(int a,int b);
int min(int a,int b);
int main(){
  int x,(*p)(int,int),a,b;
  printf("功能:");
  scanf("%d",&x);
  printf("a:");
  scanf("%d",&a);
  printf("b:");
  scanf("%d",&b);
  switch (x){
  case 1:
    p=max;
    break;
  
  case 2:
    p=min;
    break;
  }
  printf("答案:%d",(*p)(a,b));
}
int max(int a,int b){
  return (a>b?a:b);
}
int min(int a,int b){
  return (a>b?b:a);
}