#include <stdio.h>

// 최다 득표자를 찾은 후에 그 사람에게서 표를 빼앗는 것이 핵심

int main()
{
    int N; // 후보자 수 총 N명 (50 이하의 자연수)
    scanf("%d", &N); // 후보의 수 입력받기
    
    int dasom; // 다솜이 득표 수 (100 이하의 자연수)
    scanf("%d", &dasom);  // 다솜이 득표 수 입력받기

    int a[50]; // 다솜 제외 후보자들의 득표수를 넣을 리스트
    
    for (int i = 0; i < N - 1; i++)
        scanf("%d", &a[i]); // 다른 후보들 득표 수 입력받기 (100 이하의 자연수)

    int count = 0; // 매수한 사람 총 인원 세는 변수

    while (1) // 다솜이가 최다득표자가 될 때까지 반복할 것.
    {
        int max = 0, idx = -1;

        // 다솜을 제외한 후보들 중 가장 표 많은 사람 찾기
        for (int i = 0; i < N - 1; i++) {
            if (a[i] > max) {
                max = a[i];
                idx = i;
            }
        }

        if (dasom > max)
            break; // 다솜이 득표수 1등이면 종료

        a[idx]--; // 최다득표자에게서 표 하나 뺏기
        dasom++; // 뺏기 완료
        count++; // 매수한 사람 수 +1
    }

    printf("%d\n", count); // 다솜이가 매수해야하는 사람의 최솟값 출력
    
    return 0;
}