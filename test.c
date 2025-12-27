#include <stdio.h>
struct test
{
 int data; /* data */
};

void change(struct test *x){
  (*x).data = 1;
}

int main(){
  struct test y;
  change(&y);
  y.data = 10;
  printf("%d",y.data);  
}