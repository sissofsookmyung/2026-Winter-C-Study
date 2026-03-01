#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    int k, n;
    scanf("%d %d", &k, &n);  // 현재가지고있는 랜선개수와 필요한 랜선 개수 입력받기
    long long leng[10000];  // 랜선들의 길이를 저장하는 배열
    long long max = 0;  // 가장 긴 랜선의 길이

    for (int i = 0; i < k; i++) {
        scanf("%lld", &leng[i]);  // 길이 입력받기 
        if (leng[i] > max) {  // 가장 긴 랜선의 길이 구하기
            max = leng[i];
        } 
    }

    // 범위 설정
    long long left = 1;
    long long right = max;
    long long result = 0;

    // 이분탐색
    while (left <= right) {  //가능한 최댓값을 찾아간다
        long long mid = (left + right) / 2;
        long long total = 0; 

        for (int i = 0; i < k; i++) {
            total += leng[i] / mid;  // mid로 잘라서 만들수있는 랜선의 총개수
        }

        if (total >= n) {  // 범위 좁히기 
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;  
        }
    }
    printf("%lld", result);  // 결과 출력
    return 0;
}
