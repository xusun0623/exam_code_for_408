#include<stdio.h>
#include<stdlib.h>

//获取三个数的绝对值距离
int getDis(int a, int b, int c) {
    int ab = (a - b) > 0 ? (a - b) : (b - a);
    int bc = (b - c) > 0 ? (b - c) : (c - b);
    int ac = (a - c) > 0 ? (a - c) : (c - a);
    if (ab >= bc && ab >= ac)return ab * 2;
    if (bc >= ab && bc >= ac)return bc * 2;
    if (ac >= ab && ac >= bc)return ac * 2;
}

//获取三个数中的最小值
int getMin(int a, int b, int c) {
    if (a <= b && a <= c)return 0;
    if (b <= c && b <= a)return 1;
    if (c <= a && c <= b)return 2;
}

void getAbsDis(int s1[], int s2[], int s3[], int l1, int l2, int l3) {
    int min = INT_MAX;
    int p1 = 0, p2 = 0, p3 = 0;
    while (p1 < l1 && p2 < l2 && p3 < l3) {
        int a = s1[p1], b = s2[p2], c = s3[p3];
        if (min > getDis(a, b, c)) {
            min = getDis(a, b, c);
        }
        int flag = getMin(a, b, c);
        if (flag == 0)p1++;
        if (flag == 1)p2++;
        if (flag == 2)p3++;
    }
    printf("最小值为:%d", min);
}

int main() {
    int s1[] = { -1,0,9 };
    int s2[] = { -25,-10,9,11 };
    int s3[] = { 2,9,17,30,41 };
    getAbsDis(s1, s2, s3, 3, 4, 5);
    return 0;
}