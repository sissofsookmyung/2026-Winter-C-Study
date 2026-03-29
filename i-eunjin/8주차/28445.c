#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 몸통과 꼬리 색상을 저장할 구조체
typedef struct {
    char body[21];
    char tail[21];
} Color;

int compare(const void* a, const void* b) {
    Color* c1 = (Color*)a;
    Color* c2 = (Color*)b;

    // 몸통 색이 다르면 몸통을 사전 순으로 정렬
    if (strcmp(c1->body, c2->body) != 0) {
        return strcmp(c1->body, c2->body);
    }
    // 몸통 색이 같으면 꼬리 색을 사전 순으로 정렬
    return strcmp(c1->tail, c2->tail);
}

int main() {
    char colors[4][21]; // 색 4개 저장
    for (int i = 0; i < 4; i++) {
        scanf("%s", colors[i]);
    }

    Color list[16]; // 가능한 모든 조합 저장
    int count = 0;

    // 가능한 모든 조합 생성
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(list[count].body, colors[i]);
            strcpy(list[count].tail, colors[j]);
            count++;
        }
    }

    // 사전 순으로 정렬
    qsort(list, count, sizeof(Color), compare);

    // 중복이 아닌 조합만 출력
    for (int i = 0; i < count; i++) {
        // 현재 조합이 이전 조합과 같으면 건너뜀
        if ((i > 0) && (strcmp(list[i].body, list[i - 1].body) == 0) && (strcmp(list[i].tail, list[i - 1].tail) == 0)) {
            continue;
        }
        printf("%s %s\n", list[i].body, list[i].tail);
    }

    return 0;
}