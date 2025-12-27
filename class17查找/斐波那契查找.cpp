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
int fib(int n){
	int i,f,f1=0,f2=1;
	if(n==0)return 0;
	if(n==1)return 1;
	for(i=2;i<=n;i++){
		f=f1+f2;
		f1=f2;
		f2=f;
	}
	return f;
}

int FibSearch(SSTable ST, KeyType kval){//在表中用斐波那契方法查找关键字等于kval的记录
	int low,high,mid,f1,f2;
	int m=0;
	while(fib(m)<ST.length)m++;	//求得表长n对应的斐波那契数，即n=F(m)-1
	low=1;high=fib(m); //置区间初值
	f1=fib(m-1);
	f2=fib(m-2);
	while(low<=high){
		mid=low+f1-1;
		if(ST.elem[mid].key==kval) return mid;
		else if(ST.elem[mid].key>kval){
			high=mid-1;
			f2=f1-f2;
			f1=f1-f2;
		}
		else{
			low=mid+1;
			f1=f1-f2;
			f2=f2-f1;
		}
	}
	return 0;
}


void main(){
	SSTable ST;
	KeyType kval=24;
	int n=7;
	InitSSTable(ST);
	CreateSSTable(ST,n);
	DispSSTable(ST);
	if(FibSearch(ST,kval))printf("%d的位置是：%d\n",kval,FibSearch(ST,kval));
	
}
