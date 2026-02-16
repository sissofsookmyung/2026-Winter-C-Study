// 백준 silver5 자료구조

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문제 조건 상 현재 회사에 있는 사람의 이름을 역순으로 출력해야 하므로 정렬을 사전 역순으로 한다.
// 이후, 퇴근 시에는 무조건 enter-leave로 2번 작성되어야 하므로 같은 이름이 2번 연속 등장하는 경우
// 넘어가고, 한 번만 등장하면 출력하도록 한다.

// 이름을 담아둘 배열 전역으로 선언
char names[1000000][6];
// qsort를 사용하기 위한 비교 함수 - 대소문자 비교 조건 적용
int cmp(const void* a, const void* b) {
	return strcmp((char*)b, (char*)a);
}

int main() {
	int n;
	char status[6];
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s", names[i], status);
	}

	qsort(names, n, sizeof(names[0]), cmp);

	for (int i = 0; i < n; i++) {
		if (cmp(names[i], names[i + 1]) == 0 && i + 1 <= n) {
			i++;
		}
		else {
			printf("%s\n", names[i]);
		}
	}

	return 0;
}