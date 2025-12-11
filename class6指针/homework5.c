#include <stdio.h>
#include <string.h>
char *longestName(char *name[], int n);

int main(){
  char a[10000],b[10000],c[10000];
  printf("第一个:");
  scanf("%s",a);
  printf("第二个:");
  scanf("%s",b);
  printf("第三个:");
  scanf("%s",c);
  char*p[3] = {a,b,c};
  printf("名字最长的是:%s\n",longestName(p,3));
}
char *longestName(char *name[], int n){
  char*ans;
  int max=0;
  for(int i = 0;i<n;i++){
    int x = strlen(name[i]);
    if(x>max){ans=name[i];max=x;}
  }
  return ans;
}