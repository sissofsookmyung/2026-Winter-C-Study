
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

////////////////////////////////////////
//작성자: 김수완
//작성일: 2026-02-21
//11724: 연결요소의 개수 
////////////////////////////////////////
//1. 방문하지 않은 정점에서 DFS를 시작하면 하나의 연결 요소가 된다.
//2. DFS로 해당 정점과 연결된 모든 정점을 방문 처리한다.
//3. DFS 시작 횟수가 곧 연결 요소의 개수이다.
////////////////////////////////////////


int graph[1001][1001];
int visited[1001];
int N, M;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= N; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf_s("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf_s("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // 무방향 그래프
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}

