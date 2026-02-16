#include <stdio.h>

int main() 
{
    // 상근이가 가지고 있는 CD의 수 N, 선영이가 가지고 있는 CD의 수 M
    int N, M;

    while (1) 
    {
        scanf("%d %d", &N, &M); // CD 개수 입력받기

        if (N == 0 && M == 0) // 개수가 0이라면 프로그램 바로 종료
            break;

        int a[N], b[M]; // CD 번호를 저장할 배열 준비

        for (int i = 0; i < N; i++) // 상근이가 가진 CD 번호 입력받기
            scanf("%d", &a[i]);
        for (int i = 0; i < M; i++) // 선영이가 가진 CD 번호 입력받기
            scanf("%d", &b[i]);

        int i = 0, j = 0;
        int count = 0; // 둘 다 가지고 있는 CD 개수

        // 오름차순으로 입력받았다는 전제 하
        while (i < N && j < M) // 상근이 CD 전체와 선영이 CD 전체를 비교
        {
            if (a[i] == b[j]) { // 상근이가 가진 CD 번호와 선영이가 가진 CD 번호가 같다
                count++; // 둘 다 가지고 있는 CD 개수 +1
                i++; // 상근이의 다른 CD 가져오기
                j++; // 선영이의 다른 CD 가져오기
            } else if (a[i] < b[j]) { // 상근이 CD 번호 < 선영이 CD 번호
                i++; // 상근이의 다른 CD 가져오기
            } else { // 상근이 CD 번호 > 선영이 CD 번호
                j++; // 선영이의 다른 CD 가져오기
            }
        }

        printf("%d\n", count); // 둘 다 가지고 있는 CD 개수 출력
    }

    return 0; // 두 사람이 동시에 가지고 있는 CD가 없으므로 0 출력
}
