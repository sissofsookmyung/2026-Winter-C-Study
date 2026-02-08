#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////
//작성자: 김수완
//작성일: 2026-02-08
//1872: 스택수열
////////////////////////////////////////
//1. 1부터 n까지 숫자를 순서대로 스택에 push하면서 목표 수열이 나올 때까지 진행합니다
//2. 스택 top이 원하는 값이면 pop하며 `+`,  연산을 기록합니다
//3. 중간에 만들 수 없는 경우 `NO` 출력, 끝까지 성공하면 연산 순서를 한 줄씩 출력합니다
////////////////////////////////////////

int main() {
    int n;
    scanf_s("%d", &n);

    int* stack = (int*)malloc(sizeof(int) * n);
    int top = -1;
    int current = 1;
    int* sequence = (int*)malloc(sizeof(int) * n);
    char* result = (char*)malloc(sizeof(char) * n * 2);

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &sequence[i]);
    }

    int idx = 0;

    for (int i = 0; i < n; i++) {
        int target = sequence[i];

        // target이 나올 때까지 push
        while (current <= target) {
            stack[++top] = current++;
            result[idx++] = '+';
        }

        // 스택 top이 target이면 pop
        if (top >= 0 && stack[top] == target) {
            top--;
            result[idx++] = '-';
        }
        else {
            printf("NO\n");
            free(stack);
            free(sequence);
            free(result);
            return 0;
        }
    }

    // 결과 출력
    for (int i = 0; i < idx; i++) {
        printf("%c\n", result[i]);
    }

    free(stack);
    free(sequence);
    free(result);
    return 0;
}
