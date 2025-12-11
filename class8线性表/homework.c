#include <stdio.h>
#define Listsize 100

typedef struct{
  int all[Listsize];
  int length;
}list;

void InitList(list *L){
  L->length = 0;
}

int GetElem(list L, int i, int *e){
  if(i<1||i>L.length) return 0;
  *e = L.all[i-1];
  return 1;
}

int InsertList(list *L,int i,int e){
  if(i<1||i>L->length+1){
    printf("位置不合法");
    return 0;
  }else if(L->length>=Listsize){
    printf("已满");
    return -1;
  }else{
    for(int j = L->length;j>=i;j--){
      L->all[j]=L->all[j-1];
    }
    L->all[i-1]=e;
    L->length+=1;
    return 1;
  }
}

int LocElem (list L,int e){
  for(int i = 1;i<=L.length;i++){
    if(L.all[i-1]==e)return i;
  }
  return 0;
}

int Delete(list *L,int i,int *e){
  if(L->length<=0){
    printf("已空");
    return -1;
  }else if(i<1||i>L->length){
    printf("不合法");
    return 0;
  }else{
    *e = L->all[i-1];
    for(int j = i;j<L->length;j++){
      L->all[j-1]=L->all[j];
    }
    L->length-=1;
    return 1;
  }
}

int main(){
  int x[] = {-12,3,-6,-10,20,-7,9,-20};
  list a;
  InitList(&a);
  printf("顺序表L中的元素:\n");
  for(int i = 0;i<8;i++){
    InsertList(&a,i+1,x[i]);
    printf("%d ",x[i]);
  }
  printf("\n");
  int L,R,Lf=0,Rf=0;
  GetElem(a,1,&L);
  GetElem(a,a.length,&R);
  for(int i = 1,j=a.length;i<j;){
    if(L<=0&&!Lf){
      i++;
      GetElem(a,i,&L);
    }else if(L>0&&!Lf){
      Lf=1;
    }
    if(R>0&&!Rf){
      j--;
      GetElem(a,j,&R);
    }else if(R<=0&&!Rf){
      Rf=1;
    }
    if(Rf&&Lf){
      Delete(&a,i,&L);
      InsertList(&a,i,R);
      Delete(&a,j,&R);
      InsertList(&a,j,L);
      Rf=Lf=0;
      i++;j--;
      GetElem(a,i,&L);GetElem(a,j,&R);
    }
  }
  printf("顺序表调整后:\n");
  for(int i = 1;i<=a.length;i++){
    int x;
    GetElem(a,i,&x);
    printf("%d ",x);
  }
  printf("\n");
}