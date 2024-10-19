#include<iostream>
typedef int ElemType;
using namespace std;
//////////双链表结构体定义///////////
 typedef struct DNode{
 	ElemType  data;
 	struct DNode *prior;
 	struct DNode *next;
	
 }DLinkNode;
///////////头插法建立双链表//////////
void CreateListF(DLinkNode *&l, ElemType a[], int n) {
    DLinkNode *s;
    l = (DLinkNode*)malloc(sizeof(DLinkNode)); // 创建头节点
    l->prior = l->next = NULL; // 前后指针域置为空
    for (int i = 0; i < n; i++) {
        s = (DLinkNode*)malloc(sizeof(DLinkNode));
        s->data = a[i]; // 创建数据节点 s
        s->next = l->next; // 将 s 插到头节点之后
        if (l->next != NULL) { // 若 l 存在数据节点修改前驱指针
            l->next->prior = s;
        }
        l->next = s;
        s->prior = l;
    }
}
///////////尾插法建立双链表//////////
void CreateListR(DLinkNode *&l,ElemType a[],int  n){
	DLinkNode *s,*r;
	l=(DLinkNode*)malloc(sizeof(DLinkNode));//创建数据节点
	r=l;//r始终指向尾节点，开始时指向头节点
	for(int i=0;i<n;i++){//循环建立数据节点
			s=(DLinkNode*)malloc(sizeof(DLinkNode));
			s->data=a[i];//创建数据节点s
			r->next=s;//将s插入r之后
			s->prior=r;
			r=s;//r指向尾结点
	}
	r->next=NULL;//尾结点next域置为空
}
///////////双链表的插入/////////////
bool ListInsert(DLinkNode *&l,int i,ElemType e){
	int j=0;
	DLinkNode *p=l,*s;//p指向头结点，j设置为0
	 while(j<i-1&&p!=NULL){//查找第i-1个结点
	 	j++;
	 	p=p->next;
	 }
	 if(p==NULL){//未找到第i-1个结点。返回false
	 	return false;
	 }else{//找到第i-1个结点p，在其后插入新结点s
	 	s=(DLinkNode*)malloc(sizeof(DLinkNode));
	 	s->data=e;//创建新的结点S
	 	s->next=p->next;//再p之后插入新S的结点
	 	if(p->next!=NULL){
		 	p->next->prior=s;//若存在后继节点修改前驱指针
		 }
		 s->prior=p;
		 p->next=s;
		 return true;
	 }
}
////////////双链表删除算法//////////
bool ListDelete(DLinkNode *&l, int i, ElemType &e) {
    int j = 0; // 初始化计数器 j
    DLinkNode *p = l, *q; // 定义指针 p 指向头节点 l，定义指针 q
    while (j < i - 1 && p != NULL) { // 寻找第 i-1 个节点
        j++; 
        p = p->next; 
    }
    if (p == NULL) { // 若 p 为空，说明未找到第 i-1 个节点
        return false; // 返回删除失败
    } else {
        q = p->next; // 找到第 i 个节点 q
        if (q == NULL) { // 若 q 为空，说明第 i 个节点不存在
            return false; // 返回删除失败
        }
        e = q->data; // 将第 i 个节点的数据存入 e 中
        p->next = q->next; // 修改指针连接，删除第 i 个节点
        if (q->next != NULL) { // 若第 i+1 个节点存在
            q->next->prior = p; // 修改第 i+1 个节点的前驱指针
        }
        free(q); // 释放第 i 个节点的内存空间
        return true; // 返回删除成功
    }
}
/////////////双链表的销毁///////////
void DestroyList(DLinkNode *&l) {
    DLinkNode *p = l, *q; // 定义指针 p 指向头节点 l，定义指针 q
    while (p != NULL) { // 遍历链表直到结束
        q = p->next; // 保存下一个节点的指针
        free(p); // 释放当前节点的内存
        p = q; // 移动到下一个节点
    }
    l = NULL; // 头指针置为空
}
////////////// 打印双链表元素////////////
void PrintList(DLinkNode *l) {
    DLinkNode *p = l->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int main(){
	DLinkNode *list = NULL; // 定义一个双链表头指针，初始化为空
	    ElemType data[] = {1, 2, 3, 4, 5}; // 示例数据
	
	    // 测试头插法建立双链表
	    CreateListF(list, data, 5);
	
	    // 打印双链表元素
	    cout << "双链表元素：";
	    PrintList(list);
	
	    // 测试双链表插入
	    ListInsert(list, 3, 10);
	    cout << "插入元素后：";
	    PrintList(list);
	
	    // 测试双链表删除
	    ElemType deletedData;
	    ListDelete(list, 2, deletedData);
	    cout << "删除元素后：";
	    PrintList(list);

	    // 测试双链表销毁
	    DestroyList(list);
	    cout << "双链表已销毁" << endl;
	    return 0;
}













