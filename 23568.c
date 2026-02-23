// 영희는 1차원 직선 위에 있다. 영희는 지금 자신의 위치를 지선에게 보냈다.
// 그러자 지선이가 이동 방법이 적힌 n개의 규칙을 보내줬다.

// 규칙은 이러한 형태이다 -> (i, j, k)
// i는 현재 위치를 나타낸다.
// j는 이동 방향이다. (L/R)
// k는 이동할 거리이다.

// j=L(Left)라면 i-k
// j=R(Right)라면 i+k

// 주어진 규칙들을 이용해 지선이 집 위치를 출력하는 것이 프로그램 목표

#include <stdio.h>

int main() 
{
    int n; 
    scanf("%d", &n); // 규칙 개수 n 입력받기

    int pos[10000]; // 출발 위치 i를 저장할 배열
    char dir[10000]; // L또는 R 방향을 저장할 배열
    int dist[10000]; // 이동거리를 저장할 배열
    int used[10000] = {0}; // 규칙을 이미 사용했는지 체크할 배열 (사용함=1, 사용안함=0)

    for (int i = 0; i < n; i++) // n개의 규칙 입력받기 (i, j, k)
        scanf("%d %c %d", &pos[i], &dir[i], &dist[i]);

    int current; 
    scanf("%d", &current); // 영희의 시작 위치 입력받기

    for (int step = 0; step < n; step++) { // n개의 규칙 사용하기
        for (int i = 0; i < n; i++) { // 단, 현재 위치에 해당하는 규칙 사용하기
            if (!used[i] && pos[i] == current) // 아직 사용하지 않은 규칙이고, 출발 위치가 현재 위치와 같으면
            {
                used[i] = 1; // 이 규칙을 사용

                if (dir[i] == 'L') // 왼쪽 방향이면
                    current -= dist[i]; // 빼기 (함수그래프 x축 생각하면 이해하기 편함)
                else // 오른쪽 방향이면 
                    current += dist[i]; // 더하기

                break;
            }
        }
    }

    printf("%d\n", current); // 지선이 집 위치 출력

    return 0;
}