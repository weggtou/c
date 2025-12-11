#include <stdio.h>

int main(){
  int a[2][4];
  for(auto &i :a){
    for(auto &g:i){
      scanf("%d",&g);
    }
  }
  
  for(int i = 0;i<2;i++){
    for(int g = 0;g<4;g++){
      printf("%d ",a[i][g]);
    }
  }
}