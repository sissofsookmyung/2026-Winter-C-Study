#define _CRT_SECURE_NO_WARNINGS     
#include <stdio.h>                

// nCr을 계산하는 함수
long long comb(int n, int r) {
    long long result = 1;          // 조합 결과를 저장할 변수

    // nCr = nC(n-r)이므로 계산량을 줄이기 위해 더 작은 값 사용
    if (r > n - r)
        r = n - r;

    // nCr = n*(n-1)*...*(n-r+1) / r!
    for (int i = 0; i < r; i++) {
        result = result * (n - i) / (i + 1); // 한 단계씩 곱하고 나눔
    }

    return result;
}

int main() {
    int N, M;                      // N: 과일 종류 수, M: 훔칠 총 과일 개수

    scanf("%d", &N);
    scanf("%d", &M);

    // 모든 종류의 과일을 최소 1개 이상 훔치는 경우의 수
    // M을 N개의 양의 정수로 나누는 경우의 수
    // 조합 공식 C(M-1, N-1)
    printf("%lld\n", comb(M - 1, N - 1));

    return 0;
}