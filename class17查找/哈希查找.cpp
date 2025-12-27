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
typedef struct{
  ElemType  *elem;// 数据元素存储基址，动态分配数组
  int length;// 当前数据元素个数
}HashTable;


int InitHashTable(HashTable &HT){//初始化哈希表
	HT.elem=new ElemType[MAXSIZE];
	HT.length=0;
	return OK; 
}

void CreateHashTable(HashTable &HT,int n){//创建哈希表，以课本上的例子为例
	int i,key,h;
    for(i=0;i<MAXSIZE;i++)HT.elem[i].key=-1;	
	for(i=0;i<n;i++){
		scanf("%d",&key);
		h=key%7;
		printf("h=%d",h);
		while(HT.elem[h].key!=-1)h=(h+1)%7;
		HT.elem[h].key=key;
		printf("(%d %d)\n",h,HT.elem[h].key);
		HT.length++;
	}
}
void DispHashTable(HashTable HT){//输出哈希表
	int i;
	for(i=0;i<HT.length;i++)printf("%d ",HT.elem[i].key);
	printf("\n");	
}



int SearchHash(HashTable HT,KeyType kval){//在开放定址哈希表HT中查找关键字为kval的记录，若查找成功，返回该记录的位置，否则返回-1
	int i,h;
	i=0;
	//h=H(kval);//求得哈希地址
	h=kval%7;
	//while(i<HT.length&&HT.elem[h].key!=NULLKEY){//该位置中填有记录并且关键字不相等
	while(i<HT.length&&HT.elem[h].key>0){//该位置中填有记录并且关键字不相等
		if(HT.elem[h].key==kval)return h;
		//else h=collision(k,++i);//用解决冲突的方法求得下一哈希地址
		else h=(h+1)%7;
	}
	return -1;
}//SearchHash


int InsertHash(HashTable &HT, ElemType e){//在开放定址哈希表HT中插入元素e
	int i,h;
	i=0;
	//h=H(e.key);
	h=e.key%7;
	while(i<HT.length){
		//if(HT.elem[h].key!=NULLKEY){
		if(HT.elem[h].key==-1){
			HT.elem[h]=e;
			return 1;
		}
		if(HT.elem[h].key==e.key)
			return -1;
		else 
			//h=collision(k,++i);//用解决冲突的方法求得下一哈希地址
			h=(h+1)%7;
	}
	return -1;
}//InsertHash


void main(){
	HashTable HT;
	KeyType kval=26;
	int n=5;
	InitHashTable(HT);
	CreateHashTable(HT,n);
	DispHashTable(HT);
	if(SearchHash(HT,kval))printf("%d的位置是：%d\n",kval,SearchHash(HT,kval));
	ElemType e;
	e.key=23;
	InsertHash(HT,e);
	DispHashTable(HT);
	
}
