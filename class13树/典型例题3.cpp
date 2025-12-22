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

typedef struct PMType{
	BiTree ptr;
	int mark;//mark=0表示刚刚访问此结点，mark=1表示左子树处理结束返回，mark=2表示右子树处理结束返回。
}PMType; 


typedef struct{
	PMType *base;
	PMType *top;
}SqStack;

void InitStack(SqStack &S){
  //S.base=(BiTree*)malloc(20*sizeof(BiTree));
	S.base=new PMType[Maxsize];
	if(!S.base)exit(-2);
	S.top=S.base;
}
void Push(SqStack &S,PMType p){
	*S.top++=p;
}
void Pop(SqStack &S,PMType &p){
	p=*--S.top;
}
int StackEmpty(SqStack S){
	if(S.top==S.base)return 1;
	return 0;
}
PMType GetTop(SqStack S){
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








int NodeNumLevel(BiTree T,int k){//求二叉树第k层的结点数
	PMType a;
	SqStack S;
	InitStack(S);//S的元素为PMType类型
	int sum=0;
	if(!T||k<1)return 0;
	a.ptr=T;
	a.mark=0;	
	Push(S,a);
	if(S.top-S.base==k)sum++;
	while(!StackEmpty(S)){
		Pop(S,a);
		switch(a.mark){
		case 0:a.mark=1;Push(S,a);
			if(a.ptr->lchild) {a.ptr=a.ptr->lchild;a.mark=0;Push(S,a);if(S.top-S.base==k)sum++;}
			break;
		case 1:a.mark=2;Push(S,a); 
			if(a.ptr->rchild) {a.ptr=a.ptr->rchild;a.mark=0;Push(S,a);if(S.top-S.base==k)sum++;}
			break;
		case 2:break;
		}
	}//while
	return sum;
}


void main(){
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	for(int i=1;i<6;i++)printf("%d\n",NodeNumLevel(T,i));
}
