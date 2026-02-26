#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);                // 파티 일수

    long long A[1000];              // 각 날의 간식 평점
    long long dp[1000];             // dp[i]: i번째 날 간식을 먹었을 때 최대 만족도

    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);       // 간식 평점 입력
    }

    long long answer = 0;           // 최대 만족도

    for (int i = 0; i < N; i++) {
        dp[i] = A[i];               // i번째 날 처음 먹는 경우

        for (int j = 0; j < i; j++) {
            // 이전 간식보다 평점이 높을 경우만 선택 가능
            if (A[j] < A[i]) {
                if (dp[j] + A[i] > dp[i]) {
                    dp[i] = dp[j] + A[i];
                }
            }
        }

        if (dp[i] > answer) {
            answer = dp[i];         // 최대값 갱신
        }
    }

    printf("%lld\n", answer);       // 결과 출력
    return 0;
}