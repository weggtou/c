#include <stdio.h>

int main(){
  int a[10];
  for(int i =0;i<10;i++){
    scanf("%d",&a[i]);
  }

  int c1=0,c2=0,c3=0;
  for(int i =0;i<10;i++){
    if(a[i]>0){
      c1++;
    }else if(a[i]<0){
      c2++;
    }else{
      c3++;
    }
  }

  printf("正数个数 %d\n",c1);
  printf("负数个数 %d\n",c2);
  printf("零的个数 %d\n",c3);
}