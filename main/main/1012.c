#include <stdio.h>
#include <string.h>

int map[51][51];
int visited[51][51];
int M, N, K;
int dx[] = { 0, 0, -1, 1 }; // 상하좌우 이동을 위한 배열
int dy[] = { -1, 1, 0, 0 };

// 깊이 우선 탐색 (DFS) 함수
void dfs(int y, int x) {
    visited[y][x] = 1; // 현재 위치 방문 처리

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 맵 범위 내에 있고, 배추가 있으며(1), 아직 방문하지 않은 경우
        if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
            if (map[ny][nx] == 1 && !visited[ny][nx]) {
                dfs(ny, nx);
            }
        }
    }
}

int main() {
    int T;
    scanf_s("%d", &T); // 테스트 케이스 개수

    while (T--) {
        scanf_s("%d %d %d", &M, &N, &K);

        // 초기화
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        int count = 0;

        // 배추 위치 입력
        for (int i = 0; i < K; i++) {
            int x, y;
            scanf_s("%d %d", &x, &y);
            map[y][x] = 1;
        }

        // 전체 맵을 돌며 새로운 배추 군집 찾기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j); // 연결된 모든 배추 방문
                    count++;   // 군집 하나 발견할 때마다 지렁이 한 마리 추가
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}