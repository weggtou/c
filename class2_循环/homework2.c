#include <stdio.h>
#define pow(x) ((x)*(x)*(x))
int main(){

  for(int i=100;i<=999;i++){
    int sum=0,x=i;
    for(;x;x/=10){
      sum+=pow(x%10);
    }
    if(sum==i){
      printf("%d\n",i);
    }
  }

}