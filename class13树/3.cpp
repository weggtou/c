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




typedef struct QNode {// 结点类型
	BiTree  data;
	struct QNode  *next;
}Qnode,*QueuePtr;
typedef struct{//链队列类型
	QueuePtr  front;// 队头指针
	QueuePtr  rear;// 队尾指针
}LinkQueue;

int InitQueue(LinkQueue &Q){//构造一个空队列Q
	Q.front=Q.rear=new Qnode;
	if(!Q.front)exit(OVERFLOW);//存储分配失败
	Q.front->next=NULL;
	return OK;
}

int DestryQueue(LinkQueue &Q){//销毁队列Q
	while(Q.front){
		Q.rear=Q.front->next;
		delete(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

int EnQueue(LinkQueue &Q,BiTree e){//插入元素e为Q的新的队尾元素
	Qnode *p;
	p=new Qnode;
	if(!p)exit(OVERFLOW);//存储分配失败
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	return OK;
}

int DeQueue(LinkQueue &Q,BiTree &e){//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
	Qnode *p;
	if(Q.front==Q.rear)return ERROR;//空队列
	p=Q.front->next;
	e=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)Q.rear=Q.front;//当删除的是队列中最后一个元素时，需对尾指针进行重新赋值(指向头结点)
	delete(p);
	return OK;
}
int QueueEmpty(LinkQueue Q){
	if(Q.front->next)return 0;
	else return 1;
}


void LayerOrder(BiTree T){//层序遍历二叉树
	LinkQueue Q;
	InitQueue(Q);//队列初始化
	EnQueue(Q,T);//根结点入队
	BiTree p;
	while(!QueueEmpty(Q)){
		DeQueue(Q,p);
		printf("%c",p->data);
		if(p->lchild) EnQueue(Q,p->lchild);
		if(p->rchild) EnQueue(Q,p->rchild);
	}
}//LayerOrder


int main(){
	BiTree T;
	CreateBiTree(T);
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	LayerOrder(T);
	printf("\n");
}
