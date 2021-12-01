#include<stdio.h>
#include<stdlib.h>

void reverse(int a[], int start, int end) {
    //逆置start～end之间的所有数
    int i = 0;
    while (start + i < end - i) {
        int tmp = a[start + i];
        a[start + i] = a[end - i];
        a[end - i] = tmp;
        i++;
    }
}

void move(int a[], int p, int length) {
    reverse(a, 0, p - 1);
    reverse(a, p, length - 1);
    reverse(a, 0, length - 1);
}

int main() {
    int a[] = { 1,2,3,4,5,6,7,8,9,10 };
    move(a, 7, 10);
    return 0;
}