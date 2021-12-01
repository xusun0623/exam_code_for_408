#include<stdio.h>
#include<stdlib.h>

int majority(int A[], int length) {
    int p = 0;
    int start = 0, count = 0;
    for (int j = 0;j < length;j++) {
        if (A[start] == A[j]) count++;
        else count--;
        if (count == 0 && j < length - 1) {
            start = ++j;
            count = 1;
        }
    }
    int mainElement = A[start];
    int countElement = 0;
    for (int j = 0;j < length;j++) {
        if (A[j] == mainElement)countElement++;
    }
    return countElement > length / 2 ? 1 : 0;
}

int main() {
    int A[] = { 1,1,0,0,0,1,1,1,0 };
    int isMajority = majority(A, 9);
    if (isMajority)printf("有主元素");
    else printf("没有主元素");
}