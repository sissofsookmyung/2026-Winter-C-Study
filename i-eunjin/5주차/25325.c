#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[11];
    int score;
} Student;

int compare(const void* a, const void* b) {
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;

    if (s1->score != s2->score) {
        return s2->score - s1->score;
    }
    return strcmp(s1->name, s2->name);
}

Student list[101];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", list[i].name);
        list[i].score = 0;
    }

    char voted_name[11];
    while (scanf("%s", voted_name) != EOF) {
        for (int i = 0; i < n; i++) {
            if (strcmp(list[i].name, voted_name) == 0) {
                list[i].score++;
            }
        }
    }

    qsort(list, n, sizeof(Student), compare);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", list[i].name, list[i].score);
    }

    return 0;
}