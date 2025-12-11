#include <stdio.h>
int main(){
  int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  for(int i = 1;i<=12;i++){
    day[i] = day[i]+day[i-1];
  }
  int m1,m2,d1,d2,ans;
  printf("Enter the first date (mm/dd): ");
  scanf("%d/%d",&m1,&d1);
  printf("Enter the second date (mm/dd): ");
  scanf("%d/%d",&m2,&d2);
  ans = day[m2-1]-day[m1-1]+d2-d1;
  printf("The interval between the two dates is %d days",ans);

}