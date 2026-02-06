#include <stdio.h>
#include <stdlib.h>

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
