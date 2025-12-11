#include <stdio.h>
#include <math.h>
double jiechen(int k){
  double ans=1;
  for(int i = 1;i<=k;i++){
    ans*=i;
  }
  return ans;
}

double xishu(int k,double a){
  if(k==0)return 1;
  double fenzi = 1;
  for(int i = 0;i<=k-1;i++){
    fenzi*=a-i;
  }
  return fenzi/jiechen(k);
}

int main(){
  double x,ans=0;
  int n;
  printf ("Enter x (-1<x<=1): ");
  scanf("%lf",&x);
  printf("Enter number of terms n: ");
  scanf("%d",&n);
  for(int k=0;k<=n;k++){
    ans+= xishu(k,0.5)*pow(x,k);
  }
  printf("The estimated sqrt(1+x) is :%lf",ans);
}