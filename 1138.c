#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int cnt[11];
    int line[11];
    int size = 0;  // 현재 줄에 서 있는 사람 수

    for (int i = 1; i <= N; i++) {
        scanf("%d", &cnt[i]);
    }

    for (int h = N; h >= 1; h--) {//키 큰 사람부터 반복

        // 오른쪽으로 한 칸씩 밀기
        for (int i = size; i > cnt[h]; i--) {
            line[i] = line[i - 1];
        }

        // cnt[h] 위치에 h 삽입
        line[cnt[h]] = h;
        size++;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", line[i]);
    }

    return 0;
}
