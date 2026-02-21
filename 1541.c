#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////
//작성자: 김수완
//작성일: 2026-02-21
//1541: 일어버린 괄호
////////////////////////////////////////
//1. '-'가 처음 등장하기 전까지는 모두 더한다.
//2. '-'가 한 번 나오면 이후의 모든 수는 전부 빼준다.
//3. 이는 첫 '-' 이후를 전부 괄호로 묶는 것과 같아 최소값을 만들 수 있다.
////////////////////////////////////////


int main() {
    char expr[51];
    scanf_s("%50s", expr, 51);

    int result = 0;
    int num = 0;
    int isMinus = 0;  // 한 번이라도 '-'가 나왔는지 체크한다.

    for (int i = 0; i <= strlen(expr); i++) {
        if (expr[i] >= '0' && expr[i] <= '9') {
            num = num * 10 + (expr[i] - '0');
        }
        else {
            if (isMinus)
                result -= num;
            else
                result += num;

            num = 0;

            if (expr[i] == '-')
                isMinus = 1;
        }
    }

    printf("%d\n", result);
    return 0;
}

