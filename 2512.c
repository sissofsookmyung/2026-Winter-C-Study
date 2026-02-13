#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void) {

    int N, M, i;

    scanf("%d", &N); //N 입력받아 저장
    
    int max = 0; //최댓값 초기화
    int* request = (int*)malloc(sizeof(int) * N); //N개 개수 맞춰서 메모리 할당
    for (i = 0; i < N; i++) { //N개의 값 입력받아서
        scanf("%d", &request[i]); //각 인덱스에 저장
        if (max < request[i]) max = request[i]; //값이 최댓값보다 크면 max값 변경
    }

    scanf("%d", &M); //M 입력받아 저장

    int left= 0;
    int right=max;
    int result = 0;

    while (left <= right) { //이진탐색 시작
        int mid = (left + right) / 2;

        long sum = 0;
        for (i = 0; i < N; i++) { //request 배열 하나씩 돌며
            if (request[i] > mid) //mid값보다 값이 크면 sum에 mid값을 더하기
                sum += mid;
            else //mid값보다 값이 작으면 sum에 request[i]값 그대로 더하기
                sum += request[i];
        }

        if (sum < M) { //sum이 M보다 작으면 result에 mid값 저장 후 더 큰 mid를 찾아 다시 while문으로
            result = mid;
            left = mid + 1;
        }
        else if (sum > M) { //sum이 M보다 크면 더 작은 mid를 찾아 다시 while문으로
            right = mid - 1;
        }
        else { //sum==M이면 rsult에 mid값 저장 후 바로 while문 탈출
            result = mid;
            break;
        }
    }

    printf("%d", result); //최종 result 출력
    free(request); //동적 메모리 해제
    return 0;
}