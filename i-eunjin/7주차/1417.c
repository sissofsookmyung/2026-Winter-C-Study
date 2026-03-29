#include <stdio.h>
#include <stdlib.h>

// 득표 수를 기준으로 내림차순 정렬
int compare(const void* a, const void* b) {
    int* n1 = (int*)a;
    int* n2 = (int*)b;

    return *n2 - *n1;
}

int main() {
    int n, dasom;
    // 후보 수 n 입력 받기
    scanf("%d", &n);

    // 다솜이의 득표 수 입력 받기
    scanf("%d", &dasom);

    // 후보가 다솜이뿐이라면 사람 매수할 필요 X
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    // 나머지 후보들의 득표 수 저장
    int others[50];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &others[i]);
    }

    // 매수해야 하는 사람의 수
    int count = 0;

    // 다솜이가 전체에서 득표 수 1위가 될 때까지 반복
    while (1) {
        // 나머지 후보들 중 득표 수 1위가 맨 앞에 오도록 정렬
        qsort(others, n - 1, sizeof(int), compare);
        // 다솜이가 다른 후보 중 1위보다 득표 수가 많으면 종료
        if (dasom > others[0]) {
            break;
        }
        // 다솜이가 가장 많지 않다면 현재 1위의 표를 하나 빼서 다솜이에게 줌
        others[0]--;
        dasom++;

        count++;    // 매수해야 하는 사람 증가
    }

    // 최종 매수해야 하는 사람 수 출력
    printf("%d\n", count);

    return 0;
}