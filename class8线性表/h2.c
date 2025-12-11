#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
  int data;
  struct Node *next;
}ListNode,*LinkList;

void InitList(LinkList *head){
  *head=(LinkList)malloc(sizeof(ListNode));
  (*head)->next = NULL;
}

int ListEmpty(LinkList head){
  if(head->next==NULL){
    return 1;
  }else{
    return 0;
  }
}

ListNode* Get(LinkList head,int i){
  ListNode*p;
  if(ListEmpty(head)){
    return NULL;
  }
  if(i<1)return NULL;
  p=head;
  int j=0;
  while(p->next!=NULL&&j<i){
    p=p->next;
    j++;
  }
  if(j==i){
    return p;
  }else{
    return NULL;
  }
}

ListNode* LocateElem(LinkList head,int e){
  ListNode*p;
  p=head->next;
  while(p){
    if(p->data!=e){
      p=p->next;
    }else{
      break;
    }
  }
  return p;
}

int LocatePos(LinkList head,int e){
  ListNode *p;
  int i;
  if(ListEmpty(head)){
    return 0;
  }
  p=head->next;
  i=1;
  while(p){
    if(p->data==e){
      return i;
    }else{
      p=p->next;
      i++;
    }
  }
  if(!p){
    return 0;
  }
}

int InsertList(LinkList head,int i,int e){
  ListNode *pre,*p;
  int j;
  pre = head;
  j=0;
  while(pre->next!=NULL&&j<i-1){
    pre=pre->next;
    j++;
  }
  if(j!=i-1){
    printf("插入位置错误");
    return 0;
  }
  p=(ListNode*)malloc(sizeof(ListNode));
  p->data=e;
  p->next=pre->next;
  pre->next = p;
  return 1;
}

int DeleteList(LinkList head,int i,int*e){
  ListNode*pre,*p;
  int j;
  pre=head;
  j=0;
  while(pre->next!=NULL&&pre->next->next!=NULL&&j<i-1){
    pre=pre->next;
    j++;
  }
  if(j!=i-1){
    printf("删除位置有误");
    return 0;
  }
  p=pre->next;
  *e=p->data;
  pre->next=p->next;
  free(p);
  return 1;
}

int ListLength(LinkList head){
  ListNode* p;
  int cont =0;
  p=head;
  while(p->next!=NULL){
    p=p->next;
    cont++;
  }
  return cont;
}

int main(){
  LinkList a,b;
  InitList(&a);
  InitList(&b);
  for(int i = 1;i<=10;i++){
    InsertList(a,i,i+10);
  }
  printf("A:\n");
  for(int i = 1;i<=ListLength(a);i++){
    int x =Get(a,i)->data;
    printf("%d ",x);
  }
  printf("\n");
  for(int i=1,j=2;j<=22;i++,j+=4){
    InsertList(b,i,j);
  }
  printf("B:\n");
  for(int i = 1;i<=ListLength(b);i++){
    int x =Get(b,i)->data;
    printf("%d ",x);
  }
  printf("\n");
  for(int i = 1;i<=ListLength(b);i++){
    int x = LocatePos(a,Get(b,i)->data);
    if(x){
      int y;
      DeleteList(a,x,&y);
    }
  }
  printf("A-B:\n");
  for(int i = 1;i<=ListLength(a);i++){
    int x =Get(a,i)->data;
    printf("%d ",x);
  }
  printf("\n");
}