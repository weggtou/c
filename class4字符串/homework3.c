#include <stdio.h>

int main(){
  char all [51];
  gets(all);
  int c1=0,c2=0,c3=0;
  for(int i = 0;;i++){
    if(all[i]==0)break;
    else if((all[i]>=65&&all[i]<=90)||(all[i]>=97&&all[i]<=122)){
      c1++;
    }else if(all[i]>=48&&all[i]<=57){
      c2++;
    }else{
      c3++;
    }
  }

  printf("字母个数: %d\n",c1);
  printf("数字个数: %d\n",c2);
  printf("其他字符个数: %d\n",c3);
}