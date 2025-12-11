#include <stdio.h>

int main(){
  int num,cont=0;
  scanf("%d",&num);
  for(;num<0;){
    printf("²»ºÏ·¨\n");
    scanf("%d",&num);
  }
  
  do{
    num/=10;
    cont++;
  }while(num);
      

  printf("%d",cont);
}