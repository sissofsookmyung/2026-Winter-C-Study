#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51

int main(void) {

    char expr[MAX];
    int result = 0;

    fgets(expr, MAX, stdin); //문자열을 입력받아 expr에 저장

    int first = 1; //첫번째 토큰인지 아닌지에 대한 flag

    char* save1, * save2;
    char* token = strtok_r(expr, "-", &save1); //1. "-" 기준으로 토큰화
    while (token != NULL) {
        int sum = 0; //합계를 0으로 초기화

        char* sub = strtok_r(token, "+", &save2); //2. 토큰화한 것 안에서 다시 "+" 기준으로 토큰화
        while (sub != NULL) {
            sum += atoi(sub); //파싱한 것 각각을 모두 숫자로 변환해 sum에 더하기
            sub = strtok_r(NULL, "+", &save2);
        }

        if (first) { //"-" 단위 파싱에서 첫번째 토큰일 경우
            result += sum; //sum한 값을 result에 더하기
            first = 0; //flag를 0으로 바꾸기
        }
        else { //첫번째 토큰이 아닌 경우
            result -= sum; //sum한 값을 빼기
        }

        token = strtok_r(NULL, "-", &save1);
    }

    printf("%d", result); //최종 결과 출력
    return 0;
}