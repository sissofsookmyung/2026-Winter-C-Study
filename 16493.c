#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;            // 두 값 중 큰 값 반환
}

int main() {
    int N, M;                        // N: 남은 일 수, M: 챕터 수
    scanf("%d %d", &N, &M);

    int day[21];                     // 각 챕터를 읽는 데 필요한 일 수
    int page[21];                    // 각 챕터의 페이지 수

    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &day[i], &page[i]); // 챕터 정보 입력
    }

    int dp[21][201] = { 0 };           // dp[i][j]: i번째 챕터까지, j일 사용 시 최대 페이지

    for (int i = 1; i <= M; i++) {           // 챕터 하나씩 고려
        for (int j = 0; j <= N; j++) {       // 사용 가능한 일 수
            dp[i][j] = dp[i - 1][j];         // i번째 챕터를 안 읽는 경우

            if (j >= day[i]) {               // i번째 챕터를 읽을 수 있다면
                dp[i][j] = max(dp[i][j],
                    dp[i - 1][j - day[i]] + page[i]);
            }
        }
    }

    printf("%d\n", dp[M][N]);         // M개 챕터, N일 안에서 최대 페이지 수 출력

    return 0;
}