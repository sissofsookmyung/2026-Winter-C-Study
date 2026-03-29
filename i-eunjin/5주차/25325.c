#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 이름과 득표 수를 저장할 구조체
typedef struct {
    char name[11];
    int num;
} Student;

int compare(const void* a, const void* b) {
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;

    // 득표 수가 다르면 득표 수로 내림차순 정렬
    if (s1->num != s2->num) {
        return s2->num - s1->num;
    }
    // 같은 표를 받았다면 이름으로 오름차순 정렬
    return strcmp(s1->name, s2->name);
}

Student list[101];

int main() {
    int n;  // 학생 수 입력 받음
    scanf("%d", &n);

    // 득표 수 0으로 초기화
    for (int i = 0; i < n; i++) {
        scanf("%s", list[i].name);
        list[i].num = 0;
    }

    char voted_name[11];
    // 투표된 이름이 없을 때까지 읽어옴
    while (scanf("%s", voted_name) != EOF) {
        // 투표된 이름과 일치하는 학생의 득표 수에 +1
        for (int i = 0; i < n; i++) {
            if (strcmp(list[i].name, voted_name) == 0) {
                list[i].num++;
            }
        }
    }

    // 정해진 기준대로 학생 정렬
    qsort(list, n, sizeof(Student), compare);

    // 결과 출력
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", list[i].name, list[i].num);
    }

    return 0;
}