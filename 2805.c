#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////
//작성자: 김수완
//작성일: 2026-02-14
//2805: 나무 자르기
////////////////////////////////////////
// 1.이분 탐색 활용: 0부터 가장 큰 나무 높이 사이에서 절단기 높이를 이분 탐색으로 결정.
// 2. 데이터 타입은 long long으로 설정.
// 3. 최댓값 도출: 얻은 나무의 합이 M 이상인 경우 중, 절단기 높이 H의 최댓값을 계속 갱신하며 정답을 찾기.
////////////////////////////////////////

int main() {
    int N;
    long long M;
    scanf_s("%d %lld", &N, &M);

    long long* trees = (long long*)malloc(sizeof(long long) * N);
    long long max_height = 0;

    for (int i = 0; i < N; i++) {
        scanf_s("%lld", &trees[i]);
        if (trees[i] > max_height) max_height = trees[i];
    }

    long long low = 0, high = max_height;
    long long result = 0;

    // 이분 탐색 시작
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) {
                sum += (trees[i] - mid);
            }
        }

        if (sum >= M) {      // 나무를 충분히 얻었으면, 높이를 더 높여본다
            result = mid;
            low = mid + 1;
        }
        else {             // 나무가 부족하면, 높이를 낮춰야 한다
            high = mid - 1;
        }
    }

    printf("%lld\n", result);
    free(trees);
    return 0;
}