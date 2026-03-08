#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int heap[100001];  // n의 최댓값은 100000이므로
int size = 0;
int cmp(int a, int b) {   // 절댓값 판별 함수
    if (abs(a) == abs(b)) {
        return a - b;   // 절댓값이 같으면 음수가 우선
    }
    return abs(a) - abs(b);  // 절댓값이 다르면 더 작은값 우선
    // 리턴값 음수면 a가 먼저 양수면 b가 먼저
}
void push(int x) {  // 입력된 숫자 힙에 삽입하는 함수
    heap[++size] = x;  // 힙 맨뒤에 삽입
    int i = size;  // 삽입한 위치를 저장 
    
    // 부모노드와 비교하면서 위치를 잡아감
    while (i > 1 && cmp(heap[i], heap[i / 2]) < 0) {

        // 현재노드와 부모노드의 값을 교환
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;

        i = i / 2; // 교환했으니 부모노드의 위치로 이동
    }
}
int pop() {   // 삭제 및 출력하는 함수
    if (size == 0) {  // 힙이 비어있을 땐 0출력
        return 0;
    }

    int result = heap[1];
    heap[1] = heap[size--];
    int i = 1;

    // 순서대로 위부터 정렬
    while (1) {
        int left = i * 2;  // 왼쪽 자식
        int right = i * 2 + 1;  // 오른쪽 자식
        int p = i;    // 가장우선순위가 높은 위치를 가리킴

        // 왼쪽자식이 존재, 우선 순위가 높을시
        if (left <= size && cmp(heap[left], heap[p]) < 0) {
            p = left;
        }
        //오른쪽 자식이존재, 우선순위가 더 높을시
        if (right <= size && cmp(heap[right], heap[p]) < 0) {
            p = right;
        }
        // 가장 우선순위 높은것과 일치하여 더이상 교환필요x
        if (p == i) {
            break;
        }

        // 부모자식 값 교환 더 작은 자식
        int temp = heap[i];
        heap[i] = heap[p];
        heap[p] = temp;
        i = p;
    }
    return result;
}
int main(void) {
    // printf 호출 시 제약 -> 속도줄이기
    setvbuf(stdout, NULL, _IOFBF, 1 << 20);
    int n;
    scanf("%d", &n);  // 개수입력받기

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);  // 정수 x 입력받기 

        if (x == 0) {
            printf("%d\n", pop());  //0이 입력되면 값 출력
        }
        else {
            push(x);  // 0이 아닐시 힙에추가
        }
    }

    return 0;
}
