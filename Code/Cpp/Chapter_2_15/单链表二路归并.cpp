#include<iostream>
#include<vector>
using namespace std;
typedef int  ElemType;
//////////单链表结构体创建///////////
typedef struct LNode{
	ElemType data;
	struct LNode *next;
} LinkNode;
//////////尾插法建立单链表///////////
void CreteList(LinkNode *&l,ElemType a[],int n){
	LinkNode *s,*r;
	l=(LinkNode*)malloc(sizeof(LinkNode));//创建头节点
	r=l;//r始终指向为节点
	for(int i=0;i<n;i++){//循环建立数据节点
	s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=a[i];//创建数据节点
	r->next=s;//将s插入r之后
	r=s;
	}
	r->next=NULL;//尾节点指针置空
}
///////////单链表初始化////////////
void InitList(LinkNode *&l){
	l=(LinkNode*)malloc(sizeof(LinkNode));
	l->next=NULL;
}
//////////单链表的二路归并算法////////////
void UnionList(LinkNode *la, LinkNode *lb, LinkNode *&lc){
    LinkNode *pa = la->next, *pb = lb->next, *s, *r;//r用来添加元素进lc，s用来复制节点
    lc = (LinkNode *)malloc(sizeof(LinkNode));//初始化lc，给他创造空间
    r = lc; // r指向尾节点
    //将la,lb进行比较，较小的结果放入lc
    while (pa != NULL && pb != NULL) {
        if (pa->data <= pb->data) {
            s = (LinkNode*)malloc(sizeof(LinkNode));
            s->data = pa->data;//复制节点pa
            r->next = s;//将la插入lc
            r = s;//更新r节点位置
            pa = pa->next;//更新pa节点位置
        } else {
            s = (LinkNode*)malloc(sizeof(LinkNode));
            s->data = pb->data;//复制节点pb
            r->next = s;//将lb插入lc
            r = s;//更新r节点位置
            pb = pb->next;//更新pa节点位置
        }
    }
    //处理la未遍历完全的情况
    while (pa != NULL) {
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = pa->data;
        r->next = s;
        r = s;
        pa = pa->next;
    }
	//处理la未遍历完全的情况
    while (pb != NULL) {
        s = (LinkNode*)malloc(sizeof(LinkNode));
        s->data = pb->data;
        r->next = s;
        r = s;
        pb = pb->next;
    }

    r->next = NULL; // 尾节点指针置空
}
int main(){
    ElemType arr1[] = {1, 2, 5, 7, 9};
    ElemType arr2[] = {2, 4, 6, 8, 10};

    LinkNode *l1, *l2, *l3;//定义链表
    CreteList(l1, arr1, 5);
    CreteList(l2, arr2, 5);
    cout << "单链表 1: ";
    LinkNode *p1 = l1->next;
    while (p1) {
        cout << p1->data << " ";
        p1 = p1->next;
    }
    cout << endl;

    cout << "单链表 2: ";
    LinkNode *p2 = l2->next;
    while (p2) {
        cout << p2->data << " ";
        p2 = p2->next;
    }
    cout << endl;

    UnionList(l1, l2, l3);

    cout << "排序后的链表 List: ";
    LinkNode *p3 = l3->next;
    while (p3) {
        cout << p3->data << " ";
        p3 = p3->next;
    }
    cout << endl;
    getchar();//防止程序闪退
    getchar();
    return 0;
}