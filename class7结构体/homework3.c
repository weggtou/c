#include <stdio.h>
struct Department
{
  int dep_id;
  char name[20];  
  float revenue;  
};
void output(struct Department *p[], int n);
int main(){
  struct Department dep[4]={
    {1,"a",100000},{2,"b",20000},{3,"c",3000},{4,"d",1219932}
  };
  struct Department* pdep [4] = {&dep[0],&dep[1],&dep[2],&dep[3]};
  output(pdep,4);
}
void output(struct Department *p[], int n){
  for(int i = 0;i<n;i++){
    printf("id:%d name:%s revenue:%f\n",p[i]->dep_id,p[i]->name,p[i]->revenue);
  }
}