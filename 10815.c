#include <stdio.h>
#include <stdlib.h> // malloc, qsort 등 사용을 위해 선언

// qsort가 사용할 비교 함수
int cp(const void *a, const void *b) // 정렬할 두 값의 주소 a, b
{
    // 입력받은 값이 int 주소라는 것을 알려주고, 그 주소에 있는 실제 값을 x, y에 저장
    int x = *(int *)a;
    int y = *(int *)b;

    // 반환값이 음수면 a>b, 양수면 a<b, 0이라면 a==b라고 qsort가 판단할 것.
    return x - y;
}

// target이 상근이가 가지고 있는 숫자 카드인지 아닌지를 찾는 함수
// 이분 탐색을 이용함
int bs(int arr[], int n, int target)
{
    int left = 0, right = n - 1; // 탐색 범위는 배열 처음부터 끝까지

    while (left <= right) // 탐색할 구간이 남아있는 동안 계속 반복
    {
        int mid = (left + right) / 2; // 탐색 범위의 중간

        if (arr[mid] == target) // 바로 찾았다면
            return 1; // 1 반환
        else if (arr[mid] < target) // 찾는 값보다 중간이 작다면
            left = mid + 1; // 중앙 기준 오른쪽 탐색 시작
        else // 찾는 값보다 중간이 크다면
            right = mid - 1; // 중앙 기준 왼쪽 탐색 시작
    }
    return 0; // 끝까지 못 찾은 것이므로 0 반환
}

int main() 
{
    // 상근이가 가지고 있는 숫자 카드의 개수
    int N;
    scanf("%d", &N);

    // 배열 크기를 입력받는 상황이기 때문에 포인터와 malloc을 사용함
    int *card = (int *)malloc(sizeof(int) * N);
    
    // 숫자 카드에 적혀있는 정수 입력받기 (N개의 카드)
    for (int i = 0; i < N; i++)
        scanf("%d", &card[i]);

    // compare 함수를 이용해 오름차순으로 정렬
    qsort(card, N, sizeof(int), cp);

    // 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 정수의 개수 M
    int M;
    scanf("%d", &M);

    // 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 정수를 입력받기 (M개의 정수)
    for (int i = 0; i < M; i++) 
    {
        int x;
        scanf("%d", &x);
        // 상근이가 가지고 있는 숫자 카드라면 1, 아니라면 0을 출력하기
        printf("%d ", bs(card, N, x));
    }

    free(card); // malloc으로 빌린 메모리 반납
    return 0;
}

// malloc했으면 free는 필수. 마치 호텔 체크인/체크아웃과 같다.
// malloc: 정수 N개 들어갈 방 하나 주세요 (체크인)
// free: 호텔 체크아웃