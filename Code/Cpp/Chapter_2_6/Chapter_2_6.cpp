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
假设有一个带头结点的单链表L=（a1，b1，a2，b2，…，an，bn）。
设计一个算法将其拆分成两个带头结点的单链表L1和L2：
　　　L1=（a1，a2，…，an），L2=（bn，bn-1，…，b1）
要求L1使用L的头结点。
*/
void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2){
  	LinkNode *p=L->next, *q, *r1;		//p指向第1个数据结点
	L1=L;					//L1利用原来L的头结点
   	r1=L1;					//r1始终指向L1的尾结点
   	L2=(LinkNode *)malloc(sizeof(LinkNode));	//创建L2的头结点
   	L2->next=NULL;				//置L2的指针域为NULL
   	while (p!=NULL){
   		r1->next=p;		//采用尾插法将p(data值为ai)插入L1中
		r1=p;
		p=p->next;		//p移向下一个结点(data值为bi)
		q=p->next;     	//用q保存p的后继结点
		p->next=L2->next;	//采用头插法将p插入L2中
		L2->next=p;
		p=q;			//p重新指向ai+1的结点
   	}
   	r1->next=NULL;		//尾结点next置空
}

int main() {
    LinkNode *L;
 	char a[]={'a','1','b','2','c','3','d','4'};
 	
  	CreateListR(L, a, strlen(a)-1);
	DispList(L);

    // 分离后的链表
    LinkNode *L1, *L2;
    split(L, L1, L2);

    // 打印分离后的链表
    printf("L1: ");
    DispList(L);
    printf("L2: ");
    DispList(L2);

    DestroyList(L1);
	DestroyList(L2);
	DestroyList(L);

    return 0;
}
