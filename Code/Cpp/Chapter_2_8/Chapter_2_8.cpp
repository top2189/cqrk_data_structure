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
��һ����ͷ���ĵ�����L��������һ�����ݽ�㣩��
���һ���㷨ʹ��Ԫ�ص����������С�
*/
void sort(LinkNode *&L){
   	LinkNode *p, *pre, *q;
   	p=L->next->next;		//pָ��L�ĵ�2�����ݽ��
   	L->next->next=NULL;	//����ֻ��һ�����ݽ��������
   	while (p!=NULL){
		q=p->next;		 //q����p����̽���ָ��

		pre=L;  	        //�������ͷ��preָ�����p��ǰ�����
		while (pre->next!=NULL && pre->next->data<p->data)
	      	pre=pre->next;	 //����������Ҳ���p��ǰ�����pre

		p->next=pre->next;
		pre->next=p;
		p=q;			//ɨ��ԭ���������µĽ��
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
