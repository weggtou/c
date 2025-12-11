#include "stdio.h"
int main(){
  double a = 3.1415926;
  int b = 1234;
  printf("%-12.3lf\n",a);
  printf("%10.5lf\n",a);
  printf("%-8d\n",b);
  printf("%06d\n",b);
  printf("%-15s\n","HelloWorld");
  printf("%-10.5s\n","HelloWorld");
}