#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    while (1) {
        // 상근(n)이와 선영이(m)의 CD 개수 입력받기
        scanf("%d %d", &n, &m);

        // 0 0 입력 -> 종료
        if ((n == 0) && (m == 0)) {
            break;
        }
        // 상근이의 CD 목록 동적 할당
        int* sg = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &sg[i]);
        }
        int count = 0;
        int inx_sg = 0; // 상근이 CD 목록 인덱스

        // 상근이 번호가 더 작으면 while문으로 상근이 인덱스만 증가
        // 상근이 번호와 선영이 번호가 같으면 둘 모두의 인덱스 증가
        // 선영이의 번호가 더 작으면 for문 돌면서 선영이 인덱스 증가
        for (int i = 0; i < m; i++) {
            int sy_cd; // 선영이의 현재 CD 번호
            scanf("%d", &sy_cd);

            // 상근이의 번호가 선영이의 번호보다 작음 -> 상근이의 인덱스 증가
            while (inx_sg < n && sg[inx_sg] < sy_cd) {
                inx_sg++;
            }

            // 상근이와 선영이의 번호가 일치하면 count 증가
            if (inx_sg < n && sg[inx_sg] == sy_cd) {
                count++;
                inx_sg++;
            }
        }
        // 두 사람이 동시에 가지고 있는 CD 개수 출력
        printf("%d\n", count);

        free(sg);
    }
    return 0;
}