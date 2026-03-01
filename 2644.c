#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
int main(void) {
    int n, a, b, m;
    scanf("%d", &n);  // 전체 사람 수 
    scanf("%d %d", &a, &b);  // 촌수를 구할 두 사람
    scanf("%d", &m); // 부모자식 관계의 수
    
    int arr[101][101]; // n의 최댓값은 100이므로

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] = 0;  // 행렬초기화
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y); // 부모자식 관계 m번 입력받기

        arr[x][y] = 1;
        arr[y][x] = 1; // 관계표시
    }
    // bfs 접근
    int front = 0;
    int rear = 0;
    int queue[101] = { 0 };  // bfs 큐
    int visited[101] = { 0 };  // 방문체크
    int result[101] = { 0 };  // 촌수 저장


    // 시작지점
    queue[rear++] = a;
    visited[a] = 1;
    result[a] = 0;  // 자기자신의 촌수는 0이므로

    while (front < rear) {
        int current = queue[front++];
        // 현재확인할사람과 연결된 모든 사람 방문
        for (int i = 1; i <= n; i++) {
            // 연결되었고 방문아직 안했으면
            if (arr[current][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                result[i] = result[current] + 1;
                // 내촌수는 부모촌수+1이다
                queue[rear++] = i;
            }
            
        }
    }
    if (visited[b] == 0) {
        // 아무관계가 없을때는 -1을 출력한다
        printf("-1");
    }
    else {
        printf("%d", result[b]);  // 결과 출력
    }
    return 0;
}
