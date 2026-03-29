#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[6];   // 사람 이름 최대 다섯 글자
} Log;

// 이름 사전 역순으로 정렬
int compare(const void* a, const void* b) {
    Log* l1 = (Log*)a;
    Log* l2 = (Log*)b;

    return strcmp(l2->name, l1->name);
}

Log list[1000001];

int main() {
    int n;
    scanf("%d", &n);    // 출입 기록 수 입력 받기

    char status[10];    // 현재 상태("enter" or "leave")
    for (int i = 0; i < n; i++) {
        // 이름과 현재 상태 입력 받음
        scanf("%s %s", list[i].name, status);
    }

    // 이름을 기준으로 사전 역순 정렬
    qsort(list, n, sizeof(Log), compare);

    // 현재 회사에 남아있는 사람만 출력
    // 정렬된 리스트에서 이름이 연속으로 나온다 -> enter하고 leave한 것 -> 회사에 남아있지 X
    for (int i = 0; i < n; i++) {
        // 현재 이름과 다음 이름이 같으면 그 다음 기록도 건너뛰도록 i++
        if ((i < n - 1) && (strcmp(list[i].name, list[i + 1].name) == 0)) {
            i++;
        }
        // 현재 이름과 다음 이름이 다르다 -> 현재 회사에 남아있는 사람임(leave 기록 X)
        else {
            printf("%s\n", list[i].name);
        }
    }

    return 0;
}