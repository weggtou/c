#include <stdio.h>

struct student
{
  int id;
  char name[20];
  float score;
};

void output(struct student*p){
  printf("学号\t姓名\t成绩\n");
  printf("%d\t%s\t%.2f",p->id,p->name,p->score);
}
int main(){
  struct student stu1 = {102,"张三强",78.5},*pstu = &stu1;
  output(pstu);
}