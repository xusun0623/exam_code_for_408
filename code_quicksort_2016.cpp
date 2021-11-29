#include <stdio.h>
#include <stdlib.h>
#include <cstring>

void printArr(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int Partition(int A[], int low, int high) {
	//快速排序
	int pivot = A[low]; //选取第一个作为枢轴
	while (low < high) {
		while (low < high && A[high] >= pivot)
			high--;
		A[low] = A[high];
		while (low < high && A[low] <= pivot)
			low++;
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}
void QuickDivideSort(int A[], int low, int high, int n) {
	if (low < high) {
		int pivot = Partition(A, low, high);
		if (pivot < n / 2)//划分出n/2的位置
			QuickDivideSort(A, pivot + 1, high, n);
		else
			QuickDivideSort(A, low, pivot - 1, n);
	}
}

int main() {
	int sort[] = { 2, 3, 3, 5, 6, 7, 1, 1, 1, 1, 1 };
	int n = sizeof(sort) / 4;
	QuickDivideSort(sort, 0, n - 1, n);
	printArr(sort, 11);
	return 0;
}
