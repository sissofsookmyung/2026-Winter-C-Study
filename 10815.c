#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { //정렬 함수(이진 탐색 전처리 위함)
    return (*(int *)a - *(int *)b);
}

int binary_search(int arr[], int size, int target) { //이진 탐색
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return 1; //찾음
        else if (arr[mid] < target) low = mid + 1; //탐색 범위 조정
        else high = mid - 1;
    }
    return 0;
}

int main() {
    int n, m; //성근이가 갖고 있는 카드 개수, 비교할 카드 개수

    scanf("%d", &n);     
    
    //상근이가 갖고 있는 카드 입력 받아 동적 배열에 저장
    int *mycards = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &mycards[i]);
    }

    qsort(mycards, n, sizeof(int), compare); //배열 오름차순 정렬

    scanf("%d", &m);    
    
    for (int i = 0; i < m; i++) {
        int samplecards;
        scanf("%d", &samplecards); //비교할 카드의 숫자 입력 받음 

        //이진탐색으로 mycards에 동일 숫자 존재하는지 검사
        if (binary_search(mycards, n, samplecards)) {
            printf("1 "); 
        } else {
            printf("0 ");
        }
    }

    free(mycards);  //동적 배열 해제
    return 0;
}
