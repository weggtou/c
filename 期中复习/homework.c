#include <stdio.h>
#include <math.h>
double jiechen(int x){
  if(x==0)return 1;
  double ans=1;
  for(int i = 1;i<=x;i++){
    ans*=i;
  }
  return ans;
}
int main(){
  double x,ans=0;
  double n;
  printf("Enter x(in radians): ");
  scanf("%lf",&x);
  printf("Enter number of terms n: ");
  scanf("%lf",&n);
  for(int i = 0;i<=n;i++){
    ans+=pow(-1,i)*pow(x,2*i)/jiechen(2*i);
  }
  
  printf("The estimated cosine value is : %.5lf",ans);
}