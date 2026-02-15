#include <stdio.h>
#include <stdlib.h>

// qsort 비교함수: 오름차순 정렬용
int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;  // a의 값
    int y = *(const int *)b;  // b의 값
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// 정렬된 arr에서 target 존재하면 1, 없으면 0
int binary_search(const int *arr, int n, int target) {
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;  // 중앙 인덱스

        if (arr[mid] == target) return 1;  // 찾음
        if (arr[mid] < target) lo = mid + 1;  // 오른쪽으로
        else hi = mid - 1;  // 왼쪽으로
    }
    return 0;  // 끝까지 못 찾음
}

int main(void) {
    int N, M;
    scanf("%d", &N);

    int *cards = (int *)malloc(sizeof(int) * N);  // 카드 배열
    for (int i = 0; i < N; i++) scanf("%d", &cards[i]);

    qsort(cards, N, sizeof(int), cmp_int);  // 이분탐색하려면 정렬 필수

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);

        printf("%d", binary_search(cards, N, x));  // 존재 여부 출력
        if (i != M - 1) putchar(' ');  // 공백 처리
    }
    putchar('\n');

    free(cards);  // 메모리 해제
    
    return 0;
}
