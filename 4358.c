#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 128
#define TABLE_SIZE 200003  // 해시 테이블 크기

// 해시 테이블용 노드 (체이닝 방식)
typedef struct Node {
    char *key;  // 나무 이름
    int count;  // 등장 횟수
    struct Node *next;  // 같은 해시값을 가진 노드 연결
} Node;

Node *table[TABLE_SIZE];  // 해시 테이블
long long total = 0;  // 전체 나무 개수

// 문자열 해시 함수 (djb2)
unsigned long hash_str(const char *s) {
    unsigned long h = 5381;
    int c;
    while ((c = (unsigned char)*s++))
        h = h * 33 + c;
    return h;
}

// 해시 테이블에 문자열 추가
void add_key(const char *key) {
    unsigned long h = hash_str(key) % TABLE_SIZE;
    Node *cur = table[h];

    // 이미 있는 문자열인지 확인
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            cur->count++;  // 있으면 개수 증가
            return;
        }
        cur = cur->next;
    }

    // 없으면 새 노드 생성
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = (char *)malloc(strlen(key) + 1);
    strcpy(n->key, key);
    n->count = 1;
    n->next = table[h];
    table[h] = n;
}

// qsort용 비교 함수 (사전순)
int cmp(const void *a, const void *b) {
    Node *x = *(Node **)a;
    Node *y = *(Node **)b;
    return strcmp(x->key, y->key);
}

int main(void) {
    char buf[MAXLEN];

    // EOF까지 한 줄씩 입력
    while (fgets(buf, sizeof(buf), stdin)) {
        // 개행 문자 제거
        size_t len = strlen(buf);
        if (len && buf[len - 1] == '\n')
            buf[len - 1] = '\0';

        if (buf[0] == '\0') continue;

        add_key(buf);  // 나무 이름 추가
        total++;  // 전체 개수 증가
    }

    // 해시 테이블에 저장된 노드 개수 세기
    int cnt = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
        for (Node *cur = table[i]; cur; cur = cur->next)
            cnt++;

    // 정렬을 위해 노드 포인터 배열 생성
    Node **arr = (Node **)malloc(sizeof(Node *) * cnt);
    int idx = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
        for (Node *cur = table[i]; cur; cur = cur->next)
            arr[idx++] = cur;

    // 사전순 정렬
    qsort(arr, cnt, sizeof(Node *), cmp);

    // 결과 출력
    for (int i = 0; i < cnt; i++) {
        double percent = (double)arr[i]->count * 100.0 / total;
        printf("%s %.4f\n", arr[i]->key, percent);
    }

    // 메모리 해제
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *cur = table[i];
        while (cur) {
            Node *next = cur->next;
            free(cur->key);
            free(cur);
            cur = next;
        }
    }
    free(arr);

    return 0;
}
