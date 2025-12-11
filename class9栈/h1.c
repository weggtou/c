#include <stdio.h>
int jiechen(int n){
  if(n==1){
    return 1;
  }else{
    return n*jiechen(n-1);
  }
}

int main(){
  int n;
  scanf("%d",&n);
  printf("%d",jiechen(n));
}