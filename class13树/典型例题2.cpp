#include<stdio.h>
#include<stdlib.h>
# define  OK 1
# define  OVERFLOW -1
# define  ERROR 0
# define  TRUE 1
# define  FALSE 0
int n;

typedef char ElemType;
typedef struct BiTNode{//结点结构
	ElemType data;//数据元素
	struct BiTNode *lchild,*rchild;//左右孩子指针
}BiTNode,*BiTree;


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

typedef BiTree LinkList;
LinkList head,pre=NULL;//全局变量
LinkList InOrder(BiTree T){
	if(T){
		InOrder(T->lchild);//中序遍历左子树
		if(T->lchild==NULL && T->rchild==NULL)//叶子结点
			if(pre==NULL){head=T;pre=T;}//处理第一个叶子结点
			else{pre->rchild=T;pre=T;}//将叶子结点链入链表
			InOrder(T->rchild);//中序遍历右子树
			pre->rchild=NULL;//设置链表尾
	}
	return head;
}


void main(){


	BiTree T;
	LinkList H,p;
	CreateBiTree(T);
	H=InOrder(T);
	for(p=H;p;p=p->rchild)printf("\%c",p->data);
	printf("\n");	
}
