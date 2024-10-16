#include <iostream>
#include <vector>
using namespace std;

typedef int Elemtype;
const Elemtype MaxSize = 20;

// 顺序表类型定义
typedef struct {
    Elemtype date[MaxSize];
    int length;
} sqlist;

// 顺序表建立
void CreatList(sqlist *&l, Elemtype a[], int n) {
    int i = 0, k = 0;
    l = (sqlist *)malloc(sizeof(sqlist));
    while (i < n) {
        l->date[k] = a[i];
        k++;
        i++;
    }
    l->length = k;
}

// 有序表的二路归并算法
void UnionList(sqlist *la, sqlist *lb, sqlist *&lc) {
    int i = 0, k = 0, j = 0; // 定义i,j指针用来扫描la,lb,k用来记录lc的长度
    lc = (sqlist *)malloc(sizeof(sqlist));
    while (i < la->length && j < lb->length) {
        if (la->date[i] < lb->date[j]) {
            lc->date[k] = la->date[i];
            i++;
        } else {
            lc->date[k] = lb->date[j];
            j++;
        }
        k++;
    }
    // 当la未扫描完时
    while (i < la->length) {
        lc->date[k] = la->date[i];
        i++;
        k++;
    }
    // 当lb未扫描完时
    while (j < lb->length) {
        lc->date[k] = lb->date[j];
        j++;
        k++;
    }
    lc->length = k;
}

int main() {
    vector<Elemtype> a;
    vector<Elemtype> b;
    Elemtype num1, num2;
    cout << "请输入la的数据，输入-1表示输入结束: ";

    while (cin >> num1 && num1 != -1) {
        a.push_back(num1);
    }

    cout << "请输入lb的数据，输入-1表示输入结束: ";
    while (cin >> num2 && num2 != -1) {
        b.push_back(num2);
    }

    sqlist *la, *lb, *lc;
    CreatList(la, a.data(), a.size());
    CreatList(lb, b.data(), b.size());

    UnionList(la, lb, lc);

    cout << "lc的元素为: ";
    for (int i = 0; i < lc->length; i++) {
        cout << lc->date[i] << " ";
    }
    cout << endl;

    free(la);
    free(lb);
    free(lc);
   	system("pause");
    return 0;
}