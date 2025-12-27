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
int Search_SSTable(SSTable ST,KeyType kval){//对静态查找表L进行查找
	int i;
	ST.elem[0].key=kval;
	for(i=ST.length;ST.elem[i].key!=kval;--i);//从后往前找
	return i;//找不到时为0
}//Search_SSTable

void main(){
	SSTable ST;
	KeyType kval=3;
	int n=8;
	InitSSTable(ST);
	CreateSSTable(ST,n);
	DispSSTable(ST);
	if(Search_SSTable(ST,kval))printf("%d的位置是：%d\n",kval,Search_SSTable(ST,kval));
	
}
