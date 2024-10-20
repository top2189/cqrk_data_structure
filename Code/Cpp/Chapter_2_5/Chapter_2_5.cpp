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

//头插法 
void CreateListF(LinkNode *&L, ElemType a[], int n){
	LinkNode *s;
	int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;		//创建头结点，其next域置为NULL
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
	r->next=NULL;		//尾结点next域置为NULL
}

//初始化
void InitList(LinkNode *&L){
	L=(LinkNode *)malloc(sizeof(LinkNode));    //创建头结点
    L->next=NULL;
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

//判断是否为空表
bool ListEmpty(LinkNode *L){
	return(L->next==NULL);
}

//求长度
int ListLength(LinkNode *L){
	int n=0;
	LinkNode *p=L;	//p指向头结点，n置为0（即头结点的序号为0）
	while (p->next!=NULL){
   		n++;
		p=p->next;
   	}
   	return(n);		//循环结束，p指向尾结点，其序号n为结点个数
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

//求位置i的数据元素
bool GetElem(LinkNode *L, int i, ElemType &e){ 
   	int j=0;
	LinkNode *p=L;	 //p指向头结点，j置为0（即头结点的序号为0）
   	while (j<i && p!=NULL){
   		j++;
		p=p->next;
   	}
   	if (p==NULL)	//不存在第i个数据结点，返回false
      	return false;
   	else{			//存在第i个数据结点，返回true
     	e=p->data;
      	return true;
   	}
}

//按元素值查找
int LocateElem(LinkNode *L, ElemType e){
   	int i=1;
   	LinkNode *p=L->next;	//p指向开始结点，i置为1  
   	while (p!=NULL && p->data!=e){ 
     	p=p->next;  		//查找data值为e的结点，其序号为i
      	i++;
   	}
	if (p==NULL)	//不存在元素值为e的结点，返回0
      	return 0;
   	else			//存在元素值为e的结点，返回其逻辑序号i
      	return i;
}

//插入
bool ListInsert(LinkNode *&L, int i, ElemType e){
  	int j=0;
   	LinkNode *p=L, *s;          	//p指向头结点，j置为0
   	while (j<i-1 && p!=NULL){
   		j++;
		p=p->next;
   	}
   	if (p==NULL)		//未找到第i-1个结点，返回false
       	return false;
   	else{			//找到第i-1个结点p，插入并返回true
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;		//创建新结点s，其data域置为e
		s->next=p->next;	//将s插入到p之后
		p->next=s;
		return true;
   	}
}

//删除
bool ListDelete(LinkNode *&L, int i, ElemType &e){
  	int j=0;
   	LinkNode *p=L, *q;		//p指向头结点，j置为0
   	while (j<i-1 && p!=NULL){	//查找第i-1个结点
   		j++;
		p=p->next;
   	}
   	if (p==NULL)		//未找到第i-1个结点，返回false
		return false;
   	else{				//找到第i-1个结点p
   		q=p->next;		//q指向第i个结点
		if (q==NULL)		//若不存在第i个结点，返回false
	   		return false;
		e=q->data;
		p->next=q->next;	//从单链表中删除q结点
		free(q);		//释放q结点
		return true;		//返回true表示成功删除第i个结点
   	}
}

//主函数 
int main(int argc, char *argv[]) {
	LinkNode *Lf,*Lr;
 	char a[]={'a','b','1','2','3','C','D','5'};
 	char c;
 	
	CreateListF(Lf, a, strlen(a)-1); 
  	CreateListR(Lr, a, strlen(a)-1);
  	printf("头插法:");
	DispList(Lf);
	printf("尾插法:");
  	DispList(Lr);
	printf("长度为：%d\n",ListLength(Lr));
	if (ListInsert(Lf, 3, 'c'))
		DispList(Lf);
	if (ListDelete(Lr, 2, c))
		DispList(Lr);
	DestroyList(Lf);
	DestroyList(Lr);
 	return 0;

}
