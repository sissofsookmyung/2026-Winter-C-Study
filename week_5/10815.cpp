// 백준 silver5 자료구조

#include <stdio.h>
#include <stdlib.h>

// 순차 탐색으로 진행하게 된다면 시간 초과로 실패하게 된다.
// 따라서, 이진 탐색 함수를 정의하여 탐색 시간을 줄인다.
// 이진 탐색을 위해서는 qsort를 이용하여 오름차순으로 정렬해야한다.

// qsort에 사용할 대소 비교 함수를 정의한다.


int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int bi_search(int arr[], int n, int s) {
	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == s) {
			return 1;
		}
		else if (arr[mid] > s) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return 0;
}

int main() {
	int n, m, s;

	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), cmp);

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &s);
		printf("%d ", bi_search(arr, n, s));
	}

	free(arr);

	return 0;
}