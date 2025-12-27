#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
typedef  int  KeyType;   
typedef  struct{
  KeyType key;//关键字
  //InfoType  otherinfo;   //其它数据项
}ElemType;               //记录类型
typedef struct BSTNode{
  ElemType data;
  struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

void Insert_BST(BSTree &T,ElemType e){//当二叉排序树中不存在关键字等于e.key的数据元素时，插入元素值为e的结点; 否则，不进行插入
	BSTNode *s;
	if(!T){
		s=new BSTNode;
		s->data=e;
		s->lchild=s->rchild=NULL;
		T=s;
	}
	if(T->data.key==e.key)return;
	else if(e.key<T->data.key)Insert_BST(T->lchild,e);
	else Insert_BST(T->rchild,e);
}//Insert_BST



BSTree SearchBST(BSTree T,KeyType kval){//在根指针T所指二叉排序树中递归地查找其关键字等于kval的数据元素，若查找成功，则返回指向该结点的指针，否则返回空指针
	if(!T)return T;//查找不成功
	if(kval==T->data.key)//查找成功
		return T;
	else if(kval<T->data.key)return SearchBST(T->lchild,kval);//在左子树中继续查找
	else return SearchBST(T->rchild,kval);//在右子树中继续查找
}//SearchBST


void DeleteBST(BSTree &T,KeyType kval){//删除二叉排序树中关键字等于kval的结点
	BSTree f=NULL,p,q,s;
	p=T;
	while(p!=NULL&&p->data.key!=kval){//找关键字等于kval的结点
		f=p;//用f记录结点p的父结点
		if(kval<p->data.key)p=p->lchild;//搜索左子树
		else p=p->rchild;//搜索右子树
	}
	if(p==NULL)return;//未找到删除的结点
	s=p;
	if(p->lchild&&p->rchild){//左、右子树都非空
		f=p;
		s=p->lchild;
		while(s->rchild){//找左子树最右边结点
			f=s;//用f指向s的父结点
			s=s->rchild;
		}
		p->data.key=s->data.key;//复制s的值
		//p->otherinfo=s->otherinfo;
	}
	if(s->lchild)//若s左子树不空，则右子树一定为空
		q=s->lchild;//用q指向左子树
	else q=s->rchild;//此时，左子树为空，用q指向右子树
	if(f==NULL)T=q;//要删除的为根结点
	else if(f->lchild==s)f->lchild=q;//结点s为双亲f的左孩子		    
	     else f->rchild=q;//结点s为双亲f的右孩子
	delete p;
}//DeleteBST

void InOrderTraverse(BSTree T){//中序遍历二叉树算法
	if(T){
		InOrderTraverse(T->lchild);//遍历左子树算法
		printf("%d ",T->data.key);//访问结点
		InOrderTraverse(T->rchild);//遍历右子树
	}
}


void main(){
	BSTree T;
	KeyType kval=35;
	ElemType e;
	int i;
	T=NULL;
	for(i=0;i<9;i++){
		scanf("%d",&e.key);
		Insert_BST(T,e);
	}
	InOrderTraverse(T);
	printf("\n");
	if(SearchBST(T,kval))printf("%d\n",SearchBST(T,kval)->data.key);
	else printf("no data\n");
	kval=95;
	if(SearchBST(T,kval))printf("%d\n",SearchBST(T,kval)->data.key);
	else printf("no data\n");
	kval=40;
	DeleteBST(T,kval);
	InOrderTraverse(T);
	printf("\n");
	kval=80;
	DeleteBST(T,kval);
	InOrderTraverse(T);
	printf("\n");
}
