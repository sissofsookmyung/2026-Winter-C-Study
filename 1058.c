#include <stdio.h>

int main() {
    int N;
    char f[50][51]; // 친구 관계
    scanf("%d", &N);

    // 친구 관계 입력
    for (int i = 0; i < N; i++) {
        scanf("%s", f[i]);
    }

    int max = 0; // 최대 2-친구 수

    for (int i = 0; i < N; i++) {
        int cnt = 0; // i의 2-친구 수

        // 사람 j가 2-친구인지 확인
        for (int j = 0; j < N; j++) {
            if (i == j) continue; // 자기 자신 제외

            //  직접 친구
            if (f[i][j] == 'Y') {
                cnt++;
            }
            // 친구의 친구
            else {
                for (int k = 0; k < N; k++) {
                    if (f[i][k] == 'Y' && f[k][j] == 'Y') {
                        cnt++;
                        break; // 한 명만 있으면 충분
                    }
                }
            }
        }

        // 최댓값 구하기
        if (cnt > max) {
            max = cnt;
        }
    }

    printf("%d\n", max);
    return 0;
}
