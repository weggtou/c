#include <stdio.h>
#define Maxsize 100000
int jiechen(int n){
  int s[Maxsize][2],top=0;
  s[top][0] = n;
  s[top][1] = 0;
  do{
    if(s[top][0]==1){
      s[top][1]=1;
    }
    if(s[top][1]!=0&&top>0){
      top--;
      s[top][1]=s[top][0]*s[top+1][1];
    }else if(s[top][1]==0){
      top++;
      s[top][0] = s[top-1][0]-1;
      s[top][1] = 0; 
    }
  }while(top>0);
  return s[0][1];
}
int main(){
  int n;
  scanf("%d",&n);
  printf("%d",jiechen(n));
}