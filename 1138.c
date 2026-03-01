#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);

    // n의 최댓값은 10이므로
    int arr[11];  // 왼쪽에 큰사람 수 입력받는 배열
    int result[11] = {0}; // 결과 저장할 배열. 초기화하기

    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);  // 입력받기
    }

   
    for (int i = 1; i <= n; i++) { // 키작은 순서대로 1번부터 차례대로 배치
        int count = 0;  // 빈자리개수 저장하는 변수
        for (int j = 1; j <= n; j++) {   // 처음부터 끝까지 탐색
            if (result[j] == 0) {   // 만약 빈자리면
                if (count == arr[i]) {  // 지금까지 지나친 빈자리 개수와 키가 같다면
                    result[j] = i;  // 앉히기
                    break;   // 다음 사람으로 넘어감
                }
                count++;  // 일치하지 않으면 빈자리 하나 추가
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", result[i]);  // 결과 출력 
    }
    return 0;
}
