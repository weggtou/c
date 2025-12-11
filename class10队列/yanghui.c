#include "queue.c"

int main(){
  int record[100000],n;
  scanf("%d",&n);
  queue a;
  Init(&a);
  Enqueue(&a,1);
  record [0] = 1;
  int k = 0;
  printf("%*s1\n",n," ");
  for(int i = 2;i<=n;i++){
    printf("%*s",n-i+1," ");
    Enqueue(&a,1);
    record [k+1] = 1;
    for(int j = 1;j<=i-2;j++){
      int x;
      QDelete(&a,&x);
      auto b = a.front->next;
      record [k+1+j] = x+b->data;
      Enqueue(&a,record[k+1+j]);
    }
    Enqueue(&a,1);
    record[k+i] = 1;
    int t;
    QDelete(&a,&t);
    for(int j = 0;j<i;j++){
      printf("%d ",record[++k]);
    }
    printf("\n");
  }
}