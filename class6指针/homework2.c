#include <stdio.h>

void sort(int* p);
int main(){
  int a[5];
  for(int* p = a;p<a+5;p++){
    scanf("%d",p);
  }
  sort(a);
  for(int* p = a;p<a+5;p++){
    printf("%d ",*p);
  }
}

void sort(int* p){
  for(int i=1;i<=4;i++){
    for(int g = 0;g<5-i;g++){
      if(*(p+g)>*(p+g+1)){
        int t = *(p+g);
        *(p+g) = *(p+g+1);
        *(p+g+1) = t;
      }
    }
  }
}