#include <stdio.h>

int main() 
{
    // 찬우가 교과서 N권을 M개의 더미로 놔둠
    int N, M;
    scanf("%d %d", &N, &M); // 교과서 권 수와 더미 수 입력받기

    for (int i = 0; i < M; i++) // 각 더미마다
    {
        int k; // 더미에 쌓인 교과서의 수
        scanf("%d", &k); // 교과서 수 입력받기
 
        int prev, curr;
        scanf("%d", &prev); // 아래 놓인 교과서의 번호

        // 맨 아래 교과서를 기준으로 시작해 (아래 있는 교과서를 갱신하며)
        // 나머지 (k-1)개 교과서 번호 비교하기
        for (int j = 1; j < k; j++)
        {
            scanf("%d", &curr); // 위에 놓은 교과서의 번호

            // 아래 교과서 번호보다 위 교과서 번호가 크다면
            if (prev < curr)
            {
                printf("No\n"); // 번호 순으로 나열할 수 없음!
                return 0;
            }

            prev = curr; // 아래 교과서 갱신
        }
    }

    printf("Yes\n"); // 모든 더미에서 올바른 순서대로 교과서가 꺼내졌다
    return 0;
}
