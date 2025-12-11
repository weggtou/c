#include <stdio.h>

int main(){
  int a[]={5,15,25,35};
  int* num[] = {&a[0],&a[1],&a[2],&a[3]};
  int**p=num,max=0;
  double sum=0;
  for(int i = 0;i<4;i++,p++){
    printf("%d ",**p);
    sum+=**p;
    if(**p>max)max=**p;
  }
  printf("\n");
  printf("avg = %.2f\n",sum/4);
  printf("max = %d\n",max);
}