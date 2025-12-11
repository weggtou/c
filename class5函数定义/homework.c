#include <stdio.h>
#define N 5

void MPSort(int b[],int n);

int main(){
  int a[N],i;
  for(i = 0;i<N;i++){
    scanf("%d",&a[i]);
  }
  for(i = 0;i<N;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  MPSort(a,N);
  for(i = 0;i<N;i++){
    printf("%d ",a[i]);
  }
}

void MPSort(int a[],int b){
  for(int i = 0;i<b-1;i++){
    for(int g = 0;g<b-1-i;g++){
      int t =a[g];
      if(a[g]>a[g+1]){
        a[g] = a[g+1];
        a[g+1] = t;
      }
    }
  }
}