#include<stdio.h>
#include<stdlib.h>
# define  OK 1
# define  OVERFLOW -1
# define  ERROR 0
# define  TRUE 1
# define  FALSE 0

typedef char ElemType;

typedef struct CSNode{//结点结构
	ElemType data;
	struct CSNode  *firstchild, *nextsibling;//分别指向结点的第一个孩子结点和下一个兄弟结点
}CSNode, *CSTree;


void PreOrderTraverse(CSTree T){//孩子兄弟链表树的先根遍历算法
	if(T){
		printf("%c",T->data);//访问结点
		PreOrderTraverse(T->firstchild);//依次先根遍历各棵子树
		PreOrderTraverse(T->nextsibling);
		
	}
}

void PostOrderTraverse(CSTree T){//孩子兄弟链表树的后根遍历算法
	if(T){
		PostOrderTraverse(T->firstchild);//后根遍历第一棵棵子树
		printf("%c",T->data);//访问结点
		PostOrderTraverse(T->nextsibling);//后根遍历其它子树
	}
}


int CreateCSTree(CSTree &T){//孩子兄弟链表树的构建
	ElemType ch;
	scanf("%c",&ch);
	if(ch==' ')T=NULL;
	else{
		if(!(T=new CSNode))exit(OVERFLOW);
		T->data=ch;//生成根结点
		CreateCSTree(T->firstchild);//依次构建各棵子树	
		CreateCSTree(T->nextsibling);
    }
	return OK;  
}//CreateBiTree


int GetDepth_CSTree(CSTree T){//求孩子兄弟链表表示的树T的深度
	int max,d;
	CSTree p;
	if(!T) return 0; //空树
	else{
		for(max=0,p=T->firstchild;p;p=p->nextsibling)
			if((d=GetDepth_CSTree(p))>max)max=d; //子树的最大深度
			return max+1;
	}
}


int LeafCount_CSTree(CSTree T){//求孩子兄弟链表表示的树T的叶子数目
	int count;
	CSTree p;
	if(!T->firstchild) return 1; //叶子结点
	else{
		count=0;
		for(p=T->firstchild;p;p=p->nextsibling)count+=LeafCount_CSTree(p);
		return count; //各子树的叶子数之和
	}
}




int main(){
	CSTree T;
	CreateCSTree(T);
	PreOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	printf("\n");
	printf("树的深度:%d\n",GetDepth_CSTree(T));
	printf("树叶数:%d\n",LeafCount_CSTree(T));
}
