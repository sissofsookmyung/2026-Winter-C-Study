#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char body[21];
    char tail[21];
} Color;

int compare(const void* a, const void* b) {
    Color* c1 = (Color*)a;
    Color* c2 = (Color*)b;

    if (strcmp(c1->body, c2->body) != 0) {
        return strcmp(c1->body, c2->body);
    }
    return strcmp(c1->tail, c2->tail);
}

int main() {
    char colors[4][21];
    for (int i = 0; i < 4; i++) {
        scanf("%s", colors[i]);
    }

    Color list[16];
    int count = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(list[count].body, colors[i]);
            strcpy(list[count].tail, colors[j]);
            count++;
        }
    }

    qsort(list, count, sizeof(Color), compare);

    for (int i = 0; i < count; i++) {
        if (i > 0 && strcmp(list[i].body, list[i - 1].body) == 0 &&
            strcmp(list[i].tail, list[i - 1].tail) == 0) {
            continue;
        }
        printf("%s %s\n", list[i].body, list[i].tail);
    }

    return 0;
}