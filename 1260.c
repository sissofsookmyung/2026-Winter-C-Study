#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void dfs(int);
void bfs(int);

int N, M, V;
int graph[1001][1001]; //연결정보를 표시할 2차원 배열
int visited[1001]; //방문 여부를 표시할 배열

int main(void) {

    scanf("%d %d %d", &N, &M, &V); //N, M, V 입력받기

    for (int i = 0; i < M; i++) { //M번 간선 정보를 입력받아 graph 배열에 저장 (a-b 연결이면 [a][b]=1, [b][a]=1)
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(V); //dfs 함수 실행
    printf("\n");

    for (int i = 1; i <= N; i++) { //dfs 실행 종료 후 방문 여부 all 초기화
        visited[i] = 0;
    }

    bfs(V); //bfs 함수 실행
    printf("\n");

    return 0;
}

void dfs(int v) { //dfs 함수
    visited[v] = 1; //시작점을 visited한 상태(1)로 변경
    printf("%d ", v); //현재 정점 출력

    for (int i = 1; i <= N; i++) { //모든 정점을 돌며
        if (graph[v][i] && !visited[i]) //현재 정점과 연결 O and 아직 방문x이면
            dfs(i); //그 정점 기준으로 다시 dfs함수 실행
    }
}

void bfs(int v) { //bfs 함수
    int queue[1001]; 
    int front = 0, rear = 0;

    queue[rear++] = v; //현재 정점을 큐에 넣고
    visited[v] = 1; //visited한 상태(1)로 변경

    while (front < rear) { //큐 내부의 모든 걸 뺄 때까지 반복하며
        int current = queue[front++]; //현재 front에 위치한 정점을 빼서
        printf("%d ", current); //출력

        for (int i = 1; i <= N; i++) { //모든 정점을 돌며
            if (graph[current][i] && !visited[i]) { //현재 정점과 연결 O and 아직 방문x이면
                visited[i] = 1; //visited한 상태(1)로 변경
                queue[rear++] = i; //그 정점을 큐에 넣기
            }
        }
    }

}