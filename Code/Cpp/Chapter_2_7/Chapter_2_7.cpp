#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

typedef char ElemType;

typedef struct LNode{
	ElemType data;         //���嵥����������
    struct LNode *next;    //ָ���̽��
}LinkNode;

//β�巨
void CreateListR(LinkNode *&L, ElemType a[], int n){
	LinkNode *s, *r;
   	int i;
   	L=(LinkNode *)malloc(sizeof(LinkNode));  //����ͷ���
	r=L;				//rʼ��ָ��β��㣬��ʼʱָ��ͷ���
	for (i=0;i<n;i++){		//ѭ���������ݽ��
   		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=a[i];		//�������ݽ��s
		r->next=s;		//��s����r֮��
		r=s;
	}
	r->next=NULL;		//β���next����ΪNULL
}

//����
void DestroyList(LinkNode *&L){  
	LinkNode *pre=L;
	LinkNode *p=L->next;    //preָ��p��ǰ�����
   	while (p!=NULL){	//ɨ�赥����L
     	free(pre);	    //�ͷ�pre���
      	pre=p;		    //pre��pͬ������һ�����
      	p=pre->next;
   	}
   	free(pre);         //ѭ������ʱ��pΪNULL��preָ��β��㣬�ͷ���
}

//���
void DispList(LinkNode *L){
   	LinkNode *p=L->next;	//pָ��ʼ���
   	while (p!=NULL){		//p��ΪNULL�����p����data��
     	printf("%c ", p->data);
      	p=p->next;		//p������һ�����
   	}
   	printf("\n");
}

/*
���һ���㷨��ɾ��һ��������L��Ԫ��ֵ���Ľ�㣨�������ֵ�����Ψһ�ģ���
*/
void delmaxnode(LinkNode *&L){
   	LinkNode *p=L->next, *pre=L, *maxp=p, *maxpre=pre;

    while (p!=NULL){
      	if (maxp->data<p->data){	//���ҵ�һ������Ľ��
	   		maxp=p;			//����maxp
	    	maxpre=pre;		//����maxpre
		}
		pre=p;				//p��preͬ������һ�����
		p=p->next;
    }

    maxpre->next=maxp->next;		//ɾ��maxp���
    free(maxp);			//�ͷ�maxp���
}

int main() {
    LinkNode *L;
 	char a[]={'a','1','b','2','c','3','d','4'};
 	
  	CreateListR(L, a, strlen(a)-1);
	DispList(L);

    delmaxnode(L);

    DispList(L);

	DestroyList(L);

    return 0;
}
