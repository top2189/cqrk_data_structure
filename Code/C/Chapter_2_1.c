#include <stdio.h>
#include <stdlib.h>

// 定义最大长度
#define MaxSize 200

// 定义元素类型 这里以char为例
typedef char ElemType;


// 定义链表结构体
typedef struct
{
    // data成员存放元素
    ElemType data[MaxSize];
    // length成员存放线性表的实际长度
    int length;
} SqList;


// 1. 初始化线性表
void InitList(SqList*& L)
{
    L = (SqList*)malloc(sizeof(SqList));
    //分配存放线性表的顺序表空间
    L->length = 0;
}

// 2. 销毁线性表
void DestroyList(SqList*& L)
{
    free(L);
}

// 3. 判定是否为空表
bool ListEmpty(SqList* L)
{
    return(L->length == 0);
}

// 4. 求线性表的长度
int ListLength(SqList* L)
{
    return(L->length);
}

// 5. 输出线性表
void DispList(SqList* L)
{
    int i;
    if (ListEmpty(L)) return;
    for (i = 0;i < L->length;i++)
        printf("%c", L->data[i]);
    printf("\n");
}


// 6. 求某个数据元素值
bool GetElem(SqList* L, int i, ElemType& e)
{
    if (i<1 || i>L->length)  return false;
    e = L->data[i - 1];
    return true;
}


// 7. 按元素值查找
int LocateElem(SqList* L, ElemType e)
{
    int i = 0;
    while (i < L->length&& L->data[i] != e)
        i++;
    if (i >= L->length)  return 0;
    else  return i + 1;
}


// 8. 插入数据元素
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

// 9. 删除数据元素
bool ListDelete(SqList*& L, int i, ElemType& e)
{
    int j;
    //参数错误时返回false
    if (i<1 || i>L->length)  return false;

    i--;//将顺序表逻辑序号转化为物理序号
    e = L->data[i];
    for (j = i;j < L->length - 1;j++)  //将data[i..n-1]元素前移
        L->data[j] = L->data[j + 1];
    L->length--;//顺序表长度减1
    return true;//成功删除返回true
}


int main()
{
    // 初始化顺序表
    SqList* L;
    InitList(L);
    ElemType e;

    // 依次插入元素 ABCD
    ListInsert(L, 1, 'A');
    ListInsert(L, 2, 'B');
    ListInsert(L, 3, 'C');
    ListInsert(L, 4, 'D');

    // 打印输出，结果为：ABCD
    DispList(L);
    // 输出结果：4
    printf("当前链表长度为：%d \n",ListLength(L));


    printf("元素B所对应的位置为：%d \n", LocateElem(L,'B'));

    // 删除位置为3的元素，这里是删除3对应的元素C
    ListDelete(L, 3, e);

    // 打印输出，结果为：ABD
    DispList(L);
    printf("当前链表长度为：%d \n", ListLength(L));

    int i = 3;
    GetElem(L, i, e);

    printf("位置%d的元素，对应的元素值：%c", i,e);

    // 销毁线性表
    DestroyList(L);

    return 0;
}