#include "queue.c"
#include "stack.c"
int main(){
  stack a;queue b;
  SInit(&a);Init(&b);
  char x[100];
  scanf("%s",x);
  for(int i = 0;x[i]!='\0';i++){
    Spush(&a,x[i]);
    Enqueue(&b,x[i]);
  }
  while(!SEmpty(a)&&!QEmpty(b)){
    char A,B;
    SPop(&a,&A);
    QDelete(&b,&B);
    if(A!=B){
      printf("不是回文\n");
      return 0;
    }
  }
  printf("是回文\n");
}