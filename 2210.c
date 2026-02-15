#include <stdio.h>
#include <stdbool.h>

int map[5][5];
bool visited_nums[1000000];
int result_count = 0;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y, int depth, int current_num) {
    if (depth == 5) {
        if (!visited_nums[current_num]) {
            visited_nums[current_num] = true;
            result_count++;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
            dfs(nx, ny, depth + 1, current_num * 10 + map[nx][ny]);
        }
    }
}
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (scanf("%d", &map[i][j]) == EOF) return 0;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            dfs(i, j, 0, map[i][j]);
        }
    }
    printf("%d\n", result_count);
    return 0;
}

/*문제 설명
재귀함수dfs를 호출할때마다 현재 숫자에 10을 곱하고 이동한 칸의 숫자를 더하는 방식으로 자릿수를 늘려나간다
이동횟수가 5번이 되면 탐색을 종료한다
중복을 방지하기 위해 visited_nums배열을 사용하고, 처음 발견된 숫자인 경우에만 카운트를 증가시킨다
*/