#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}ListNode,*LinkList;

void Init (LinkList *a){
  *a =(LinkList)malloc(sizeof(ListNode));
  (*a)->next = *a;
}

int ListEmpty(LinkList head){
  if(head->next==head){
    return 1;
  }else{
    return 0;
  }
}

int InsertList(LinkList head,int i,int e){
  ListNode *pre,*p;
  int j;
  pre = head;
  j=0;
  while(pre->next!=head&&j<i-1){
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
  while(pre->next!=head&&pre->next->next!=head&&j<i-1){
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

ListNode* Get(LinkList head,int i){
  ListNode*p;
  if(ListEmpty(head)){
    return NULL;
  }
  if(i<1)return NULL;
  p=head;
  int j=0;
  while(p->next!=head&&j<i){
    p=p->next;
    j++;
  }
  if(j==i){
    return p;
  }else{
    return NULL;
  }
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
  if(p==head){
    return 0;
  }
}

int main(){
  LinkList a,b;
  Init (&a);
  int n,k,m;
  scanf("%d",&n);
  scanf("%d",&k);
  scanf("%d",&m);
  for(int i = 1;i<=n;i++){
    InsertList(a,i,i);
  }
  b = Get(a,k);
  while(!ListEmpty(a)){
    for(int i = 1;i<=m-1;i++){
      if(b->next!=a){
        b=b->next;
      }else{
        b=b->next->next;
      }
    }
    int x;
    DeleteList(a,LocatePos(a,b->data),&x);
    printf("%d ",x);
    if(b->next!=a){
      b=b->next;
    }else{
      b=b->next->next;
    }
  }
  printf("\n");
}