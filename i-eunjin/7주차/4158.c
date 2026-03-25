#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    while (1) {
        if (scanf("%d %d", &n, &m) != 2 || (n == 0 && m == 0)) break;

        int* sangeun = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) scanf("%d", &sangeun[i]);

        int count = 0;
        int p1 = 0, p2 = 0;

        for (int i = 0; i < m; i++) {
            int seonyoung_cd;
            scanf("%d", &seonyoung_cd);

            while (p1 < n && sangeun[p1] < seonyoung_cd) {
                p1++;
            }
            if (p1 < n && sangeun[p1] == seonyoung_cd) {
                count++;
                p1++;
            }
        }

        printf("%d\n", count);
        free(sangeun);
    }
    return 0;
}