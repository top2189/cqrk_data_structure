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

// 解法一（前后交换法，类似例2.4解法一）
// i（初值为0）从左向右扫描，j（初值为L->length - 1）从右向左扫描。
// 当i≠j时循环：j从右向左找一个奇数元素data[j]，i从左向右找一个偶数data[i]，然后在i < j时将两者进行交换。
void move1(SqList*& L)
{
    int i = 0, j = L->length - 1;
    while (i < j)
    {
        while (i < j && L->data[j] % 2 == 0)
            j--;			//从右向左,找一个奇数元素
        while (i < j && L->data[i] % 2 == 1)
            i++;			//从左向右,找一个偶数元素
        if (i < j)			//若i<j，L->data[i]和L->data[j]交换
            std::swap(L->data[i], L->data[j]);
    }
}

// 解法二（区间划分法）
// 用L->data[0..i]表示存放奇数的奇数区间（i指向奇数区间中的最后元素），初始时i为 - 1表示奇数区间为空。
// j从左向右扫描所有元素，如果j指向的元素是奇数，让i增1表示奇数区间多了一个奇数，然后将L->data[j]和L->data[i]交换，j继续扫描。
void move2(SqList*& L)
{
    int i = -1, j;
    for (j = 0;j <= L->length - 1;j++)
        if (L->data[j] % 2 == 1)	//j指向奇数时
        {
            i++;			//奇数区间个数增1
            if (i != j)		//若i不为j，L->data[i]和L->data[j]交换
                std::swap(L->data[i], L->data[j]);
        }
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

    // 按照题目要求，准备 5 个数据
    int data[5] = { 1,2,3,4,5 };
    int length = sizeof(data) / sizeof(data[0]);

    // 循环遍历加入到顺序表中
    for (int i = 0;i < length;i++) {
        ListInsert(L, i + 1, data[i]);
    }

    // 以下代码，选其一进行调用测试
    move1(L); // 输出结果为：1 5 3 4 2
    //move2(L); // 输出结果为：1 3 5 4 2

    // 打印顺序表
    DispList(L);

    return 0;
}