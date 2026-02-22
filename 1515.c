#include <stdio.h>
#include <string.h>

int main() {
    char s[3001];
    scanf("%s", s);

    int len = strlen(s); // 길이 저장
    int idx = 0;  // s에서 현재 맞춰야 할 위치

    for (int n = 1; ; n++) {
        char temp[20];
        sprintf(temp, "%d", n);  // 숫자를 문자열로 변환

        for (int i = 0; temp[i] != '\0'; i++) {
            if (idx < len && temp[i] == s[idx]) { // 입력 문자열을 맞추지 않음 && 현재 숫자의 문자와 s[idx]같음
                idx++;
            }
        }

        if (idx == len) {
            printf("%d\n", n);
            break;
        }
    }

    return 0;
}
