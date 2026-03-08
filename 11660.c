#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[1025][1025];  // 입력받을 표 (크기 최대)
int dp[1025][1025];

int main(void) {
    int n, m;  
    scanf("%d %d", &n, &m);  // 표 크기 입력받기 n x m 크기임
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);  // 표입력받기
            
            // (1+1)부터 (i,j)까지 누적합계산
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
            // 겹친거없애고 현재, 위쪽왼쪽까지 더하기
        }
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        // 사각형 좌표 입력받기
        int result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        // (1,1)~(x2,y2)까지 더하고 아까랑반대로겹친거더하고 왼쪽위쪽 제거
        printf("%d\n", result);
    }
    return 0;
}
