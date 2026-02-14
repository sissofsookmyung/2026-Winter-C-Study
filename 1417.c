#include <stdio.h>
#include <stdlib.h> 

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main() {
    int n, k, count = 0; //후보자 수, 다솜이 득표수, 매수한 횟수
    int candidate[50];

    scanf("%d", &n);

    scanf("%d", &k);  

    if (n == 1) {     //후보가 1명
        printf("0\n");
        return 0;
    }

    //다솜이 제외한 후보 득표수 입력 받아 candidate 배열에 저장
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &candidate[i]);
    }

    qsort(candidate, n - 1, sizeof(int), compare);     //배열 내림차순 정렬

    while (k <= candidate[0]) {     //다솜이가 최다득표자가 아닌 동안
        candidate[0]--; //최다득표자 지지자 한명 매수
        k++;
        count++;

        qsort(candidate, n - 1, sizeof(int), compare);     //배열 내림차순 정렬
    }

    printf("%d\n", count);

    return 0;
}