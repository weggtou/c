#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define MAXSIZE 100
typedef  char  KeyType;   
typedef  struct {
  KeyType   *key;         //关键字
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
int H(char *s){//求Hash函数
	if(s) return s[0]-96; //求关键字第一个字母的字母序号(小写)
	else return 0;
}//H 
void CreateHashTable(HashTable &HT,int n){//创建哈希表，以课本上的例子为例
	int i,h;
	char *key;
    for(i=0;i<MAXSIZE;i++)HT.elem[i].key='\0';	
	for(i=0;i<n;i++){
		key=new char;
		scanf("%s",key);
		h=H(key);
		while(HT.elem[h].key!=NULL)h=(h+1)%26;
		HT.elem[h].key=key;
		printf("(%d %s)\n",h,HT.elem[h].key);
		HT.length++;
	}
}
void DispHashTable(HashTable HT){//输出哈希表
	int i;
	for(i=0;i<26;i++)if(HT.elem[i].key!='\0')printf("%s ",HT.elem[i].key);
	printf("\n");	
}

void Print_Hash(HashTable HT){//按第一个字母顺序输出Hash表中的所有关键字,其中处理冲突采用线性探测开放定址法
	int i,j;
	for(i=0;i<26;i++)
		for(j=i;HT.elem[j].key!='\0';j=(j+1)%26) //线性探测
			if(HT.elem[j].key[0]-96==i) printf("%s\n",HT.elem[j].key);
}//Print_Hash



typedef struct Node{
	ElemType  data;// 数据元素存储基址，动态分配数组
	struct Node *next;//指向下一个数据元素
}Node,*HTable;
int ASLHash(HTable HT[]){//求链地址解决冲突的哈希表查找不成功的平均查找长度
	int i,j,count=0;//记录查找不成功的总的次数
	Node *p;
	for(i=0;i<26;i++){
		p=HT[i];
		j=1;//查找不成功是指直到空指针为止
		while(p!=NULL){j++;p=p->next;}
		count+=j;
	}
	return count/26;
}

void main(){
	HashTable HT;
	KeyType kval=26;
	int n=7;
	InitHashTable(HT);
	CreateHashTable(HT,n);
	DispHashTable(HT);	
	Print_Hash(HT);
	HTable H[100];
	//HT[]=NULL;
	printf("%d\n",ASLHash(H));
}


