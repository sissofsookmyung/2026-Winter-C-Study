// 백준 silver5 자료구조

#include <stdio.h>

// 최대 후보의 수가 50명으로 정해져 있기 때문에 쉽게 배열을 선언할 수 있다.
// 다솜의 표는 변수로, 다른 후보군들은 배열에 저장한 뒤 탐욕적 알고리즘을 적용한다.
// 다른 후보군에서 최대값을 구한 뒤, 다솜이가 가진 표가 많아질 때까지 표를 뺏어간다.

int main() {
	int n;
	int dasom;
	int max_idx = 0, count = 0;
	int arr[51];

	scanf("%d", &n);
	scanf("%d", &dasom);

	for (int i = 0; i < n-1; i++) {
		scanf("%d", &arr[i]);
	}

	// 다솜이만 있을 경우의 예외 처리
	if (n == 1) {
		printf("0\n");
		return 0;
	}

	while (true) {
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[max_idx]) {
				max_idx = i;
			}
		}
		if (arr[max_idx] < dasom) {
			break;
		}
		arr[max_idx]--;
		dasom++;
		count++;
	}
	printf("%d\n", count);

	return 0;
}