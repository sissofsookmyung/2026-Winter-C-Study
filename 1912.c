#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);  // 수열 크기 입력받기

    // n의 최댓값은 100000이므로
    int arr[100001];  // 수열 저장할 배열
    int sum[100001];  // 최댓값을 저장해가는 배열

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);  // 수열 입력받기
    }

    sum[1] = arr[1];  // 첫번째는 비교할 수 없으므로 자기자신임
    int result = sum[1];  // 결과를 저장할 변수

    for (int i = 2; i <= n; i++) { // 두번째부터 계산시작

        // 현재 숫자를 더하는 것이 더 이득이면 더하기
        if (sum[i - 1] + arr[i] > arr[i]) {
            sum[i] = sum[i - 1] + arr[i]; 
        }
        else {  // 전까지 더한 것이 음수였다면 현재 인덱스부터 새로 시작하는 것이 이득
            sum[i] = arr[i]; 
        }

        if (sum[i] > result) {
            result = sum[i];  // 최댓값 계산
        }
    }
    printf("%d", result);
    return 0;

}
