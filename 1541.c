//1541번_잃어버린 괄호

#include <stdio.h>
#include <string.h>

int main() {
    char str[51];
    scanf("%s", str);
    int result = 0;
    int temp = 0;
    int minus_found = 0;
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            temp = temp * 10 + (str[i] - '0');
        }
        else {
            if (minus_found == 0) {
                result += temp;
            }
            else {
                result -= temp;
            }
            temp = 0;
            if (str[i] == '-') {
                minus_found = 1;
            }
        }
    }
    printf("%d\n", result);
    return 0;
}

/* 문제설명
핵심: 덧셈과 뺄셈만 있을때 값을 최소로 만들려면, 마이너스가 나오는 순간부터 그 뒤의 모든 숫자를 빼면 됨
문자열을 scanf로 입력받은 후, for문을 이용해서 문자열을 한글자씩 읽으며 숫자로 만든다
연산자(+,-)나 문자열 끝을 만나면 지금까지 만든 숫자(temp)를 결과에 반영한다.
minus_found가 0이면 더하고, 1이면 뺀다.
*/
