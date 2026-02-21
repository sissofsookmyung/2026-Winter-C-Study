#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 50

int map[MAX][MAX];
int visited[MAX][MAX];
int M, N;
int dx[4] = { 1, -1, 0, 0 }; //상하좌우 이동에 대한 행 이동
int dy[4] = { 0, 0, 1, -1 }; //상하좌우 이동에 대한 열 이동

void dfs(int x, int y) {
    visited[y][x] = 1; //방문한 것으로 처리

    for (int i = 0; i < 4; i++) { //상하좌우 한칸씩 이동해보기
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) { //map 안에 존재하고
            if (map[ny][nx] == 1 && visited[ny][nx] == 0) { //그 위치에 배추가 존재하고 & 아직 방문하지 않았다면
                dfs(nx, ny); //그 좌표에 대한 dfs 실행
            }
        }
    }
}

int main(void) {

    int T, K;
    int x, y, i;

    scanf("%d", &T); //T 입력받아 저장

    while (T--) { //T 개수만큼 반복

        scanf("%d %d %d", &M, &N, &K); //M, N, K 입력받아 저장
        
        for (i = 0; i < N; i++) { //map 초기화
            for (int j = 0; j < M; j++) {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for (i = 0; i < K; i++) { //관계를 입력받아 map에 입력
            scanf("%d %d", &x, &y);
            map[y][x] = 1; //가로(열) 세로(행) 순으로 입력받기 때문에 [y][x]
        }

        int count = 0; //필요한 배추흰지렁이 수를 담을 count 초기화

        for (int i = 0; i < N; i++) { //map 전체 좌표를 모두 돌며
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && visited[i][j] == 0) { //관계가 존재하고 & 아직 방문하지 않았으면
                    dfs(j, i); //dfs 실행
                    count++; //count 1 증가
                }
            }
        }
        printf("%d\n", count); //최종 count 출력

    }

    return 0;
}