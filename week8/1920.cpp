// 백준 silver4 자료 구조

#include <stdio.h>
#include <stdlib.h>

// 문제 유형을 파악하였을 때, 지난 번에 풀이하였던 10815번과 유형이 유사하여 출력 방식만 조정하였다.
// 그러나, 문제 채점 시 오답으로 처리되어 문제 조건을 확인하였다. 이를 통해 하나의 힌트를 얻어낼 수 있었는데, 정수의 범위가 -2^31 ~ 2^31이었기 때문에
// 기존에 사용하던 뺄셈을 활용하여 정렬하는 cmp 함수는 intiger overflow가 발생할 수 있었다.
// 따라서, 이를 조건문을 활용하여 다시 처리해주었다.

int cmp(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	if (n1 > n2) return 1;
	else if (n1 < n2) return -1;
	else return 0;
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
		printf("%d\n", bi_search(arr, n, s));
	}

	free(arr);

	return 0;
}