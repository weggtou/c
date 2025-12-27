#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
typedef  int  KeyType;   
typedef  struct {
  KeyType   key;         //关键字
  //InfoType  otherinfo;   //其它数据项
}ElemType;               //记录类型
typedef  struct {
  ElemType  *elem;//0号单元为“检测哨”
  int length;         //表长
}SSTable;                //静态查找表

int InitSSTable(SSTable &ST){//初始化静态查找表
	ST.elem=new ElemType[MAXSIZE];
	ST.length=0;
	return OK; 
}

void CreateSSTable(SSTable &ST,int n){//创建静态查找表
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&ST.elem[i].key);
		ST.length++;
	}
}
void DispSSTable(SSTable ST){//输出静态查找表
	int i;
	for(i=1;i<=ST.length;i++)printf("%d ",ST.elem[i].key);
	printf("\n");	
}


typedef struct{
	KeyType maxkey;
	int stadr;
}IndexItem; //索引项
typedef  struct{
	IndexItem *elem;
	int length;
}IndexTable;//索引表
int InitIndexTable(IndexTable &idx){//初始化静态查找表
	idx.elem=new IndexItem[MAXSIZE];
	idx.length=0;
	return OK; 
}

void CreateIndexTable(SSTable ST,IndexTable &idx){//创建静态查找表
	idx.elem[1].maxkey=25;
	idx.elem[1].stadr=1;
	idx.elem[2].maxkey=56;
	idx.elem[2].stadr=6;
	idx.elem[3].maxkey=89;
	idx.elem[3].stadr=11;
	idx.length=3;	
}
void DispIndexTable(IndexTable idx){//输出静态查找表
	int i;
	for(i=1;i<=idx.length;i++)printf("(%d,%d)",idx.elem[i].maxkey,idx.elem[i].stadr);
	printf("\n");	
}


int IndexSearch(SSTable ST, KeyType kval,IndexTable idx){
	int low,high,mid,i,b;
	low=1;high=idx.length;
	while(low<=high){//在索引表中进行折半查找，找到的位置放在low中
		mid=(low+high)/2;
		if(idx.elem[mid].maxkey>=kval)high=mid-1;
		else low=mid+1;
	}
	b=ST.length/idx.length;//b为每块的记录数
	if(low<idx.length){//在索引表中查找成功后，再在线性表中进行顺序查找
		i=idx.elem[low].stadr;
		while(i<=idx.elem[low].stadr+b-1 && ST.elem[i].key!=kval)i++;
		if(i<=idx.elem[low].stadr+b-1)return i;
		else return 0;
	}
	return 0;
}



void main(){
	SSTable ST;
	IndexTable idx;
	KeyType kval=32;
	int n=15;
	InitSSTable(ST);
	CreateSSTable(ST,n);
	DispSSTable(ST);
	InitIndexTable(idx);
	CreateIndexTable(ST,idx);
	DispIndexTable(idx);
	if(IndexSearch(ST,kval,idx))printf("%d的位置是：%d\n",kval,IndexSearch(ST,kval,idx));
	
}
