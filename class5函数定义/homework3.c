#include <stdio.h>
double average(int a[],int n);
int contPass(int a[],int n);
int maxScore(int a[],int n);
int minScore(int a[],int n);

int main(){
  int n,a[100];
  printf("请输入学生人数: ");
  scanf("%d",&n);
  printf("请输入%d个总成绩:\n",n);

  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("平均分:%.2lf\n",average(a,n));
  printf("及格人数:%d\n",contPass(a,n));
  printf("不及格人数:%d\n",n-contPass(a,n));
  printf("最高分:%d\n",maxScore(a,n));
  printf("最低分:%d\n",minScore(a,n));
}

double average(int a[],int n){
  double sum = 0;
  for(int i = 0;i<n;i++){
    sum+=a[i];
  }
  return sum/n;
}

int contPass(int a[],int n){
  int cont = 0;
  for(int i = 0;i<n;i++){
    cont += (a[i]>=60);
  }
  return cont;
}

int maxScore(int a[],int n){
  int m=a[0];
  for(int i=1;i<n;i++){
    if(a[i]>m)m=a[i];
  }
  return m;
}

int minScore(int a[],int n){
  int m = a[0];
  for(int i =1;i<n;i++){
    if(a[i]<m)m=a[i];
  }
  return m;
}