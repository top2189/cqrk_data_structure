#include <iostream>
typedef int  ElemType;
using namespace std;
///////////创建双链表结构体///////////////
typedef struct DNode{
 	ElemType  data;
 	struct DNode *prior;
 	struct DNode *next;
 }DLinkNode;

// 头插法逆置双链表
DLinkNode* ReverseDLinkList(DLinkNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // 空链表或只有一个节点，直接返回
    }

    DLinkNode* newHead = new DLinkNode(); // 动态申请内存新链表的头结点
    DLinkNode* current = head->next;
    while (current != nullptr) {
        DLinkNode* nextNode = current->next;

        // 将当前节点插入到新链表的头部
        current->prior = newHead;
        current->next = newHead->next;
        if (newHead->next != nullptr) {
            newHead->next->prior = current;
        }
        newHead->next = current;

        current = nextNode;
    }

    // 更新新链表头结点的prior指针
    if (newHead->next != nullptr) {
        newHead->next->prior = newHead;
    }

    // 释放原链表的头结点
    delete head;

    return newHead;
}

// 打印双链表元素
void PrintDLinkList(DLinkNode* head) {
    DLinkNode* p = head->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // 示例输入数组

    // 创建带头结点的双链表
    DLinkNode* head = new DLinkNode();
    DLinkNode* current = head;

    // 将数组元素插入双链表
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
	        DLinkNode* newNode = new DLinkNode{arr[i], nullptr, nullptr};
	        current->next = newNode;
	        newNode->prior = current;
	        current = newNode;
	    }

    cout << "原始双链表：";
    PrintDLinkList(head);

    DLinkNode* newHead = ReverseDLinkList(head);

    cout << "逆置后的双链表：";
    PrintDLinkList(newHead);

    // 释放逆置后的双链表
    current = newHead->next;
    while (current != nullptr) {
        DLinkNode* temp = current;
        current = current->next;
        delete temp;
    }
    delete newHead;

    return 0;
}