#include<stdio.h>
#include<stdlib.h>
# define  OK 1
# define  OVERFLOW -1
# define  ERROR 0
# define  TRUE 1
# define  FALSE 0

# define  Maxsize 100

typedef char ElemType;
typedef struct BiTNode{//结点结构
	ElemType data;//数据元素
	struct BiTNode *lchild,*rchild;//左右孩子指针
}BiTNode,*BiTree;


typedef struct{
	BiTree *base;
	BiTree *top;
}SqStack;

void InitStack(SqStack &S){
  //S.base=(BiTree*)malloc(20*sizeof(BiTree));
	S.base=new BiTree[Maxsize];
	if(!S.base)exit(-2);
	S.top=S.base;
}
void Push(SqStack &S,BiTree p){
	*S.top++=p;
}
void Pop(SqStack &S,BiTree &p){
	p=*--S.top;
}
int StackEmpty(SqStack S){
	if(S.top==S.base)return 1;
	return 0;
}
BiTree GetTop(SqStack S){
	return *(S.top-1);
}





void PreOrderTraverse(BiTree T){//先序遍历二叉树算法
	if(T){
		printf("%c",T->data);//访问结点
		PreOrderTraverse(T->lchild);//遍历左子树
		PreOrderTraverse(T->rchild);//遍历右子树
	}
}


void InOrderTraverse(BiTree T){//中序遍历二叉树算法
	if(T){
		InOrderTraverse(T->lchild);//遍历左子树算法
		printf("%c",T->data);//访问结点
		InOrderTraverse(T->rchild);//遍历右子树
	}
}


void PostOrderTraverse(BiTree T){//后序遍历二叉树算法
	if(T){
		PostOrderTraverse(T->lchild);//遍历左子树
		PostOrderTraverse(T->rchild);//遍历右子树
		printf("%c",T->data);//访问结点
	}
}

int CreateBiTree(BiTree &T){
	ElemType ch;
	scanf("%c",&ch);
	if(ch==' ')T=NULL;
	else{
		if(!(T=new BiTNode))exit(OVERFLOW);
		T->data=ch;//生成根结点
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
    }
	return OK;  
}//CreateBiTree



void PreOrder_Nonrecursive(BiTree T){//先序遍历的非递归算法
	SqStack S;
	BiTree p;
	InitStack(S);
	Push(S,T);//根指针进栈
	while(!StackEmpty(S)){
		while(GetTop(S)){
			printf("%c",GetTop(S)->data);//访问结点，向左一步
			Push(S,GetTop(S)->lchild);
		}//向左走到尽头
		Pop(S,p);//空指针出栈
		if(!StackEmpty(S)){//向右一步
			Pop(S,p);
			Push(S,p->rchild);
		}
	}//while
}//PreOrder_Nonrecursive



void InOrder_Nonrecursive(BiTree T){//中序遍历的非递归算法
	SqStack S;
	BiTree p;
	InitStack(S);
	Push(S,T);//根指针进栈
	while(!StackEmpty(S)){
		while(GetTop(S))Push(S,GetTop(S)->lchild);//向左走到尽头
		Pop(S,p);//空指针出栈
		if(!StackEmpty(S)){//访问结点，向右一步
			Pop(S,p);
			printf("%c",p->data);
			Push(S,p->rchild);
		}//if
	}//while
}//InOrder_Nonrecursive


int main(){
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	PreOrder_Nonrecursive(T);
	printf("\n");
	InOrder_Nonrecursive(T);
	printf("\n");
}
