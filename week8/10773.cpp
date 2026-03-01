// 백준 silver4 자료 구조

#include <stdio.h>
#include <stdlib.h>

// 0을 입력 받았을 때, 가장 최근에 입력한 수를 삭제한다는 것에서 후입선출의 스택을 사용해야 함을 알 수 있다.
// 0을 입력 받으면 포인터를 앞으로 하나 옮겨 해당 지점부터 다시 입력한 값을 저장하도록 구현하면 될 것이다.
// 숫자를 입력 받는다면 그대로 top_idx를 늘리고 해당 자리에 저장하면 될 것이다.

int main() {
	int k;
	int stack[100000];
	int top_idx = -1;

	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int n;
		scanf("%d", &n);

		// 0이 들어왔을 때, 지워야 할 숫자가 항상 존재하는 것은 보장되므로
		if (n == 0) {
			top_idx--;
		}
		else {
			stack[++top_idx] = n;
		}
	}

	// 한 번에 입력할 수 있는 정수의 가장 큰 값이 100만이며, 그 개수는 10만개가 될 수 있으므로 자료형은 long long을 사용한다.
	long long sum = 0;
	for (int i = 0; i <= top_idx; i++) {
		sum += stack[i];
	}
	printf("%lld\n", sum);

	return 0;
}