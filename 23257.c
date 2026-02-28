#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int k;
        scanf("%d", &k);

        int prev;
        scanf("%d", &prev);

        for (int j = 1; j < k; j++) {
            int curr;
            scanf("%d", &curr);

            if (prev < curr) {
                printf("No\n");
                return 0;
            }
            prev = curr;
        }
    }

    printf("Yes\n");
    return 0;
}