#include<stdio.h>
#include<stdlib.h>
# define  OK 1
# define  OVERFLOW -1
# define  ERROR 0
# define  TRUE 1
# define  FALSE 0

typedef char ElemType;

typedef struct BiThrNode{//结点结构
   ElemType data;//数据元素
   struct BiThrNode  *lchild, *rchild;//左右指针
   int LTag, RTag;//左右标志
}BiThrNode, *BiThrTree;

BiThrTree pre;

int CreateBiTree(BiThrTree &T){
	ElemType ch;
	scanf("%c",&ch);
	if(ch==' ')T=NULL;
	else{
		if(!(T=new BiThrNode))exit(OVERFLOW);
		T->data=ch;//生成根结点
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
    }
	return OK;  
}//CreateBiTree


void InThreading(BiThrTree p){//对以p为根的非空二叉树进行线索化
	if(p){
		InThreading(p->lchild);//左子树线索化
		if(!p->lchild){//建前驱线索
			p->LTag=1; 
			p->lchild=pre;
		}
		else p->LTag=0;////////
		if(!pre->rchild){//建后继线索
			pre->RTag=1;
			pre->rchild=p;
		}
		else pre->RTag=0;////////
		pre=p;//保持pre指向p的前驱
		InThreading(p->rchild);//右子树线索化
	}//if
}//InThreading
int InOrderThreading(BiThrTree &Thrt, BiThrTree T){//构建中序线索链表
	if(!(Thrt=new BiThrNode))exit(OVERFLOW);
	Thrt->LTag=0;Thrt->RTag=1;//建头结点
	Thrt->rchild=Thrt;//右指针回指
	if(!T)Thrt->lchild=Thrt;//若二叉树为空，左指针回指
	else{
		Thrt->lchild=T;
		pre=Thrt;
		InThreading(T);//中序遍历进行中序线索化
		pre->rchild=Thrt;pre->RTag=1;//最后一个结点线索化
		Thrt->rchild=pre;
	}
	return OK;
}//InOrderThreading

void InOrderTraverse_Thr(BiThrTree T){
	BiThrTree p;
	p=T->lchild;//p指向根结点
	while(p!=T){//空树或遍历结束时，p==T
		while(p->LTag==0)p=p->lchild;//第一个结点
        printf("%c",p->data);//访问左子树为空的结点
		while(p->RTag==1 && p->rchild!=T){
			p=p->rchild; 
			printf("%c",p->data);//访问后继结点
		}
		p=p->rchild;//p进至其右子树根
	}
}//InOrderTraverse_Thr


void main(){
	BiThrTree T,Thrt;
	CreateBiTree(T);
	InOrderThreading(Thrt,T);
	InOrderTraverse_Thr(Thrt);
	printf("\n");
}
