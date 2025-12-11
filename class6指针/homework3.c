#include <stdio.h>

int main(){
  double all[7][3]={{2.0, 0.0, 1.5},
                {0.0,1.2,0.0},
                {3.4,2.1,0.0},
                {0.0,0.0,0.0},
                {5.0,4.5,2.3},
                {8.0,6.2,4.1},
                {7.5,5.3,3.0}};
  double sum = 0;
  double* p=all[0];
  for(int i = 0;i<21;i++){
    sum+= *(p+i);
  }
  printf("平均 = %.2f\n",sum/21);

  double (*p2)[3] = all+5;
  for(int i = 0;i<=1;i++){
    for(int g = 0;g<3;g++){
      printf("%.2f ",*(*(p2+i)+g));
    }
    printf("\n");
  }

}