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

void CountLeaf(BiTree T,int &count){
	if(T){
      if((!T->lchild)&& (!T->rchild))count++;  //对叶子结点计数
      CountLeaf(T->lchild, count);
      CountLeaf(T->rchild, count); 
   }//if
}//CountLeaf
int CountLeaf(BiTree T){//返回指针T所指二叉树中所有叶子结点个数
	int n,m;
	if (!T)return 0;
	if(!T->lchild && !T->rchild)return 1;
	else{
		m=CountLeaf(T->lchild);
		n=CountLeaf(T->rchild);
		return(m+n);
	}//else
}// CountLeaf


int Depth(BiTree T){//返回二叉树的深度
	int depthLeft,depthRight,depthval;
	if(!T)depthval=0;
	else{
		depthLeft=Depth(T->lchild);
		depthRight=Depth(T->rchild);
		depthval=(depthLeft>depthRight?depthLeft:depthRight)+1;
	}
	return depthval;
}
void Depth(BiTree T,int level,int &dval){
	if(T){
		if(level>dval)dval=level;
		Depth(T->lchild,level+1,dval);
		Depth(T->rchild,level+1,dval);
	} 
}//调用之前level的初值为1，dval的初值为0。



int Preorder(BiTree T,ElemType x,BiTree &p){//若二叉树中存在和x相同的元素，则p指向该结点并返回OK，否则p=NULL且返回FALSE
	if(T){
		if(T->data==x){
			p=T;
			return OK;
		}
		else{
			if(Preorder(T->lchild,x,p))return OK;
			else return(Preorder(T->rchild,x,p));
		}//else
	}//if 
	else{
		p=NULL; 
		return FALSE;
	}
}



BiTNode *GetTreeNode(ElemType item,BiTNode *lptr,BiTNode *rptr){
	BiTNode *T;
	if(!(T=new BiTNode))exit(OVERFLOW);
	T->data=item;
	T->lchild=lptr;T->rchild=rptr;
	return T;
}
BiTNode *CopyTree(BiTNode *T){
	BiTNode *newlptr,*newrptr,*newT;
	if(!T )return NULL;
	if(T->lchild )newlptr=CopyTree(T->lchild); //复制左子树
	else  newlptr=NULL;
	if(T->rchild)newrptr=CopyTree(T->rchild); //复制右子树
	else  newrptr=NULL;
	newT=GetTreeNode(T->data, newlptr, newrptr);
	return newT;
}//CopyTree





int main(){
	BiTree T,p,S;
	ElemType x;
	CreateBiTree(T);
	PreOrderTraverse(T);
	printf("\n");
	InOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	int count=0;
	CountLeaf(T,count);
	printf("树叶数：%d\n",count);
	printf("树叶数：%d\n",CountLeaf(T));
	printf("树深：%d\n",Depth(T));
	int level=1,dval=0;
	Depth(T,level,dval);
	printf("树深：%d\n",dval);
	x='c';

	if(Preorder(T,x,p))printf("结点存在：%c\n",p->data);
	else printf("该结点不存在\n");
	S=CopyTree(T);
	PreOrderTraverse(S);
	printf("\n");

}
