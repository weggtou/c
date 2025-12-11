#include <stdio.h>
#include <stdlib.h>

typedef char DT;
typedef struct n{
  int data;
  struct n* next;
}node,*stack;

void SInit(stack* a){
  *a = (node*)malloc(sizeof(node));
  (*a)->next = NULL;
}

int SEmpty(stack a){
  if(a->next==NULL){
    return 1;
  }else{
    return 0;
  }
}

void Spush(stack* a,DT e){
  stack x;
  SInit(&x);
  x->next = (*a)->next->next;
  (*a)->next = x;
  x->data = e;
}

int SPop(stack* a,DT* e){
  if(!SEmpty(*a)){
    auto x = (*a)->next;
    *e = x->data;
    (*a)->next = x->next;
    free(x);
    return 1;
  }else{
    return 0;
  }
}

int SGet(stack a,DT* e){
  if(!SEmpty(a)){
    auto x = a->next;
    *e = x-> data;
    return 1;
  }else{
    return 0;
  }
}

int SLength(stack a){
  int i = 0;
  auto x = a;
  for(;x->next;i++){
    x = x->next;
  }
  return i;
}

void SDelet(stack *a){
  for(int i = 1;i<= SLength(*a);i++){
    int t;
    SPop(a,&t);
  }
  free(a);
}
