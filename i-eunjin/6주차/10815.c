#include <stdio.h>
#include <stdlib.h>

// 오름차순 정렬
int compare(const void* a, const void* b) {
    int* n1 = (int*)a;
    int* n2 = (int*)b;

    return *n1 - *n2;
}

int main() {
    int n, m;

    // 상근이가 가지고 있는 숫자 카드의 개수 입력 받기
    scanf("%d", &n);

    // n개의 카드를 저장할 메모리 동적 할당
    int* cards = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    // 이분 탐색을 위한 오름차순 정렬
    qsort(cards, n, sizeof(int), compare);

    // 확인할 카드의 개수 입력 받기
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int target, found = 0;
        scanf("%d", &target);   // 찾아야 하는 숫자 입력 받기

        // 이분 탐색 시작
        int left = 0;   // 처음부터
        int right = n - 1;  // 끝까지

        while (left <= right) {
            int mid = (left + right) / 2;   // 중간 위치 인덱스
            // 찾았을 때
            if (cards[mid] == target) {
                found = 1;
                break;
            }
            // 아직 못 찾았는데 중간 값이 찾는 값보다 작으면 오른쪽 절반 탐색
            else if (cards[mid] < target) {
                left = mid + 1;
            }
            // 중간 값이 찾는 값보다 크면 왼쪽 절반 탐색
            else {
                right = mid - 1;
            }
        }
        // 찾았으면 1, 못 찾았으면 0 출력
        printf("%d ", found);
    }
    free(cards);

    return 0;
}