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
������һ����ͷ���ĵ�����L=��a1��b1��a2��b2������an��bn����
���һ���㷨�����ֳ�������ͷ���ĵ�����L1��L2��
������L1=��a1��a2������an����L2=��bn��bn-1������b1��
Ҫ��L1ʹ��L��ͷ��㡣
*/
void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2){
  	LinkNode *p=L->next, *q, *r1;		//pָ���1�����ݽ��
	L1=L;					//L1����ԭ��L��ͷ���
   	r1=L1;					//r1ʼ��ָ��L1��β���
   	L2=(LinkNode *)malloc(sizeof(LinkNode));	//����L2��ͷ���
   	L2->next=NULL;				//��L2��ָ����ΪNULL
   	while (p!=NULL){
   		r1->next=p;		//����β�巨��p(dataֵΪai)����L1��
		r1=p;
		p=p->next;		//p������һ�����(dataֵΪbi)
		q=p->next;     	//��q����p�ĺ�̽��
		p->next=L2->next;	//����ͷ�巨��p����L2��
		L2->next=p;
		p=q;			//p����ָ��ai+1�Ľ��
   	}
   	r1->next=NULL;		//β���next�ÿ�
}

int main() {
    LinkNode *L;
 	char a[]={'a','1','b','2','c','3','d','4'};
 	
  	CreateListR(L, a, strlen(a)-1);
	DispList(L);

    // ����������
    LinkNode *L1, *L2;
    split(L, L1, L2);

    // ��ӡ����������
    printf("L1: ");
    DispList(L);
    printf("L2: ");
    DispList(L2);

    DestroyList(L1);
	DestroyList(L2);
	DestroyList(L);

    return 0;
}
