#include <stdio.h>
#include <stdlib.h>

// 기둥 정보를 저장할 구조체
typedef struct {
    int x;  // 위치
    int h;  // 높이
} Pillar;

// qsort에서 사용할 비교 함수 (x 기준 오름차순 정렬)
int cmp(const void *a, const void *b) {
    Pillar *p = (Pillar *)a;
    Pillar *q = (Pillar *)b;
    return p->x - q->x;
}

int main(void) {
    int N;
    scanf("%d", &N);

    Pillar p[1000];

    // 입력 받기
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &p[i].x, &p[i].h);
    }

    // x 좌표 기준으로 정렬
    qsort(p, N, sizeof(Pillar), cmp);

    // 가장 높은 기둥의 인덱스 찾기
    int maxIdx = 0;
    for (int i = 1; i < N; i++) {
        if (p[i].h > p[maxIdx].h) {
            maxIdx = i;
        }
    }

    int area = 0;  // 최종 넓이 저장 변수

    // 왼쪽 → 최고 기둥까지 면적 계산
    int curH = p[0].h;  // 현재까지 본 최대 높이
    int curX = p[0].x;  // 그 높이가 시작된 위치

    for (int i = 1; i <= maxIdx; i++) {

        // 더 높은 기둥을 만나면
        if (p[i].h >= curH) {

            // 이전 위치부터 현재 위치까지
            // (가로 길이 × 현재 높이) 만큼 면적 추가
            area += (p[i].x - curX) * curH;

            // 기준 높이 갱신
            curH = p[i].h;
            curX = p[i].x;
        }
    }

    // 오른쪽 → 최고 기둥까지 면적 계산 (오른쪽에서 왼쪽으로 이동)
    curH = p[N - 1].h;
    curX = p[N - 1].x;

    for (int i = N - 2; i >= maxIdx; i--) {

        if (p[i].h >= curH) {

            // 오른쪽 위치에서 현재 위치까지
            area += (curX - p[i].x) * curH;

            // 기준 높이 갱신
            curH = p[i].h;
            curX = p[i].x;
        }
    }

    // 최고 기둥 면적 추가
    area += p[maxIdx].h;

    // 결과 출력
    printf("%d\n", area);

    return 0;
}