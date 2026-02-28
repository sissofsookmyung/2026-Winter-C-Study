#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    if(n == 0) {
        printf("0");//0이면 바로 출
        return 0;
    }

    char result[100];
    int idx = 0;

    while(n != 0) {
        long long r = n % -2;// -2로 나눈 나머지
        n /= -2;

        if(r < 0) {
            r += 2;//나머지가 -1일때 +2 해주기(이진수는 0과 1만 사용)
            n += 1;//몫에 1더하기
        }

        result[idx++] = r + '0';
    }

    // 거꾸로 출력
    for(int i = idx - 1; i >= 0; i--)
        printf("%c", result[i]);

    return 0;
}
