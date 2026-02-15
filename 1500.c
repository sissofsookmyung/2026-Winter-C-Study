#include <stdio.h>

int main() {
    long long S;
    int K;
    scanf("%lld %d", &S, &K);

    long long b = S / K; //K-r개
    int r = S % K//b +1 이 r개 => 숫자 차이가 적을수록 곱이 커짐

    long long result = 1;

    for (int i = 0; i < K - r; i++) {//K-r 개는 b가 그대로 곱해짐
        result *= b;
    }

    for (int i = 0; i < r; i++) {//r 개는 S/K +1 이 곱해진다
        result *= (b + 1);
    }

    printf("%lld", result);
    return 0;
}
