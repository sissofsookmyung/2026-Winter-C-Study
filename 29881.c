// 참가자는 총 N명 -> N을 입력받음
// 1) N명의 이름과 성을 입력받음
// 2) N명의 이름과 계정명을 입력받음
// 출력: N명의 성과 계정명을 매치시켜 출력

#include <stdio.h>
#include <string.h>

int main() 
{
    int N;
    scanf("%d", &N); // 참가자 수 N 입력받기

    char fname1[21][21], lname[21][21]; // 이름과 성을 입력받아 저장할 fname1, lname
    char fname2[21][21], acc[21][21]; // 이름과 계정명을 입력받아 저장할 fname2, acc

    // N명의 이름과 성 입력받기
    for (int i = 0; i < N; i++)
        scanf("%s %s", fname1[i], lname[i]);

    // N명의 이름과 계정명 입력받기
    for (int i = 0; i < N; i++)
        scanf("%s %s", fname2[i], acc[i]);

    // 이름 기준으로 매칭 (성-계정명)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (strcmp(fname1[i], fname2[j]) == 0) // 이름이 동일하다면 성-계정명 매치 가능
            {
                printf("%s %s\n", lname[i], acc[j]); // 매칭시킨 성-계정명 출력
                break;
            }
        }
    }

    return 0;
}
