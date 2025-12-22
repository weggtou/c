#include<stdio.h>
#include<stdlib.h>
# define  OK 1
# define  OVERFLOW -1
# define  ERROR 0
# define  TRUE 1
# define  FALSE 0

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

BiTree Build_T1(char *Pre,char *In,int n){//先序序列和中序序列已分别存在数组Pre和In中，n为二叉树的结点数，由先序序列和中序序列建立其二叉链表
	BiTNode *sroot;
	char *P;
	int k;
	if(n<=0)return NULL;
	sroot=new BiTNode;//建根结点
	sroot->data=*Pre;
	for(P=In;P<In+n;P++)//在In中查找等于*Pre的位置
		if(*P==*Pre)//Pre指向根结点
			break;//在In中找到后推出循环
	k=P-In;//确定根结点在In中的位置
	sroot->lchild=Build_T1(Pre+1,In,k);//递归地建左子树
	sroot->rchild=Build_T1(Pre+k+1,P+1,n-k-1);// 递归地建右子树
	return sroot;//返回根指针
}//Build_T1


BiTree Build_T2(char *Post,char *In,int n){//先序序列和中序序列已分别存在数组Pre和In中，n为二叉树的结点数，由先序序列和中序序列建立其二叉链表
	BiTNode *sroot;
	char *P;
	char r;
	int k;
	if(n<=0)return NULL;
	r=*(Post+n-1);//根结点
	sroot=new BiTNode;//建根结点
	sroot->data=r;
	for(P=In;P<In+n;P++)//在In中查找根结点
		if(*P==r)break;
	k=P-In;//确定根结点在In中的位置
	sroot->lchild=Build_T2(Post,In,k);//递归地建左子树
	sroot->rchild=Build_T2(Post+k,P+1,n-k-1);//递归地建右子树
	return sroot;//返回根指针
}//Build_T2



int main(){
	BiTree T,S;
//	CreateBiTree(T);
//	PreOrderTraverse(T);
//	printf("\n");
//	InOrderTraverse(T);
//	printf("\n");
//	PostOrderTraverse(T);
//	printf("\n");
	char *Pre="abcdef",*In="bcadfe",*Post="cbfeda";
	int n=6;
	T=Build_T1(Pre,In,n);
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	S=Build_T2(Post,In,n);
	PreOrderTraverse(S);
	printf("\n");
	InOrderTraverse(S);
	printf("\n");
	PostOrderTraverse(S);
	printf("\n");
	
}
