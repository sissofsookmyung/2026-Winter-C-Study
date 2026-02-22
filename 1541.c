#include <stdio.h>
#include <string.h>

int main() {
    char s[51];              
    scanf("%s", s);             

    int result = 0;             
    int num = 0;             
    int minus = 0; // 0: 더하기, 1: 빼기

    for (int i = 0; i <= strlen(s); i++) { // 문자열 끝까지 반복
        if (s[i] >= '0' && s[i] <= '9') { // 현재 문자가 숫자라면

            num = num * 10 + (s[i] - '0');
        }
        else {
            if (minus)
                result -= num;  // 빼기 상태이면 빼기
            else
                result += num;  // 더하기 상태이면 더하기
                
            num = 0;         

            if (s[i] == '-') // '-'를 만나면 이후는 전부 빼기
                minus = 1;
        }
    }

    printf("%d\n", result);

    return 0;
}
