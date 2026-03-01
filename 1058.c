#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);  // 사람 수 입력받기

    char arr[51][51];  // n의 최댓값은 50이므로
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);   // n명의 친구관계 한줄씩 입력받기
    }

    int max = 0;  // 최댓값을 저장하는 변수
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;  // 자기자신은 건너뛰기

            if (arr[i][j] == 'Y') {  // 1친구 구하기
                count++;
            }
            else {
                for (int k = 0; k < n; k++) {
                    if (arr[i][k] == 'Y' && arr[k][j] == 'Y') {  // 2친구 구하기
                        count++;
                        break; // 중복방지
                    }
                }
            }
            
        }
        if (count > max) {
            max = count;  // 최댓값 구하기
        }
    }
    printf("%d\n", max);  // 출력
    return 0;
}
