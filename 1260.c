//DFS:Depth First Search,깊이 우선 탐색. 이동할 수 있는 노드로 최대한 깊게 이동하며 탐색

//BFS:Breadth First SEarch, 너비 우선 탐색. 이동할 수 있는 노드를 먼저 한번씩 방문한 뒤더이상 인점합 노드없으면 그때야 인접한 노드로 이동해서 탐색
//visited[v]=1로 현재 방문한 노드를 표시한다.
//grapth[vi[[i]&&!visitedpi]=>연결되어 있고 방문 안했다면 바로 깊게 들어간다.]
#include<stdio.h>

int N, graph[1001][1001] = {0, }, visit[1001] = {0, }, queue[1001];

void dfs(int V) {
    visit[V] = 1;
    printf("%d ", V);
    for(int i=1; i<=N; i++) if(graph[V][i] && !visit[i]) dfs(i);
}

void bfs(int V) {
    int front = 0, rear = 1, pop;
    visit[V] = 1;
    printf("%d ", V);
    queue[0] = V;
    //큐를 이용한다. 큐가 빌 때까지 반복하고, 큐에서 하나를 꺼내고, 인접한 노드들을 모두찾은 후,
    while(front < rear) {
        pop = queue[front++];
        for(int i=1; i<=N; i++)
            //인접한 노드 모두 찾기
            if(graph[pop][i] && !visit[i]) {
                //큐에 넣기 전 방문 표시, 인접한 노드들을 큐에 순서대로 넣는다.
                visit[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
    }
}

int main() {
    int M, V, x, y;
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    visit[V] = 1;
    dfs(V);
    for(int i=1; i<=N; i++) visit[i] = 0;
    visit[V] = 1;
    printf("\n");
    bfs(V);
}