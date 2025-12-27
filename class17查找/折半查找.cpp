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
int Search_Bin(SSTable ST, KeyType kval){//在表中进行折半查找
	int low,high,mid;
	low=1;high=ST.length; //置区间初值
	while(low<=high){
		mid=(low+high)/2;
		if(kval==ST.elem[mid].key)return mid;//找到待查元素
		else if(kval<ST.elem[mid].key)high=mid-1;//继续在前半区间进行查找
		else low=mid+1;//继续在后半区间进行查找
	}
	return 0;//顺序表中不存在待查元素
}//Search_Bin


void main(){
	SSTable ST;
	KeyType kval=3;
	int n=8;
	InitSSTable(ST);
	CreateSSTable(ST,n);
	DispSSTable(ST);
	if(Search_Bin(ST,kval))printf("%d的位置是：%d\n",kval,Search_Bin(ST,kval));
	
}
