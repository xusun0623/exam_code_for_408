#include<stdio.h>
#include<stdlib.h>

int getMiddle(int a[], int start, int end) {
    return a[(start + end) / 2];
}

int getDoubleMid(int s1[], int s2[], int length) {
    int i = 0, log_i = 1;
    while (log_i * 2 < length) { i++;log_i *= 2; }
    int start_a = 0, start_b = 0, end_a = length - 1, end_b = length - 1;
    while (i-- && start_a < end_a && start_b < end_b) {
        int mid_a = getMiddle(s1, start_a, end_a);
        int mid_b = getMiddle(s2, start_b, end_b);
        if (mid_a < mid_b) {
            start_a = (start_a + end_a) / 2 + 1;
            end_b = (start_b + end_b) / 2 - 1;
        }
        else {
            start_b = (start_b + end_b) / 2 + 1;
            end_a = (start_a + end_a) / 2 - 1;
        }
    }
    return s1[start_a] < s2[start_b] ? s1[start_a] : s2[start_b];
}

int main() {
    int s1[] = { 1,2,3,8,9 };
    int s2[] = { 4,5,6,7,10 };
    int length = 5;
    int ret = getDoubleMid(s1, s2, length);
    return 0;
}