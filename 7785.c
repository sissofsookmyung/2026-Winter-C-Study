#include <stdio.h>
#include <stdlib.h> // malloc, qsort 등의 사용을 위해 선언
#include <string.h> // strcmp 사용을 위해 선언

// 직원 출퇴근 기록 저장용 Giggle
typedef struct 
{
    char name[6]; // 직원 이름 저장
    char status[6]; // 직원 출퇴근 상태 (enter/leave)
} Giggle;

// qsort가 이용하는 비교 함수
// 두 명의 직원 중에서 이름 사전순 기준으로 누가 앞인지 알려줌
int compare(const void *a, const void *b)
{
    // Giggle: 출입기록 한 줄
    // Giggle *: 출입기록 주소
    // qsort가 준 ‘출입 기록 한 줄의 위치’ a를 진짜 출입 기록(Giggle)로 해석해서 g1에 담는다
    Giggle *g1 = (Giggle *)a; 
    // qsort가 준 ‘출입 기록 한 줄의 위치’ b를 진짜 출입 기록(Giggle)로 해석해서 g2에 담는다
    Giggle *g2 = (Giggle *)b;

    // 문자열 g1과 g2를 알파벳 순으로 비교해 g1이 g2보다 앞이라면 음수, 아니라면 양수, 같으면 0을 반환
    return strcmp(g1->name, g2->name);
}

int main() 
{
    // 로그에 기록된 출입 기록의 수 n줄
    int n;
    scanf("%d", &n);

    // 출입기록을 담을 출입기록부 arr 준비 (크기 n)
    Giggle *arr = (Giggle *)malloc(sizeof(Giggle) * n);

    // n줄의 출입 기록 입력받기 ('이름 enter/leave' 형식)
    for (int i = 0; i < n; i++)
        scanf("%s %s", arr[i].name, arr[i].status);

    // 이름 기준으로 사전순 정렬
    qsort(arr, n, sizeof(Giggle), compare);

    for (int i = n - 1; i >= 0; i--) // 배열의 마지막부터 역순으로 확인
    {
        // 같은 이름이면 앞에 있는 건 무시 (최종 기록이 아니므로)
        if (i < n - 1 && strcmp(arr[i].name, arr[i + 1].name) == 0)
            continue;

        // 상태가 enter인 경우에만 이름 출력
        if (strcmp(arr[i].status, "enter") == 0)
            printf("%s\n", arr[i].name);
    }

    free(arr); // 동적 메모리 해제
    return 0;
}