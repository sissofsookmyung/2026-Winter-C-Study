//2^n크기의 색종이가 주어졌을때 이를 계속 반으로 나누면서, 해당 조각에 있는 색종이의 색이 모두 같을 경우 count및 배제한다고 했을때
//최종적으로 색에 따라 count되는 조각수가 몇개인지 찾는문제

#include <stdio.h>

//N은 색종이 한변의 길이, arr은 색종이 데이터, visit은 이미 카운트된 구역인지 체크
int N, arr[150][150] = {0, }, visit[150][150] = {0, }, temp, count_white = 0, count_blue = 0, check;

//특정 구역이 ㅗ두 같은 색인지 확인,check=1로 일단 모두 같은 색이라고 가정.
void check_block(int y, int x, int block) {
    check = 1;
    
    //블록 내부를 순회하며 좌상단 첫칸과 색이 다른 칸이 있는지 검사,
    //색이하나라도 다르면 모두같지 않음 표시
    for(int i=y; i<y+block; i++)
        for(int j=x; j<x+block; j++)
            if(arr[i][j] != arr[y][x]) check = 0;
    if(check) {
        //만약 블록 내 모두 같다면, visit표시해두고,색상에 따라 카운트 증가
        for(int i=y; i<y+block; i++)
            for(int j=x; j<x+block; j++) visit[i][j] = 1;
        if(arr[y][x]) count_blue++;
        else count_white++;
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) scanf("%d", &arr[i][j]);
    temp = N;
    while(temp) {
        for(int i=1; i<=N; i+=temp)
            for(int j=1; j<=N; j+=temp) {
                if(temp == 1 && !visit[i][j]) {
                    //크기가 1이고 아직처리안됐으면  바로 카운트
                    visit[i][j] = 1;
                    if(arr[i][j]) count_blue++;
                    else count_white++;
                }
                //크기가 1보다크고 아직처리안됐으면 같은색인지검사
                else if(!visit[i][j]) check_block(i, j, temp);
            }
        temp /= 2;
    }
    printf("%d\n%d", count_white, count_blue);
}