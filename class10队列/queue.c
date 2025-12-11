#include <stdio.h>
#include <stdlib.h>

typedef char Datatype;
typedef struct Lb{
  Datatype data;
  struct Lb* next;
}Qnode ,*lb;

typedef struct {
  lb front;
  lb end;
}queue;

void Init(queue* a){
  lb x = (lb)malloc(sizeof(Qnode));
  x->next=NULL;
  a->front = x;
  a->end = x;
}

int QEmpty(queue a){
  if(a.front == a.end){
    return 1;
  }else{
    return 0;
  }
}

void Enqueue(queue* a,Datatype e){
  Qnode* x = (Qnode*)malloc(sizeof(Qnode));
  x->data = e;
  x->next = NULL;
  a->end->next = x;
  a->end = x;
}

//删除
Datatype QDelete(queue* a,Datatype* e){
  if(QEmpty(*a)){
    return 0;
  }else{
    Qnode* x = a->front->next;//注意，头指针指向的地址是head，所以第一个值是front->next
    a->front->next = x->next;
    *e = x->data;
    //判断要删除的位置是不是尾指针指向的，如果是要将尾指针指向头，因为删完之后就没有元素了
    //而且如果不改尾指针，那尾指针就变成野指针了;
    if(a->end == x)a->end = a->front;
    free(x);
    return *e;
  }
}

//取
int GetHead(queue a,Datatype* e){
  Qnode* x = a.front->next;
  if(x!=NULL){
    *e = x->data;
    return 1;
  }else{
    return 0;
  }
}

void QClear(queue* a){
  while(!QEmpty(*a)){
    Datatype e;
    QDelete(a,&e);
  }
}