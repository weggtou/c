#include <stdio.h>
#include <stdlib.h>

typedef struct BITnode{
  int data;
  struct BITnode *Lchild,*Rchild;
}BITnode, *BITree;

/*生成二叉排序树*/
void PutNum(BITree *T, int n){
  if(*T == NULL){
    *T = (BITree)malloc(sizeof(BITnode));
    if(*T == NULL){ // 添加内存分配失败防护
      perror("malloc failed");
      exit(EXIT_FAILURE);
    }
    (*T) -> data = n;
    (*T) -> Lchild = NULL;
    (*T) -> Rchild = NULL;
    return;
  }
  if(n==(*T)->data){
    return;
  }else if(n < (*T)->data){
    PutNum(&((*T)->Lchild),n);
  }else{
    PutNum(&((*T)->Rchild),n);
  }
}
 
/*中序遍历*/
void inorder(BITree T){
  if(T != NULL){
    inorder(T->Lchild);
    printf("%d ",T->data);
    inorder(T->Rchild);
  }
}

/*查找元素*/
void SearchElem(BITree T, int n){
  int find = 0;
  if(find == 0 && T != NULL){
    if(n<T->data){
      printf("0");
      SearchElem(T->Lchild, n);
    }
    else if(n>T->data){
      printf("1");
      SearchElem(T->Rchild, n);
    }
    else{
      printf("\n"); find = 1;
    }
  }
}
/*删除元素*/
void Delete(BITree* T, int n){
  BITree record;
  /*目标节点没有左右孩子*/
  if((*T)->Lchild == NULL && (*T)->Rchild == NULL){
    free(*T);
    *T = NULL;
  }
  /*目标节点只有右孩子*/
  else if((*T)->Lchild == NULL && (*T)->Rchild != NULL){
    record = *T;
    *T = (*T)->Rchild;
    free(record);
  } 
  /*目标节点只有左孩子*/
  else if((*T)->Lchild != NULL && (*T)->Rchild == NULL){
    record = *T;
    *T = (*T)->Lchild;
    free(record);
  }
  /*目标节点有左孩子和右孩子*/
  else{
    BITree x = NULL;
    record = *T;
    *T = (*T)->Lchild;
    x = *T;
    while(x->Rchild){
      x = x->Rchild;
    }
    x->Rchild = record->Rchild;
    free(record);
  }
}

int DeleteElem(BITree* T,int n){
  if(!(*T)){
    return 0;
  }else{
    if((*T)->data>n){
      return DeleteElem(&((*T)->Lchild),n);
    }else if((*T)->data<n){
      return DeleteElem(&((*T)->Rchild),n);
    }else{
      Delete(T,n);//传入的是结构体内左孩子右孩子这个的地址，
      //解指针后直接改变的就是左孩子右孩子
      return 1;
    }
  }
}

/*释放二叉搜索树内存*/
void FreeBITree(BITree T){
  if(T != NULL){
    FreeBITree(T->Lchild);
    FreeBITree(T->Rchild);
    free(T);
  }
}

int main(){
  BITree T = NULL;
  int Elems[9]={37,32,35,62,82,95,73,12,5};
  for(int i=0; i<9; i++){
    PutNum(&T,Elems[i]);
  }
  printf("已生成二叉排序树\n");
  printf("中序输出：");inorder(T);
  printf("\n");
  int n; printf("查找的数据："); scanf("%d",&n);
  printf("%d的位置(0代表左,1代表右):",n);
  SearchElem(T,n);
  int val; printf("删除的数据：");scanf("%d",&val);
  DeleteElem(&T,val);
  printf("中序输出：");inorder(T);

  FreeBITree(T);
}