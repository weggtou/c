#include <stdio.h>
int hannuo(int n){
  if(n==1){
    return 1;
  }else{
    return hannuo(n-1)+1+hannuo(n-1);
  }
}
int main(){
  int n;
  scanf("%d",&n);
  printf("%d",hannuo(n));
}