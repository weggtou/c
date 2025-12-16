#include<stdio.h>
#include<stdlib.h>
# define  OK 1
# define  OVERFLOW -1
# define  ERROR 0
# define  TRUE 1
# define  FALSE 0

typedef char ElemType;

typedef struct Node{//结点结构
	ElemType data;
	struct Node  *firstchild, *nextsibling;//孩子及兄弟域
}Node, *Forest;


void PreOrderTraverse(Forest T){//孩子兄弟链表森林的先序遍历算法
	if(T){
		printf("%c",T->data);//访问结点
		PreOrderTraverse(T->firstchild);//依次先根遍历各棵树
		PreOrderTraverse(T->nextsibling);
		
	}
}

void PostOrderTraverse(Forest T){//孩子兄弟链表森林的中序遍历算法
	if(T){
		PostOrderTraverse(T->firstchild);//后根遍历第一棵棵树
		printf("%c",T->data);//访问结点
		PostOrderTraverse(T->nextsibling);//后根遍历其它树
	}
}


int CreateForest(Forest &T){//孩子兄弟链表森林的构建
	ElemType ch;
	scanf("%c",&ch);
	if(ch==' ')T=NULL;
	else{
		if(!(T=new Node))exit(OVERFLOW);
		T->data=ch;//生成根结点
		CreateForest(T->firstchild);//依次构建各棵树	
		CreateForest(T->nextsibling);
    }
	return OK;  
}//CreateBiTree


int ForestLeaves(Forest T){
	if(!T)return 0;
	else if(!T->firstchild)//若结点无孩子，则该结点必是叶子结点
		return(1+ForestLeaves(T->nextsibling));//返回叶子结点和其它兄弟子树中的叶子结点数
	else return(ForestLeaves(T->firstchild)+ForestLeaves(T->nextsibling));//孩子子树和兄弟子树中的叶子结点数之和
}




void main(){
	Forest T;
	CreateForest(T);
	PreOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	printf("森林的叶子数：%d\n",ForestLeaves(T));
}
