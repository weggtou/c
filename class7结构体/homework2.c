#include <stdio.h>
struct Student
{
  int id;
  char name [20];
  float score;
};

int main(){
  struct Student stu[5];
  for(int i = 0;i<5;i++){
    printf("学生%d\n",i+1);
    printf("id:");
    scanf("%d",&stu[i].id);
    printf("name:");
    scanf("%s",stu[i].name);
    printf("score:");
    scanf("%f",&stu[i].score);
  }
  float pinjun=0;
  int cont=0,m;
  float max=0;
  for(int i = 0;i<5;i++){
    if(stu[i].score>max){
      m=i;max=stu[i].score;
    }
    pinjun+=stu[i].score;
    cont += (stu[i].score<60);
  }
  printf("全班平均成绩%f\n",pinjun/5);
  printf("不及格人数%d\n",cont);
  printf("成绩最高的学生\n");
  printf("id:%d name:%s score:%f",stu[m].id,stu[m].name,stu[m].score);
}