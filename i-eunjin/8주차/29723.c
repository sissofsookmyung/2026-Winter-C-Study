#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 과목 정보를 저장할 구조체
typedef struct {
    char name[21];
    int score;
    int is_open; // 과목 공개 여부(1: 공개, 0: 비공개)
} Subject;

// 점수 기준 오름차순 정렬 함수
int compare(const void* a, const void* b) {
    Subject* s1 = (Subject*)a;
    Subject* s2 = (Subject*)b;

    // 점수가 낮은 순서대로 정렬
    return s1->score - s2->score;
}

Subject all[10000];    // 브실이가 수강한 전체 과목
Subject hidden[10000]; // 공개되지 않은 과목들만 따로 저장

int main() {
    int n, m, k;
    // 브실이가 수강한 과목 수(n), 요구 과목 수(m), 공개된 과목 수(k) 입력 받기
    scanf("%d %d %d", &n, &m, &k);

    // 브실이가 수강한 과목 이름과 점수 입력 받기
    for (int i = 0; i < n; i++) {
        scanf("%s %d", all[i].name, &all[i].score);
        all[i].is_open = 0; // 공개 여무는 일단 0
    }

    int fixed_score = 0; // 공개된 과목의 점수 합계 -> 최종 점수 계산에 고정으로 들어감
    for (int i = 0; i < k; i++) {
        // 공개된 과목 이름 입력 받기
        char opened[21];
        scanf("%s", opened);

        // 공개된 이름과 일치하는 과목이면 고정 점수에 더해줌
        for (int j = 0; j < n; j++) {
            if (strcmp(all[j].name, opened) == 0) {
                fixed_score += all[j].score;
                all[j].is_open = 1; // 공개 여부 1로
                break;
            }
        }
    }

    int count = 0; // 공개되지 않은 과목 개수
    for (int i = 0; i < n; i++) {
        // 공개되지 않은 과목들만 hidden에 저장
        if (all[i].is_open == 0) {
            hidden[count] = all[i];
            count++;
        }
    }

    // 공개되지 않은 과목들 점수 기준으로 오름차순 정렬
    qsort(hidden, count, sizeof(Subject), compare);

    int min = 0; // 추가로 선택할 과목들의 최소 점수 합
    int max = 0; // 추가로 선택할 과목들의 최대 점수 합
    int pick = m - k; // 더 골라야 하는 과목 수

    // 비공개 과목 오름차순 정렬되어 있음
    // 앞에서 부터 더하면 min
    // 뒤에서 부터 더하면 max 구할 수 있음
    for (int i = 0; i < pick; i++) {
        min += hidden[i].score;
        max += hidden[count - 1 - i].score;
    }

    // 최종 결과 출력(고정 점수 + min/max)
    printf("%d %d\n", fixed_score + min, fixed_score + max);

    return 0;
}