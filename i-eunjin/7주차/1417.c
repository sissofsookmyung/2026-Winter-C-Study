#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int n, dasom;
    if (scanf("%d", &n) != 1) return 0;
    scanf("%d", &dasom);

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    int others[51];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &others[i]);
    }

    int count = 0;
    while (1) {
        qsort(others, n - 1, sizeof(int), compare);

        if (dasom > others[0]) break;

        others[0]--;
        dasom++;
        count++;
    }

    printf("%d\n", count);
    return 0;
}