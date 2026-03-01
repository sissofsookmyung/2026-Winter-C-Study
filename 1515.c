#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[3001]; // 입력받을 문자열 크기는 최대 3000자리
    scanf("%s", s); // 입력받기

    int l = strlen(s);  // s의 길이 저장
    int p = 0;  // 위치 포인터

    // 1부터 검사
    for (int i = 1; i <= 3000;i++) {
        char buf[5];
        sprintf(buf, "%d", i);  // i를 문자열로 buf에 저장
        for (int j = 0; buf[j] != '\0';j++) {  // 위치가 s끝까지 도달하도록 검사
            if (s[p] == buf[j]) {  // 값이 같으면
                p++;   // 다음을 가리키게 됨

                if (p == l) {  // 길이비교해서 끝까지 왔다면 종료
                    printf("%d", i);
                    return 0;
                }
            }
        }
    }
    return 0;
}
