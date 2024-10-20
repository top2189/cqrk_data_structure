#include<iostream>
using namespace std;
typedef int ElemType;
//循环双链表结构体定义
 typedef struct DNode{
 	ElemType  data;
 	struct DNode *prior;
 	struct DNode *next;
 }DLinkNode;
//头插法建立循环双链表
void CreateListF(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s;
    L = (DLinkNode*)malloc(sizeof(DLinkNode));     // 创建头节点
    L->next =L;                    //后指针域置为L头结点 
    for (int i = 0; i < n; i++) {
    
        s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i]; // 创建数据节点 s
        s->next = L->next; // 将 s 插到头节点之后	
        L->next->prior=s;
        L->next = s;
        s->prior = L;	

    }
}
//尾插法建立循环双链表
void CreateListR(DLinkNode *&L,ElemType a[],int  n){
	DLinkNode *s,*r;
	L=(DLinkNode*)malloc(sizeof(DLinkNode));//创建数据节点
	r=L;//r始终指向尾节点，开始时指向头节点
	for(int i=0;i<n;i++){//循环建立数据节点
			s=(DLinkNode*)malloc(sizeof(DLinkNode));
			s->data=a[i];//创建数据节点s
			r->next=s;//将s插入r之后
			s->prior=r;
			r=s;//r指向尾结点
	}
	r->next=L;//尾结点的后继为L
	L->prior=r;//头结点的前驱为尾结点r 
}
bool Symm(DLinkNode *L)
{
	bool same=true;
	DLinkNode *p=L->next;   //p指向首结点 
	DLinkNode *q=L->prior;  //q指向尾结点 
	while(same)
	{
		if(p->data!=q->data)
		{
			same=false;
		}
		else 
		{
			if(p==q||p==q->prior)break;
			q=q->prior;    //q前移 
			p=p->next;     //p后移 
		}
	}
	return same;
 } 

// 打印循环双链表元素
void PrintList(DLinkNode *L) {
    DLinkNode *p = L->next;
    while (p != L) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}
int main(){
	DLinkNode *L ; // 定义一个循环双链表头指针
	ElemType a[] = {3,4,2,4,3}; // 示例数据
	ElemType length=sizeof(a)/sizeof(a[0]); 
	    //尾插法建立循环双链表
	 CreateListR(L, a,length);
	 //头插法建立循环双链表 
	 //CreateListF(L, a,length);	 
	    // 打印循环双链表元素
	    cout << "循环双链表元素：";
	    PrintList(L);
	    if(Symm(L))cout<<"是对称相等的";
		else cout<<"不是对称相等的"; 
	    return 0;
}