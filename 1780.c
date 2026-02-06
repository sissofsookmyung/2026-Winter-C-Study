#include <stdio.h>

int paper[2200][2200];
/* paper 배열 :
    - 입력으로 주어지는 N×N 종이를 저장
    - 각 칸에는 -1, 0, 1 중 하나가 들어감
*/

//결과 카운트 변수
int cnt_minus = 0;  // -1로만 채워진 종이 개수
int cnt_zero = 0;   // 0으로만 채워진 종이 개수
int cnt_plus = 0;   // 1로만 채워진 종이 개수

/*  divide 함수
    (x, y) : 현재 검사할 종이의 시작 좌표
    size   : 현재 종이의 한 변 길이
*/
void divide(int x, int y, int size) {
    int first = paper[x][y];  // 기준이 되는 첫 번째 값
    int same = 1;             // 모두 같은 값인지 판단하는 변수

    // 현재 종이가 모두 같은 값인지 검사
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != first) {
                same = 0;     // 다른 값 발견
                break;
            }
        }
        if (!same) break;
    }

    // 모든 값이 같다면 해당 값 카운트 증가
    if (same) {
        if (first == -1)
            cnt_minus++;
        else if (first == 0)
            cnt_zero++;
        else
            cnt_plus++;
        return;   // 재귀 종료
    }

    // 모두 같은 값이 아니라면 종이를 3×3 = 9개의 동일한 크기로 분할
    int newSize = size / 3;

    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            divide(
                x + dx * newSize,  // 분할된 종이의 시작 x좌표
                y + dy * newSize,  // 분할된 종이의 시작 y좌표
                newSize            // 분할된 종이의 크기
            );
        }
    }
}

int main() {
    int N;

    // 종이 크기 입력
    scanf("%d", &N);

    // 종이 데이터 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    // 전체 종이를 기준으로 분할 정복 시작
    divide(0, 0, N);

    // 결과
    printf("%d\n", cnt_minus);
    printf("%d\n", cnt_zero);
    printf("%d\n", cnt_plus);

    return 0;
}