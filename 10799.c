#include <stdio.h>
#include <string.h>

char input[100005];

int main() {
    scanf("%s", input);

    int result = 0;
    int stick_cnt = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        if (input[i] == '(') {
            stick_cnt++;
        }
        else {
            stick_cnt--;

            if (input[i - 1] == '(') {
                result += stick_cnt;
            }
            else {
                result += 1;
            }
        }
    }
    printf("%d\n", result);
    return 0;

}

/*
코드 문자열을 순회하며 여는 괄호 (가 나오면 현재 겹쳐진 막대기의 수(stick_cnt)를 증가시키는 방식으로 구현

닫는 괄호)가 나왔을때 바로 직전 문자를 확인해, 레이저 인경우 현재 쌓인 막대기의 수만큼 결과를 더하고, 막대기의 끝인 경우 조각 1개를 더해준다
최종적으로 printf를 통해 결과를 출력해준다.
*/