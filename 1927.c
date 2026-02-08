#include <stdio.h>

#define MAXN 100000

// 최소 힙 배열 (1번 인덱스부터 사용 → heap[1]이 항상 최솟값)
int heap[MAXN + 1];
int heapSize = 0;  // 현재 힙에 들어있는 원소 개수

// 힙에 값 x 삽입
void push(int x) {
    int i = ++heapSize;  // 힙 맨 뒤에 삽입
    heap[i] = x;

    // 부모 노드와 비교하며 힙 성질 유지 (up-heap)
    while (i > 1 && heap[i / 2] > heap[i]) {
        // 부모가 더 크면 교환
        int t = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = t;

        i /= 2;  // 부모 위치로 이동
    }
}

// 힙에서 최솟값 제거 후 반환
int popMin() {
    if (heapSize == 0) return 0;  // 힙이 비어 있으면 0 반환

    int ret = heap[1];  // 최솟값 저장
    heap[1] = heap[heapSize--];  // 마지막 값을 루트로 이동

    int i = 1;
    // 자식 노드와 비교하며 아래로 이동 (down-heap)
    while (i * 2 <= heapSize) {
        int c = i * 2;  // 왼쪽 자식

        // 오른쪽 자식이 있고 더 작으면 선택
        if (c + 1 <= heapSize && heap[c + 1] < heap[c])
            c++;

        // 현재 노드가 더 작으면 힙 성질 만족
        if (heap[i] <= heap[c]) break;

        // 더 작은 자식과 교환
        int t = heap[i];
        heap[i] = heap[c];
        heap[c] = t;

        i = c;  // 자식 위치로 이동
    }

    return ret;  // 삭제한 최솟값 반환
}

int main() {
    int N, x;
    scanf("%d", &N);  // 연산 개수 입력

    while (N--) {
        scanf("%d", &x);

        if (x == 0)   // 0이면 최솟값 출력
            printf("%d\n", popMin());
        else  // 자연수면 힙에 삽입
            push(x);
    }

    return 0;
}
