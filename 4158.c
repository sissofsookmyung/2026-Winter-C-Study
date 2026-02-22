/*
동일한 숫자인지 검사하는 comp함수 정의
첫째줄에 두 개의 정수 입력받아
정수 크기 만큼의 동적 배열이나 리스트나 그런 거 동적 할당
다음 줄에 처음으로 입력받은 수만큼 숫자 입력 받고
그 다음줄부터 두 번째로 입력받은 수만큼 숫자 입력 받아서 배열에 저장
동일한 숫자가 있는지 comp함수로 비교해서 동일하면 count 증가
전부 비교했다면 
동적 할당 받았던 거 메모리 해제
count 출력
*/
#include <stdio.h>
#include <stdlib.h>

int comp(int* a, int n, int* b, int m) {
    int count = 0;  //동일한 cd개수
    int p1 = 0, p2 = 0; //비교 중인 인덱스 위치 

    while (p1 < n && p2 < m) {  //배열 끝까지 점사할 때까지
        if (a[p1] == b[p2]) {   //배열의 원소 일치한 경우
            count++;
            p1++;   //가리키는 인덱스 옆으로 옮김
            p2++;
        } else if (a[p1] < b[p2]) { //원소가 다른 경우 한쪽의 참조할 인덱스 조정함
            p1++; 
        } else {
            p2++;
        }
    }
    return count;
}

int main(){
    int n,m;

    while(scanf("%d %d", &n, &m) == 2){ //테스트 시작과 끝에 두 개의 정수(n,m 혹은 0,0) 입력 받기 성공하면
        if (n==0 && m==0){ //종료조건
            break;
        }

        int* sg = (int*)malloc(sizeof(int)*n);  //갖고 있는 cd개수만큼 동적 배열 할당
        int* sy = (int*)malloc(sizeof(int)*m);

        for (int i = 0; i < n; i++){    //cd번호 입력받기
            scanf("%d", &sg[i]);
        }
        for (int j = 0; j < m; j++) {
            scanf("%d", &sy[j]);
        }

        int result = comp(sg, n, sy, m);   //동일한 cd 개수 세는 함수

        printf("%d\n", result);

        free(sg);   //동적 배열 해제
        free(sy);
    }
    return 0;
}