#include <stdio.h>
#include <stdlib.h>

struct DLinkNode {
    int data;
    struct DLinkNode* prior;
    struct DLinkNode* next;
};

// 头插法逆置双链表
struct DLinkNode* ReverseDLinkList(struct DLinkNode* head) {
    if (head == NULL || head->next == NULL) {
        return head; // 空链表或只有一个节点，直接返回
    }

    struct DLinkNode* newHead = (struct DLinkNode*)malloc(sizeof(struct DLinkNode)); // 新链表的头结点
    newHead->prior = NULL;
    newHead->next = NULL;

    struct DLinkNode* current = head->next;
    while (current != NULL) {
        struct DLinkNode* nextNode = current->next;

        // 将当前节点插入到新链表的头部
        current->prior = newHead;
        current->next = newHead->next;
        if (newHead->next != NULL) {
            newHead->next->prior = current;
        }
        newHead->next = current;

        current = nextNode;
    }

    // 更新新链表头结点的prior指针
    if (newHead->next != NULL) {
        newHead->next->prior = newHead;
    }

    // 释放原链表的头结点
    free(head);

    return newHead;
}

// 打印双链表元素
void PrintDLinkList(struct DLinkNode* head) {
    struct DLinkNode* p = head->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5}; // 示例输入数组

    // 创建带头结点的双链表
    struct DLinkNode* head = (struct DLinkNode*)malloc(sizeof(struct DLinkNode));
    head->prior = NULL;
    head->next = NULL;
    struct DLinkNode* current = head;

    // 将数组元素插入双链表
    for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        DLinkNode* newNode = ( DLinkNode*)malloc(sizeof( DLinkNode));
        newNode->data = arr[i];
        newNode->prior = current;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }

    printf("原始双链表：");
    PrintDLinkList(head);

    struct DLinkNode* newHead = ReverseDLinkList(head);

    printf("逆置后的双链表：");
    PrintDLinkList(newHead);

    // 释放逆置后的双链表
    current = newHead->next;
    while (current != NULL) {
        struct DLinkNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(newHead);

    return 0;
}