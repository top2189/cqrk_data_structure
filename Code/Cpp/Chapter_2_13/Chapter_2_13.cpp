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
//删除第一结点data为x 
bool delelem(DLinkNode *&L,ElemType x)
{
	DLinkNode *p=L->next;   //p指向首结点 
	while(p!=L&&p->data!=x)  //查找第一个data值为x的结点p 
	{
		p=p->next;    
	}
	if(p!=L)
	{
		p->next->prior=p->prior;//删除p结点
		p->prior->next=p->next;
		free(p);
		return true;   //返回真 
	}
	else return false;  //没有找的为x的结点，返回假 
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
	ElemType a[] = {3,1 ,2 , 3, 3}; // 示例数据
	ElemType x=3;
	ElemType length=sizeof(a)/sizeof(a[0]); 
	    // 插法建立循环双链表
	 CreateListR(L, a,length);
	 //头插法建立循环双链表 
	 //CreateListF(L, a,length);	 
	    // 打印循环双链表元素
	    cout << "循环双链表元素：";
	    PrintList(L);
	    if(delelem(L,x))
	    {
	    	cout<<"找到了并输出删除之后的"<<endl;
			PrintList(L);
		}
		else
		{
			cout<<"未找到";
		}
	    return 0;
}