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

//ͷ�巨 
void CreateListF(LinkNode *&L, ElemType a[], int n){
	LinkNode *s;
	int i;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->next=NULL;		//����ͷ��㣬��next����ΪNULL
 	for (i=0;i<n;i++){		//ѭ���������ݽ��
		s=(LinkNode *)malloc(sizeof(LinkNode));
     	s->data=a[i];		//�������ݽ��s
     	s->next=L->next;		//��s����ԭ��ʼ���֮ǰ��ͷ���֮��
     	L->next=s;
	}
}

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

//��ʼ��
void InitList(LinkNode *&L){
	L=(LinkNode *)malloc(sizeof(LinkNode));    //����ͷ���
    L->next=NULL;
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

//�ж��Ƿ�Ϊ�ձ�
bool ListEmpty(LinkNode *L){
	return(L->next==NULL);
}

//�󳤶�
int ListLength(LinkNode *L){
	int n=0;
	LinkNode *p=L;	//pָ��ͷ��㣬n��Ϊ0����ͷ�������Ϊ0��
	while (p->next!=NULL){
   		n++;
		p=p->next;
   	}
   	return(n);		//ѭ��������pָ��β��㣬�����nΪ������
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

//��λ��i������Ԫ��
bool GetElem(LinkNode *L, int i, ElemType &e){ 
   	int j=0;
	LinkNode *p=L;	 //pָ��ͷ��㣬j��Ϊ0����ͷ�������Ϊ0��
   	while (j<i && p!=NULL){
   		j++;
		p=p->next;
   	}
   	if (p==NULL)	//�����ڵ�i�����ݽ�㣬����false
      	return false;
   	else{			//���ڵ�i�����ݽ�㣬����true
     	e=p->data;
      	return true;
   	}
}

//��Ԫ��ֵ����
int LocateElem(LinkNode *L, ElemType e){
   	int i=1;
   	LinkNode *p=L->next;	//pָ��ʼ��㣬i��Ϊ1  
   	while (p!=NULL && p->data!=e){ 
     	p=p->next;  		//����dataֵΪe�Ľ�㣬�����Ϊi
      	i++;
   	}
	if (p==NULL)	//������Ԫ��ֵΪe�Ľ�㣬����0
      	return 0;
   	else			//����Ԫ��ֵΪe�Ľ�㣬�������߼����i
      	return i;
}

//����
bool ListInsert(LinkNode *&L, int i, ElemType e){
  	int j=0;
   	LinkNode *p=L, *s;          	//pָ��ͷ��㣬j��Ϊ0
   	while (j<i-1 && p!=NULL){
   		j++;
		p=p->next;
   	}
   	if (p==NULL)		//δ�ҵ���i-1����㣬����false
       	return false;
   	else{			//�ҵ���i-1�����p�����벢����true
		s=(LinkNode *)malloc(sizeof(LinkNode));
		s->data=e;		//�����½��s����data����Ϊe
		s->next=p->next;	//��s���뵽p֮��
		p->next=s;
		return true;
   	}
}

//ɾ��
bool ListDelete(LinkNode *&L, int i, ElemType &e){
  	int j=0;
   	LinkNode *p=L, *q;		//pָ��ͷ��㣬j��Ϊ0
   	while (j<i-1 && p!=NULL){	//���ҵ�i-1�����
   		j++;
		p=p->next;
   	}
   	if (p==NULL)		//δ�ҵ���i-1����㣬����false
		return false;
   	else{				//�ҵ���i-1�����p
   		q=p->next;		//qָ���i�����
		if (q==NULL)		//�������ڵ�i����㣬����false
	   		return false;
		e=q->data;
		p->next=q->next;	//�ӵ�������ɾ��q���
		free(q);		//�ͷ�q���
		return true;		//����true��ʾ�ɹ�ɾ����i�����
   	}
}

//������ 
int main(int argc, char *argv[]) {
	LinkNode *Lf,*Lr;
 	char a[]={'a','b','1','2','3','C','D','5'};
 	char c;
 	
	CreateListF(Lf, a, strlen(a)-1); 
  	CreateListR(Lr, a, strlen(a)-1);
  	printf("ͷ�巨:");
	DispList(Lf);
	printf("β�巨:");
  	DispList(Lr);
	printf("����Ϊ��%d\n",ListLength(Lr));
	if (ListInsert(Lf, 3, 'c'))
		DispList(Lf);
	if (ListDelete(Lr, 2, c))
		DispList(Lr);
	DestroyList(Lf);
	DestroyList(Lr);
 	return 0;

}
