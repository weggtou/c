#include <stdio.h>

int main(){
  int a[3][4];

  for(int i = 0;i<3;i++){
    for(int j = 0;j<4;j++){
      scanf("%d",&a[i][j]);
    }
  }

  for(int i = 0;i<3;i++){
    double sum = 0;
    for(int j = 0;j<4;j++){
      sum+=a[i][j];
    }
    printf("第%d行平均值: %.2lf",i+1,sum/4);
  }
}