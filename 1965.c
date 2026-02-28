#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); 

    int arr[1001];     // 상자 크기
    int b[1001];      // 상자를 포갤 수 있는 최대 개수
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        b[i] = 1;     // 자기자신 가능 
    }    
    int max = 1;  

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && b[i] < b[j] + 1) {//앞상자가 더 작다면 넣을 수 있다
                b[i] = b[j] + 1;  // 포갤 수 있는 상자가 더 많 경우
            }
        }
        if(b[i] > max)
            max = b[i];
    }

    printf("%d", max);

    return 0;
}
