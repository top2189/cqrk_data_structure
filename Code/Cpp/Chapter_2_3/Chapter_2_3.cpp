#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// 定义最大长度
#define MaxSize 200

// 定义元素类型
typedef int ElemType;

// 定义链表结构体
typedef struct
{
    // data成员存放元素
    ElemType data[MaxSize];
    // length成员存放线性表的实际长度
    int length;
} SqList;

// 解法一（前后交换法）
void move1(SqList*& L)
{
    int i = 0, j = L->length - 1;
    ElemType base = L->data[0];	//以data[0]为基准
    while (i < j)
    {
        while (i<j && L->data[j]>base)
            j--;	  	 	//从后向前扫描,找一个≤base的元素
        while (i < j && L->data[i] <= base)
            i++;			//从前向后扫描,找一个>base的元素
        if (i < j)
            std::swap(L->data[i], L->data[j]);
    }
    std::swap(L->data[0], L->data[i]);
}

// 解法二（前后移动法）
void move2(SqList*& L)
{
    int i = 0,j = L->length - 1;
    ElemType  base = L->data[0];     //以data[0]为基准
    while (i < j)
    {
        while (j > i && L->data[j] > base)
            j--;       		     //从右向左,找≤base的data[j]
        L->data[i] = L->data[j];	     //将其放入data[i]处
        while (i < j && L->data[i] <= base)
            i++;      		    //从左向右,找>base的记录data[i]
        L->data[j] = L->data[i];	    //将其放入data[j]处
    }
    L->data[i] = base;    	    //放置基准
}



/*                         以下代码调试输出时使用                         */

// 初始化线性表
void InitList(SqList*& L)
{
    L = (SqList*)malloc(sizeof(SqList));
    //分配存放线性表的顺序表空间
    L->length = 0;
}

// 插入数据元素
bool  ListInsert(SqList*& L, int i, ElemType e)
{
    int j;
    if (i<1 || i>L->length + 1)
        return false;//参数错误时返回false
    i--;//将顺序表逻辑序号转化为物理序号
    for (j = L->length;j > i;j--)//将data[i..n]元素后移一个位置
        L->data[j] = L->data[j - 1];
    L->data[i] = e;//插入元素e
    L->length++;//顺序表长度增1
    return true;//成功插入返回true
}

// 输出线性表
void DispList(SqList* L)
{
    int i;
    // 判定是否为空表
    if (L->length == 0) return;
    for (i = 0;i < L->length;i++)
        printf("%d ", L->data[i]);
    printf("\n");
}


int main() {
    // 初始化顺序表
    SqList* L;
    InitList(L);
    ElemType e;

    // 按照题目要求，准备 10 个数据
    int data[10] = { 3,8,2,7,1,5,3,4,6,0 };
    int length = sizeof(data) / sizeof(data[0]);

    // 循环遍历加入到顺序表中
    for (int i = 0;i < length;i++) {
        ListInsert(L, i + 1, data[i]);
    }

    // 以下代码，选其一进行调用测试
    move1(L);
    //move2(L);


    // 输出结果为：0 3 2 1 3 5 7 4 6 8
    DispList(L);

    return 0;
}