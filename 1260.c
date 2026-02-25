#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

////////////////////////////////////////
//작성자: 김수완
//작성일: 2026-02-25
//1260: DFS와 BFS
////////////////////////////////////////
//1. 인접행렬로 그래프를 저장하고 DFS(재귀)와 BFS(큐)를 각각 구현한다.
//2. DFS는 가능한 깊게 먼저 탐색하고, BFS는 가까운 정점부터 순서대로 탐색한다.
//3. 방문 배열을 이용하여 이미 방문한 정점은 다시 방문하지 않도록 처리한다.
////////////////////////////////////////

int N, M, V;
int graph[MAX][MAX];     // 인접 행렬
int visited[MAX];        // 방문 체크 배열

// ===================== DFS =====================
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 1; i <= N; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

// ===================== BFS =====================
void BFS(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    // 방문 배열 초기화
    for (int i = 1; i <= N; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 1; i <= N; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}


int main() {

    scanf_s("%d %d %d", &N, &M, &V);

    int a, b;
    for (int i = 0; i < M; i++) {
        scanf_s("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1; // 양방향 그래프
    }

    // DFS
    DFS(V);
    printf("\n");

    // BFS
    BFS(V);
    printf("\n");

    return 0;
}