#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int size;
int result[6];
int* num;

//depth는 몇 번째 번호까지 탐색했는가. 3번째인가 4번째인가를 표시하는 변수
void lotto(int start, int depth) {
    // 종료 조건: 6개를 모두 선택했을 때 출력
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }

    // 반복 조건: 현재 인덱스부터 전체 개수까지 탐색
    for (int i = start; i < size; i++) {
        result[depth] = num[i];
        lotto(i + 1, depth + 1); // 다음 숫자를 선택하기 위해 재귀 호출, 다음 번호 숫자 탐색
    }
}

int main() {
    while (1) {
        // 개수를 입력받음
        if (scanf("%d", &size) != 1 || size == 0) {
            break;
        }

        num = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &num[i]);
        }

        lotto(0, 0); // 0번 인덱스부터 시작
        printf("\n"); // 케이스 사이의 빈 줄 출력

        free(num); // 할당한 메모리 해제
    }
    return 0;
}