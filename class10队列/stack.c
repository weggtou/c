#include <stdio.h>
#include <stdlib.h>

typedef char Datatype;
typedef struct n{
  Datatype data;
  struct n* next;
}Snode,*stack;

void SInit(stack* a){
  *a = (Snode*)malloc(sizeof(Snode));
  (*a)->next = NULL;
}

int SEmpty(stack a){
  if(a->next==NULL){
    return 1;
  }else{
    return 0;
  }
}

void Spush(stack* a,Datatype e){
  stack x;
  SInit(&x);
  x->data = e;
  x->next = (*a)->next;
  (*a)->next = x;
}

int SPop(stack* a,Datatype* e){
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

int SGet(stack a,Datatype* e){
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
    Datatype t;
    SPop(a,&t);
  }
  free(a);
}
