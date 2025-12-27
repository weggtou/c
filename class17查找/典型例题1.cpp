#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
typedef  int  KeyType;   
typedef struct node{
	int A[5];//每个结点内含有5个正整数
	struct node *next;//指向下一个结点的指针
}Lnode,*LinkList;
typedef struct{
	int j;//正整数在结点内的序号
	struct node *s;//结点的指针
}Rcd;

void CreateH(LinkList &H){//创建单链表
	int i,j;
	node *p;
	H=new node;
	H->next=NULL;
	int m=7;//元素个数
	//scanf("%d",&m);
	for(i=0;i<m%5;i++){
		p=new node;
		for(j=0;j<5;j++)scanf("%d",&p->A[j]);
		p->next=H->next;
		H->next=p;
	}
}

void DispH(LinkList H){//创建单链表
	node *p;
	int i;
	p=H->next;
	while(p){
		printf("(");
		for(i=0;i<5;i++)printf("%d ",p->A[i]);
		printf(")");
		p=p->next;
	}
}

Rcd *Lsearch(LinkList H,int n){//在链表中查找正整数n，若查找成功，返回该结点指针及n在结点中的序号，否则返回空指针
	Rcd *R;
	R=new Rcd;
	node *p;
	int i;
	p=H->next;//指向单链表的第一个结点
	while(p){
		for(i=0;i<5;i++)
			if(p->A[i]==n){R->j=i;R->s=p;return R;}
			p=p->next;
	}
	return NULL;
}//LSearch


void main(){
	LinkList H;
	CreateH(H);
	DispH(H);
	Rcd *R;
	R=Lsearch(H,3);
	if(R)printf("\n%d,%d",R->j,R->s->A[R->j]);
	R=Lsearch(H,7);
	if(R)printf("\n%d,%d",R->j,R->s->A[R->j]);

}
