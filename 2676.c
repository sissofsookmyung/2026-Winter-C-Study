#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int k;              // 집합 S의 크기
int S[13];          // 집합 S에 들어 있는 숫자들
int pick[6];        // 현재 선택한 6개의 숫자

// start: 다음에 고를 수 있는 시작 인덱스
// depth: 현재까지 고른 숫자의 개수
void dfs(int start, int depth) {
    // 숫자 6개를 다 골랐으면 출력
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", pick[i]);
        }
        printf("\n");
        return;
    }

    // start부터 k-1까지 탐색하면서 숫자 선택
    for (int i = start; i < k; i++) {
        pick[depth] = S[i];     // 현재 숫자 선택
        dfs(i + 1, depth + 1);  // 다음 숫자는 i+1부터 선택
    }
}

int main() {
    while (1) {
        scanf("%d", &k);        // k 입력
        if (k == 0) break;      // 0이면 입력 종료

        for (int i = 0; i < k; i++) {
            scanf("%d", &S[i]); // 집합 S 입력
        }

        // 조합 생성 시작
        dfs(0, 0);

        printf("\n");           // 테스트 케이스 사이 빈 줄 출력
    }

    return 0;
}