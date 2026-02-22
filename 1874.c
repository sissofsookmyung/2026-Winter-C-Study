#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int stack[100000];
    int top = -1;

    // 연산 기록: 최대 2n개까지 가능
    char ans[200000];
    int idx = 0;

    int cur = 1;  // 다음에 push할 숫자 (1부터 시작)

    for (int i = 0; i < n; i++) {
        int x;  // 만들고 싶은 수열의 i번째 값
        scanf("%d", &x);

        // 스택 top이 x보다 작으면, x가 나올 때까지 push
        while (cur <= n && (top == -1 || stack[top] < x)) {
            stack[++top] = cur++;  // push
            ans[idx++] = '+';  // 기록
        }

        // 이제 top이 x면 pop해서 수열에 x를 출력한 효과
        if (top != -1 && stack[top] == x) {
            top--;  // pop
            ans[idx++] = '-';  // 기록
        } else {
            // top이 x가 아닌데 더 이상 맞출 방법이 없음
            printf("NO\n");
            return 0;
        }
    }

    // 가능하면 기록된 연산을 줄바꿈해서 출력
    for (int i = 0; i < idx; i++) {
        printf("%c\n", ans[i]);
    }

    return 0;
}