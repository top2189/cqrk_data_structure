#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef int ElemType;
//结构体 
typedef struct LNode{
	ElemType data;         //定义循环单链表结点类型
    struct LNode *next;    //指向后继结点
}LinkNode;

//头插法 
void CreateListF(LinkNode *&L, ElemType a[], int n){
	LinkNode *s;
	int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=L;		//创建头结点，其next域置为L
 	for (i=0;i<n;i++){		//循环建立数据结点
		s=(LinkNode *)malloc(sizeof(LinkNode));
     	s->data=a[i];		//创建数据结点s
     	s->next=L->next;		//将s插在原开始结点之前，头结点之后
     	L->next=s;
	}

}

//尾插法
void CreateListR(LinkNode *&L, ElemType a[], int n){
	LinkNode *s, *r;
   	int i;
   	L=(LinkNode *)malloc(sizeof(LinkNode));  //创建头结点
	r=L;				//r始终指向尾结点，开始时指向头结点
	for (i=0;i<n;i++){		//循环建立数据结点
   		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];		//创建数据结点s
		r->next=s;		//将s插入r之后
		r=s;
	}
	r->next=L;		//将尾结点的后继为头节点 
}

//初始化
void InitList(LinkNode *&L){
	L=(LinkNode *)malloc(sizeof(LinkNode));    //创建头结点
    L->next=L;
}
//寻找其date值域等于x的个数
int count(LinkNode *L,ElemType x)
{
	int ant=0;
	LinkNode *p=L->next;   //p指向首结点，ant置为0 
	while(p!=L)            //扫描循环单链表L 
	{
		if(p->data==x)
		{
			ant++;           //找到值为x的结点后ant加1 
		}
		p=p->next;      //p指向下一个结点 
	}
	return ant;         //返回值为x的结点个数 
 } 
//输出链表 
void DispList(LinkNode *L){
   	LinkNode *p=L->next;	//p指向开始结点
   	while (p!=L){		//p不为头节点，输出p结点的data域
     	printf("%d", p->data);
      	p=p->next;		//p移向下一个结点
   	}
   	printf("\n");
}

//主函数 
int main(int argc, char *argv[]) {
	LinkNode *L;
	ElemType x=3;
	ElemType a[10]={1,2,3,2,3,5,3,3,2,4}; 
 	int length=sizeof(a)/sizeof(a[0]);
    //头插法建立循环单链表 
	//CreateListF(L, a,length); 
	//尾插法建立循环单链表 
  	CreateListR(L, a,length);
  	
	DispList(L);
	printf("%d",count(L,x));
 	return 0;

}