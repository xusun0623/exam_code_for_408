#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void min_integer(int a[], int n) {
    int* tmp = (int*)malloc(4 * n);//动态分配数组空间
    memset(tmp, 0, n * 4);//空间置0
    int i;
    for (i = 0;i < n;i++) {
        if (a[i] <= n && a[i] > 0) {
            tmp[a[i] - 1] = 1;//将对应map位的元素置为1
        }
    }
    for (i = 0;i < n;i++) {//遍历得到第一个缺失的正整数
        if (tmp[i] == 0)break;
    }
    printf("%d", i + 1);
}

int main() {
    int a[] = { -5,3,2,3 };
    min_integer(a, sizeof(a) / 4);
    return 0;
}