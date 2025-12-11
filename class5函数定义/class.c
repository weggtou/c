#include <stdio.h>

int jiechen(int n);

int main(){
  int n;
  scanf("%d",&n);
  printf("%d",jiechen(n));
}
int jiechen(int n){
  if(n==1)return 1;
  else return jiechen(n-1)*n;
}