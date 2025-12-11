#include <stdio.h>

struct student
{
  int id;
  char name[20];
  float chinese;
  float math;
};
int main(){
  struct student stu1= {1,"a",99,100},stu2;
  printf("id2:");
  scanf("%d",&stu2.id);
  printf("name:");
  scanf("%s",stu2.name);
  printf("chinese:");
  scanf("%f",&stu2.chinese);
  printf("math:");
  scanf("%f",&stu2.math);
  struct student a [2] = {stu1,stu2};
  for(int i =0;i<2;i++){
    float sum = a[i].math+a[i].chinese;
    printf("stu%d: %.2f\n",i+1,sum/2);
  }
}