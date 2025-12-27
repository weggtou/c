#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
typedef  int  KeyType;   
#define m  7
typedef struct{
	KeyType key;//关键字域
	//InfoType  otherinfo; //其它数据项
}ElemType;
typedef struct node{
	KeyType  key;//关键字
	int adr;//该关键字在顺序表中的下标
}idxnode;//索引表的一项
ElemType seq[m+1];idxnode index[m+1];
void IndexT(ElemType seq[m+1],idxnode index[m+1]){//给有m个记录的顺序表seq建立索引表index
	int i,j;
	index[1].key=seq[1].key;
	index[1].adr=1;
	for(i=2;i<=m;i++){
		j=i-1;
		index[0].key=seq[i].key;//监视哨
		while(index[j].key<index[0].key){index[j+1]=index[j];j--;}
		index[j+1].key=index[0].key;//关键字放入正确位置
		index[j+1].adr=i;//第i个记录的下标
	}
}//IndexT






void main(){
	
	int i;
	for(i=1;i<=m;i++)scanf("%d",&seq[i].key);	
	IndexT(seq,index);
	for(i=1;i<=m;i++)printf("(%d,%d)",index[i].key,index[i].adr);
	printf("\n");	
}
