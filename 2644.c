#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 101

int visited[MAX];
int graph[MAX][MAX];
int dist[MAX];
int queue[MAX];

int main(void) {

    int N;
    scanf("%d", &N); //사람 수 N 입력받아 저장

    int a, b;
    scanf("%d %d", &a, &b); //촌수를 계산할 두 사람 a,b 번호를 입력받아 저장

    int M;
    scanf("%d", &M); //관계의 개수 M을 입력받아 저장

    for (int i = 0; i < M; i++) { //관계를 M번 입력받아 graph 배열에 표시
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y]=1; //양방향으로 표시
        graph[y][x]=1; //양방향으로 표시
    }

    //BFS 너비 우선 탐색으로 촌수 찾기
    int front = 0, rear = 0;
    queue[rear++] = a;
    visited[a] = 1; //a부터 시작
    dist[a] = 0; //a의 거리 초기화

    while (front < rear) {
        int current = queue[front++]; //현재 front에 있는 번호를 꺼내서 current에 저장

        for (int i = 1; i <= N; i++) { //모든 번호를 다 돌며
            if (graph[current][i] && !visited[i]) { //current가 i와 연결되어 있고 and i 아직 방문x라면
                visited[i] = 1; //i 방문
                dist[i] = dist[current] + 1; //i는 current의 다음 단계이므로 거리를 +1
                queue[rear++] = i; //i를 큐에 넣기
            }
        }
    }

    if (visited[b]) printf("%d", dist[b]); //탐색이 끝난 뒤 b를 방문했다면 b의 dist 출력
    else printf("-1"); //방문한 적 없다면 -1 출력

    return 0;
}