#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[6];
} Record;

int compare(const void* a, const void* b) {
    return strcmp(((Record*)b)->name, ((Record*)a)->name);
}

Record list[1000001];

int main() {
    int n;
    scanf("%d", &n);

    char action[10];
    for (int i = 0; i < n; i++) {
        scanf("%s %s", list[i].name, action);
    }

    qsort(list, n, sizeof(Record), compare);

    for (int i = 0; i < n; i++) {
        if (i < n - 1 && strcmp(list[i].name, list[i + 1].name) == 0) {
            i++;
        }
        else {
            printf("%s\n", list[i].name);
        }
    }

    return 0;
}