#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 11

int main(void) {

    int N;
    int left[MAX];

    scanf("%d", &N); //N값을 입력받아 저장

    for (int i = 1; i <= N; i++) { //N번 자기보다 큰 사람이 몇명있는지 입력받아 저장 (이후 비교를 위해 index를 1부터)
        scanf("%d", &left[i]);
    }

    int array[MAX] = { 0 }; //최종 줄 순서를 담을 배열 초기화

    for (int p = 1; p <= N; p++) { //키가 가장 작은 사람(1)부터 큰 사람(N) 순으로

        int count = 0; //왼쪽 빈 자리 수를 셀 변수 count 초기화
        
        for (int idx = 0; idx <N; idx++) { //줄의 인덱스를 0부터 돌며
            if (array[idx] == 0) { //자리가 비어있는 경우
                if (count == left[p]) { //현재 왼쪽 빈자리 수가 주어진 정보와 동일하다면
                    array[idx] = p; //그 위치에 현재 사람(p)을 배치
                    break;
                }
                count++; //현재 왼쪽 빈자리 수가 주어진 정보와 다르다면 count +1 증가
            }
        }
    }

    for (int i = 0; i < N; i++) { //최종 줄 순서를 출력
        printf("%d ", array[i]);
    }
    
    return 0;
}