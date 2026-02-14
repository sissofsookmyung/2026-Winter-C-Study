#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////
//작성자: 김수완
//작성일: 2026-02-14
//1912: 연속합
////////////////////////////////////////
// 1.현재 위치에서 가질 수 있는 최대 합은 이전까지의 최대 합 + 현재 값 혹은 현재 값 중 더 큰 값이다.
// 2. 수열 한 번만 훑고, 중복계산 방지한다
// 3. 매 단계마다 구한 dp[i] 값들 중 가장 큰 값을 별도의 변수(result)에 담아 마지막에 출력한다.
////////////////////////////////////////

#include <stdio.h>

// 두 수 중 더 큰 값을 반환하는 함수
int get_max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n;
    int arr[100001];
    int dp[100001];

    // 입력 받기
    if (scanf_s("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    // 초기값 설정: 첫 번째 원소의 최대 연속합은 자기 자신
    dp[0] = arr[0];
    int result = dp[0];

    // DP 진행
    for (int i = 1; i < n; i++) {
        // (이전까지의 합 + 현재 숫자)와 (현재 숫자 단독) 중 큰 것을 선택
        dp[i] = get_max(dp[i - 1] + arr[i], arr[i]);

        // 전체 결과값 갱신
        if (dp[i] > result) {
            result = dp[i];
        }
    }

    // 결과 출력
    printf("%d\n", result);

    return 0;
}