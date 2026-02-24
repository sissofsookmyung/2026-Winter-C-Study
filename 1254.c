#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51
int main(void) {

    char S[MAX];
    
    fgets(S, MAX, stdin); //문자열 입력받아 S에 저장

    int len = strlen(S); //문자열 길이를 len에 저장
    if (S[len - 1] == '\n') { //개행문자 제거 + 개행문자 제거함으로써 줄어든 문자열 길이 감소시키기
        S[len - 1] = '\0';
        len--;
    }

    int i, j, result;

    for (i = 0; i < len; i++) { 
        int flag = 1; //팰린드롬 여부에 대한 플래그를 1로 초기화
        
        for (j = 0; j < (len-i)/ 2; j++) { //j: 문자열 가장 앞(S[i])부터 +1씩하며 대칭 2개 비교
            if (S[i + j] != S[len - j - 1]) { //위치 대칭인 두 문자가 다르면
                flag = 0; //플래그를 0으로 바꾼 뒤 break
                break;
            }
        }

        if (flag) { //S[i] ~ S[len-1]이 팰린드롬인 경우
            result = len+i; //결과값은 len(기존 길이) + i(필요한 최소 문자)
            break; //바로 i에 대한 for문 탈출
        }
    }

    printf("%d\n", result); //최종 result 출력
    return 0;
}