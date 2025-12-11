#include <stdio.h>

#define Listsize 100
typedef struct{
  int data[Listsize];
  int length;
}SqList;

void InitList(SqList *L)//初始化
{
  L->length = 0;
}

int GetElem(SqList L, int i, int *e)
{
  if(i<1||i>L.length) return 0;
  *e = L.data[i-1];
  return 1;
}

int InsertList(SqList *L, int i, int e)
{
  int j;
  if(i<1||i>L->length+1){
    printf("插入位置i不合法！\n");
    return -1;
  }
  else if(L->length>=Listsize){
    printf("顺序表已满，不能插入元素。\n");
    return 0;
  }
  else{
    for(j=L->length;j>=i;j--) //将第i个位置以后的元素后移
      L->data[j]=L->data[j-1];
    L->data[i-1]=e; //插入元素到第i个位置
    L->length=L->length+1; //将顺序表长增1
    return 1;
  }
}

int LocElem(SqList L, int e)
{
  for(int i=0; i<L.length; i++){
    if(L.data[i]==e) return i+1;
  }
  return 0;
}

int Delete(SqList *L, int i, int *e){
  int j;
  if(L->length<=0){
    printf("erro");
    return 0;
  }
  else if(i<1||i>L->length){
    printf("erro");
    return -1;
  }
  else{
    *e = L->data[i-1];
    for(j=i; j<=L->length-1; j++){
      L->data[j-1]=L->data[j];
    }
    L->length = L->length-1;
    return 1;
  }
}

int main(){
  SqList a, b;
  InitList(&a);InitList(&b);

  //给a赋值
  for(int i=1; i<=10; i++){
    InsertList(&a, i, i+10);
  }
  //打印a
  printf("a: ");
  for(int i=1;i<=a.length;i++){
    int x;
    GetElem(a, i, &x);
    printf("%d ",x);
  }
  printf("\n");

  //给b赋值
  for(int j=2,i=1; j<=22; j+=4,i++){
    InsertList(&b, i, j);
  }

  printf("b: ");
  for(int i=1; i<=b.length; i++){
    int x;
    GetElem(b, i, &x); //取b的数
    printf("%d ",x);
    if (LocElem(a, x)){
      Delete(&a, LocElem(a, x),&x); //在a中删除
    }
  }
  printf("\n");
  printf("new_a: ");
  for(int i=1;i<=a.length;i++){
    int x;
    GetElem(a, i, &x);
    printf("%d ",x);
  }
  printf("\n");
}
 
