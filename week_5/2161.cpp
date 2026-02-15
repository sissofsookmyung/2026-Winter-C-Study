// 백준 silver5 자료구조

#include <stdio.h>
#include <stdlib.h>

// 문제 상황에서 가장 위의 카드를 pop한 후, 그 다음 카드를 가장 아래에 내려두는 과정에서
// 원형 큐의 구조를 이용하면 효율적으로 풀 수 있겠다는 생각을 하게 되었다.

int main(void) {
    int n;
    int front = 0, rear = 0;
    int size = 0;

    scanf("%d", &n);

    int* q = (int*)malloc(sizeof(int) * (n + 1));
    
    // push를 구현한다.
    for (int i = 1; i <= n; i++) {
        q[rear] = i;
        rear = (rear + 1) % (n + 1);
        size++;
    }

    while (size > 1) {
        // 가장 위에 있는 카드를 버린 뒤, 큐의 크기를 줄인다.
        int x = q[front];
        front = (front + 1) % (n + 1);
        size--;
        printf("%d ", x);

        // 다음 맨 위의 카드를 맨 뒤에 위치 시킨다.
        int y = q[front];
        front = (front + 1) % (n + 1);
        size--;
        q[rear] = y;
        rear = (rear + 1) % (n + 1);
        size++;
    }

    printf("%d\n", q[front]);

    free(q);
    return 0;
}