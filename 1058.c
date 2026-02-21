#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50
#define INF 100000

int main(void) {

    int N, i;
    char arr[MAX][MAX + 1]; //문자열 저장용 배열
    int dist[MAX][MAX];
    

    scanf("%d", &N); //N을 입력받아 저장

    for (int i = 0; i < N; i++) { //N명의 관계를 입력받아 각 행에 저장
        scanf("%s", arr[i]); 
    }

    for (i = 0; i < N; i++) {  //전체 배열을 돌며 초기 거리 초기화
        for (int j = 0; j < N; j++) {
            if (i == j) { //본인인 경우 거리=0
                dist[i][j] = 0;
            }
            else if (arr[i][j] == 'Y') { //관계가 있는 경우 거리=1
                dist[i][j] = 1;
            }
            else { //관계가 없는 경우 거리=매우 큰 값(INF)
                dist[i][j] = INF;
            }
        }
    }

    for (int k = 0; k < N; k++) { //플로이드-워셜로 최단 거리 계산
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) //기존 거리 > 거쳐온 거리인 경우
                    dist[i][j] = dist[i][k] + dist[k][j]; //최소 거리인 거쳐온 거리로 거리를 변경
            }
        }
    }

    int max = 0;

    for (i = 0; i < N; i++) { // 2-친구 수 세기
        int count = 0; //count 초기화
        for (int j = 0; j < N; j++) { 
            if (i != j && dist[i][j] <= 2) { //자기자신이 아니고 & 2-거리가 2 이하인 경우
                count++; //count 1 증가
            }
        }
        if (count > max) { //최종 count가 max(현재까지 가장 유명한 사람)보다 크면
            max = count; //max값을 count로 변경
        }
    }

    printf("%d\n", max); //최종 max 출력

    return 0;
}