#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int k;                                  // 찾고 싶은 소수의 순서 (k번째)
    scanf("%d", &k);                        // k 입력

    int limit = 8000000;                    // k번째 소수를 찾기 위한 상한값 
    int isPrime[8000001];                   // 소수 여부 배열 (0: 소수 아님, 1: 소수)

    for (int i = 2; i <= limit; i++) {
        isPrime[i] = 1;                     // 처음에는 모두 소수라고 가정
    }

    for (int i = 2; i * i <= limit; i++) {  
        if (isPrime[i]) {                   // i가 소수라면
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = 0;             // i의 배수는 소수가 아님
            }
        }
    }

    int count = 0;                          // 지금까지 찾은 소수의 개수

    for (int i = 2; i <= limit; i++) {      // 2부터 차례대로 확인
        if (isPrime[i]) {                   // 소수라면
            count++;                        // 소수 개수 증가
            if (count == k) {               // k번째 소수라면
                printf("%d\n", i);          // 해당 소수 출력
                break;                      
            }
        }
    }

    return 0;                               
}