#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);  // 전체 책 개수 N, 스택 개수 M

    int possible = 1;  // 가능하면 1, 중간에 틀리면 0

    for (int i = 0; i < M; i++) {

        int k;
        scanf("%d", &k);  // 현재 스택에 쌓인 책 개수

        int prev, curr;

        // 스택이 비어있지 않다면
        if (k > 0) {

            scanf("%d", &prev);  // 스택의 맨 위 책

            // 위에서 아래로 한 개씩 확인
            for (int j = 1; j < k; j++) {
                scanf("%d", &curr);

                // 아래쪽이 더 크면 정렬 불가
                if (prev < curr)
                    possible = 0;

                prev = curr;  // 다음 비교를 위해 갱신
            }
        }
    }

    // 하나라도 조건 위반이면 No
    if (possible)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
