#include <iostream>
typedef int ElemType;
using namespace std;

// 创建双链表结构体
typedef struct DNode {
    ElemType  data;
    struct DNode* prior;
    struct DNode* next;
} DLinkNode;

// 插入排序，将双链表按照元素递增有序排列
void InsertionSort(DLinkNode* head) {
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
        return; // 空链表或只有一个节点，无需排序
    }

    DLinkNode* p = head->next->next; 
    while (p != nullptr) {
        DLinkNode* current = p;
        p = p->next; 

        DLinkNode* q = current->prior;
        while (q != head && q->data > current->data) {
            q = q->prior;
        }

        current->prior->next = current->next;
        if (current->next != nullptr) {
            current->next->prior = current->prior;
        }

        current->next = q->next;
        current->prior = q;
        q->next = current;
        if (current->next != nullptr) {
            current->next->prior = current;
        }
    }
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
    int arr[] = {5, 3, 8, 2, 1}; // 示例输入数组

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

    InsertionSort(head);

    cout << "排序后的双链表：";
    PrintDLinkList(head);

    // 释放双链表
    current = head->next;
    while (current != nullptr) {
        DLinkNode* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;

    return 0;
}