// 백준 silver4 자료구조

// 해당 문제의 첫 접근은 두 괄호의 갯수를 세고, 해당 갯수가 동일한 경우만 YES를 출력하는 것이었다.
// 그러나, 위의 접근법은 )(와 같은 케이스를 해결할 수 없으므로, 실시간 검증을 통해 (가 등장하는 경우를 1,
// )가 등장하는 경우를 -1로 설정하여 -1이 되는 경우 바로 NO를 출력하고, 0이 되는 경우만 YES를 출력하도록 한다.

#include <stdio.h>

int main() {
	char arr[51];
	int n = 0;

	scanf("%s", arr);
	
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] == '(') {
			n++;
		}
		else {
			n--;
		}
		if (n < 0) {
			printf("NO\n");
			return 0;
		}
	}
	if (n > 0) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	
	return 0;
}