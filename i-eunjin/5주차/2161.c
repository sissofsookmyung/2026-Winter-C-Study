#include <stdio.h>


int cards[2000]; // 최대 1000장의 카드 중 반은 버리고 반은 뒤로 보냄 = 최대 약 1500

int main() {
	int n;	// 정수 N의 크기를 담을 변수
	scanf("%d", &n); // 정수 N 입력 받음

	for (int i = 0; i < n; i++) {
		cards[i] = i + 1;	// 배열에 카드 N개 저장
	}

	int front = 0;	// 맨 앞을 가리킬 인덱스
	int rear = n;	// 맨 뒤를 가리킬 인덱스

	while (rear - front > 1) {	// 남은 카드가 1개보다 많을 때
		printf("%d ", cards[front]);	// 맨 앞 장을 버림, 예) 1번 카드 버림
		front++;	// 그 다음 장으로 이동, 예) 2번 카드로 이동

		cards[rear] = cards[front];	// 카드를 제일 아래로 옮김, 예) 2번 카드 맨 밒으로 옮김
		front++;	// 다음 장으로 이동
		rear++;	// 본래 가리키던 카드 뒤에 카드가 추가되었으니 한 칸 뒤로 가 가장 뒷 카드를 가리킴
	}
	printf("%d ", cards[front]);	// 마지막 남은 카드 버림

	return 0;
}