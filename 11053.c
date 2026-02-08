#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	int size;
	scanf("%d", &size);

	//DP를 저장할 배열 생성 및 초기화
	int* dp = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		dp[i] = 1;
	}

	//입력받은 한 줄을 나눠 배열에 저장
	int* arr = (int*)malloc(sizeof(int) * size);
	int n = 0;
	while (n < size && scanf("%d", &arr[n]) == 1) {
		n++;
	}

	//DP를 돌려서 각 숫자로 끝날 때 가질 수 있는 최대 길이의 subset 구하기
	for (int i = 1; i < size; i++) {
		for (int find = 0; find < i; find++) {
			if (arr[i] > arr[find] && dp[i] < dp[find] + 1) {
				dp[i] = dp[find] + 1;
			}
		}
	}

	//DP 배열에 존재하는 가장 큰 수(가장 긴 증가하는 부분 수열의 길이) 찾기
	int result = -9999;
	for (int i = 0; i < size; i++) {
		if (dp[i] > result)
			result = dp[i];
	}

	printf("%d", result);

}
