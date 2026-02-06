#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int S, K;

    // S: 만들고 싶은 총합
    // K: 정수의 개수
    scanf("%d %d", &S, &K);

    // S를 K개로 나눴을 때의 기본값
    // 모든 수를 base로 시작하면 합은 base * K
    int base = S / K;

    // 나머지 값
    // 이 나머지를 1씩 나누어 더해줘야 합이 정확히 S가 됨
    int rem = S % K;

    // 곱의 결과는 매우 커질 수 있으므로 long long 사용
    long long result = 1;

    // K개의 수를 만들어 곱하기
    for (int i = 0; i < K; i++) {

        // 나머지 개수만큼은 base + 1을 사용
        // ex) S=10, K=3 -> base=3, rem=1 -> 4,3,3
        if (i < rem)
            result *= (base + 1);
        else
            result *= base;
    }

    // 최대 곱 출력
    printf("%lld\n", result);

    return 0;
}
