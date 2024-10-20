#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

typedef char ElemType;

typedef struct LNode{
	ElemType data;         //定义单链表结点类型
    struct LNode *next;    //指向后继结点
}LinkNode;

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
	r->next=NULL;		//尾结点next域置为NULL
}

//销毁
void DestroyList(LinkNode *&L){  
	LinkNode *pre=L;
	LinkNode *p=L->next;    //pre指向p的前驱结点
   	while (p!=NULL){	//扫描单链表L
     	free(pre);	    //释放pre结点
      	pre=p;		    //pre、p同步后移一个结点
      	p=pre->next;
   	}
   	free(pre);         //循环结束时，p为NULL，pre指向尾结点，释放它
}

//输出
void DispList(LinkNode *L){
   	LinkNode *p=L->next;	//p指向开始结点
   	while (p!=NULL){		//p不为NULL，输出p结点的data域
     	printf("%c ", p->data);
      	p=p->next;		//p移向下一个结点
   	}
   	printf("\n");
}

/*
有一个带头结点的单链表L（至少有一个数据结点），
设计一个算法使其元素递增有序排列。
*/
void sort(LinkNode *&L){
   	LinkNode *p, *pre, *q;
   	p=L->next->next;		//p指向L的第2个数据结点
   	L->next->next=NULL;	//构造只含一个数据结点的有序表
   	while (p!=NULL){
		q=p->next;		 //q保存p结点后继结点的指针

		pre=L;  	        //从有序表开头，pre指向插入p的前驱结点
		while (pre->next!=NULL && pre->next->data<p->data)
	      	pre=pre->next;	 //在有序表中找插入p的前驱结点pre

		p->next=pre->next;
		pre->next=p;
		p=q;			//扫描原单链表余下的结点
   	}
}

int main() {
    LinkNode *L;
 	char a[]={'a','1','b','2','c','3','d','4'};
 	
  	CreateListR(L, a, strlen(a)-1);
	DispList(L);

    sort(L);

    DispList(L);

	DestroyList(L);

    return 0;
}
