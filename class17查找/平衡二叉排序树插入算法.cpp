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
  int bf;//平衡因子
  struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

BSTree LL_Rotate(BSTree a){//对以a为根的二叉排序树作右旋处理，处理之后a指向新的树根结点，即旋转处理之前的左子树的根结点
	BSTree b;
	b=a->lchild;//b指向的a左子树根结点
	a->lchild=b->rchild;//lc的右子树挂接为p的左子树
	b->rchild=a;
	a->bf=0;
	b->bf=0;
	a=b;//p指向新的根结点
	return a;
}


BSTree RR_Rotate(BSTree a){//对以a为根的二叉排序树作左旋处理，处理之后a指向新的树根结点，即旋转处理之前的右子树的根结点
	BSTree b;
	b=a->rchild; //b指向的a右子树根结点
	a->rchild=b->lchild;//b的左子树挂接为a的右子树
	b->lchild=a;
	a->bf=0;
	b->bf=0;
	a=b;//a指向新的根结点
	return a;
}


BSTree LR_Rotate(BSTree a){
	BSTree b,c;
	b=a->lchild; //b指向的a左子树根结点
	c=b->rchild; //c指向的b右子树根结点
	a->lchild=c->rchild;
	b->rchild=c->lchild;
	c->lchild=b;
	c->rchild=a;
	if(c->bf==1){a->bf=-1;b->bf=0;}
	else if(c->bf==0)a->bf=b->bf=0;
	else{a->bf=0;b->bf=1;}
	c->bf=0;
	a=c;
	return a;
}



BSTree RL_Rotate(BSTree a){
	BSTree b,c;
	b=a->rchild;//b指向的a右子树根结点
	c=b->lchild; //c指向的b左子树根结点
	a->rchild=c->lchild;
	b->lchild=c->rchild;
	c->lchild=a;
	c->rchild=b;
	if(c->bf==1){a->bf=0;b->bf=-1;}
	else if(c->bf==0)a->bf=b->bf=0;
	else{a->bf=1;b->bf=0;}
	c->bf=0;
	a=c;
	return a;
}


void InsertAVL(BSTree &T, BSTree s){//在平衡二叉排序树T中插入结点s
	BSTree f,a,b,p,q;
	if(T==NULL){T=s;return;}
	a=p=T;//a记录离结点s最近的平衡因子不为0的结点
	f=q=NULL;//f指向a的父结点，q指向p的父结点
	while(p!=NULL){//查找插入位置
		if(s->data.key==p->data.key)return;//树中一存在关键字相同的结点，不必插入
		if(p->bf!=0){a=p;f=q;}//当前结点的平衡因子不等于0，记下平衡因子不等于0的结点
		q=p;
		if(s->data.key<p->data.key)p=p->lchild;//在左子树中搜索
		else p=p->rchild;//在右子树中搜索
	}//while
	if(s->data.key<q->data.key)q->lchild=s;//s插入为q的左孩子
	else q->rchild=s;//s插入为q的右孩子
	p=a;
	while(p!=s){//修改从a到s的所有结点的平衡因子
		if(s->data.key<p->data.key){p->bf++;p=p->lchild;}//若插入到左子树，则平衡因子加1
		else {p->bf--;p=p->rchild;}// 若插入到右子树，则平衡因子减1
	}
	if(a->bf>-2&&a->bf<2)return;//为失去平衡，不做调整
	if(a->bf==2){
		b=a->lchild;
		if(b->bf==1)p=LL_Rotate(a);//为LL型调整
		else p=LR_Rotate(a);//为LR型调整
	}
	else {
		b=a->rchild;
		if(b->bf==1)p=RL_Rotate(a);//为RL型调整
		else p=RR_Rotate(a);//为RR型调整
	}
	if(f==NULL)T=p;//a为根结点
	else if(f->lchild==a)f->lchild=p;//a为其双亲的左子树
	else f->rchild=p;//a为其双亲的右子树
}





void InOrderTraverse(BSTree T){//中序遍历二叉树算法
	if(T){
		InOrderTraverse(T->lchild);//遍历左子树算法
		printf("%d ",T->data.key);//访问结点
		InOrderTraverse(T->rchild);//遍历右子树
	}
}


void main(){
	BSTree T,s;
	T=NULL;
	for(int i=0;i<5;i++){
		s=new BSTNode;
		scanf("%d",&s->data.key);
		s->bf=0;
		s->lchild=NULL;
		s->rchild=NULL;		
		InsertAVL(T,s);
	}
	InOrderTraverse(T);
	printf("\n");
}
