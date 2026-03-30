
//분할정복 문제
//입력되는 N의값에 따라 배열의 크기가 유동적으로 변하므로 calloc으로 2차원 배열 동적할당을 수행
//종이의 모든 값이 같은지 확인하는 check함수, 종이를 자르는 divide함수로 구성되어 있음

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

int** paper;
int type[3]= { 0, 0, 0 };

int check(int row, int col, int n)
{
    int c = paper[row][col];
    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (c != paper[i][j]) {
                return False;
            }
        }
    }
    return True;
}

void divide(int row, int col, int n)
{
    if (check(row, col, n)) {
        //종이의 모든 값이 같으면 -1인 경우 type[0],0인경우 type[1]...
        type[paper[row][col] + 1]++;
        return;
    }

    int num = n / 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            divide(row + i * num, col + j * num, num);
        }
    }
}

int main()
{
    int N;

    if (scanf("%d", &N) != 1) return 0;

    paper = (int**)calloc(N, sizeof(int*));
    for (int i = 0; i < N; i++)
        paper[i] = (int*)calloc(N, sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (scanf("%d", &paper[i][j]) != 1) break;
    }

    divide(0, 0, N);

    for (int i = 0; i < 3; i++)
        printf("%d\n", type[i]);

    for (int i = 0; i < N; i++)
        free(paper[i]);
    free(paper);

    return 0;
}