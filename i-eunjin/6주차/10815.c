#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    int* cards = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &cards[i]);

    qsort(cards, n, sizeof(int), compare);

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int target, found = 0;
        scanf("%d", &target);

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (cards[mid] == target) {
                found = 1;
                break;
            }
            else if (cards[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        printf("%d ", found);
    }
    free(cards);
    return 0;
}