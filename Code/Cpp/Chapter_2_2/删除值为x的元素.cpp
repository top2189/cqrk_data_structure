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


// 解法一（整体建表法）
// 设删除L中所有值等于x元素后的顺序表为L1,显然L1包含在L中,为此L1重用L的空间。
// 思路：扫描顺序表L,重建L只包含不等于x的元素。

void delnode1(SqList*& L, ElemType x)
{
    int k = 0, i;		//k记录值不等于x的元素个数
    for (i = 0;i < L->length;i++)
        if (L->data[i] != x)    	//若当前元素不为x,将其插入A中
        {
            L->data[k] = L->data[i];
            k++;		 	//不等于x的元素增1
        }
    L->length = k;		//顺序表L的长度等于k
}


// 解法二（前移）
// 用k记录顺序表L中等于x的元素个数,一边扫描L一边统计k值。
// 思路：将不为x的元素前移k个位置,最后修改L的长度。

void delnode2(SqList*& L, ElemType x)
{
    int k = 0, i = 0;	      	//k记录值等于x的元素个数
    while (i < L->length)
    {
        if (L->data[i] == x)  	//当前元素值为x时k增1
            k++;
        else			//当前元素不为x时将其前移k个位置
            L->data[i - k] = L->data[i];
        i++;
    }
    L->length -= k;		//顺序表L的长度递减k
}


// 解法三（区间划分法）
void delnode3(SqList*& L, ElemType x)
{
    int i = -1, j = 0;
    while (j < L->length)	//j扫描所有元素
    {
        if (L->data[j] != x)	//找到不为x的元素
        {
            i++;			//扩大不为x的区间
            if (i != j)
                std::swap(L->data[i], L->data[j]); //这里用一下c++的交换方法
        }
        j++;			//继续扫描
    }
    L->length = i + 1;		//设置L中实际元素个数
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
        printf("%d", L->data[i]);
    printf("\n");
}


int main() {
    // 初始化顺序表
    SqList* L;
    InitList(L);
    ElemType e;

    // 按照题目要求，准备 1 2 1 2 3 2 这6个数据
    int data[6] = { 1, 2, 1, 2, 3, 2 };
    int length = sizeof(data) / sizeof(data[0]);

    // 循环遍历加入到顺序表中
    for (int i = 0;i < length;i++) {
        ListInsert(L,i+1,data[i]);
    }

    // 以下代码，选其一进行调用测试
    delnode1(L, 2);
    //delnode2(L, 2);
    //delnode3(L, 2);


    // 打印删除2后的顺序表，输出结果为：1 1 3
    DispList(L);

    return 0;
}