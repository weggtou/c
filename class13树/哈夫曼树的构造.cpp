#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# define  OK 1
# define  OVERFLOW -1
# define  ERROR 0
# define  TRUE 1
# define  FALSE 0
# define  Max 1000
int n;
typedef char ElemType;
typedef struct{
	int weight;//结点的权值
	int parent,lchild,rchild;//该结点的双亲结点、左孩子结点、右孩子结点在数组中的下标
}HNode,*HuffmanTree;//动态分配数组存储哈夫曼树

typedef char **HuffmanCode;//动态分配数组存储哈夫曼编码表
void CreateHT(HuffmanTree &HT,int n){
	int i,k,Lnode,Rnode,Min1,Min2;
	if(n<=1)return;
	HT=new HNode[2*n-1];
	for(i=0;i<n;i++){//初始化HT
		scanf("%d",&HT[i].weight);
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
	}
	for(i=n;i<2*n-1;i++){
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
	}

	for(i=n;i<2*n-1;i++){//构造哈夫曼树
		Min1=Min2=Max;
		Lnode=Rnode=-1;//Lnode和rnode为权值最小的两个结点的位置
		for(k=0;k<=i-1;k++)//在HT中找权值最小的两个结点
			if(HT[k].parent==-1){//只在尚未构造二叉树的结点中查找
				if(HT[k].weight<Min1){
					Min2=Min1;
					Rnode=Lnode;
					Min1=HT[k].weight;
					Lnode=k;
				}
				else if(k!=Lnode&&HT[k].weight<Min2){
					Min2=HT[k].weight;
					Rnode=k;
				}
			}
		HT[i].weight= HT[Lnode].weight+HT[Rnode].weight;
		HT[i].lchild=Lnode;
		HT[i].rchild=Rnode;
		HT[Lnode].parent=i;
		HT[Rnode].parent=i;
	}
}




void GetHhffanCode(HuffmanTree HT,HuffmanCode &HC,int n){
	int i,c,f,start;
	HC=new char*[n];
	char *cd;
	cd=new char[n];
	cd[n-1]='\0';//编码结束符
	for(i=0;i<n;i++){//根据哈夫曼树求哈夫曼编码
		start=n-1;
		for(c=i,f=HT[i].parent;f!=-1;c=f,f=HT[f].parent)//从叶子结点到根逆序求编码
			if(HT[f].lchild==c)cd[--start]='0';
			else cd[--start]='1';
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);
	}
	delete cd;
}



void main(){
	HuffmanTree HT;
	HuffmanCode HC;
	n=8;
	CreateHT(HT,n);
	for(int i=0;i<2*n-1;i++){
		printf("i=%d:%3d",i,HT[i].weight);
		printf("%3d",HT[i].parent);
		printf("%3d",HT[i].lchild);
		printf("%3d\n",HT[i].rchild);
	}	
	GetHhffanCode(HT,HC,n);
	for(i=0;i<n;i++)puts(HC[i]);

}
