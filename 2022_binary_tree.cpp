#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100

typedef struct {
    int Sqlistdata[MaxSize];
    int num;
} Sqlist;

bool T = true;
void inorder(Sqlist a, int i) {
    if (i >= a.num || a.Sqlistdata[i] == -1 || !T) {
        return;
    }
    int k = a.Sqlistdata[i];
    inorder(a, i * 2 + 1);
    if (k < a.Sqlistdata[i * 2 + 1]) {
        T = false;
        return;
    }
    inorder(a, i * 2 + 2);
}

int main() {
    Sqlist s = Sqlist();
    int a[] = {4, 2, 6, 1, 3, 5, 7};  //高度为3的满二叉排序树
    s.num = 7;
    for (int i = 0; i < s.num; i++) {
        s.Sqlistdata[i] = a[i];
    }
    inorder(s, 0);
    printf(T ? "是二叉搜索树" : "不是二叉搜索树");
    return 0;
}
