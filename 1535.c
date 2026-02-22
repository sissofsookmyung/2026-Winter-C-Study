#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int happy(int* life, int* joy, int size) {
	int f_life = 100;

	//얻을 수 있는 최대 행복을 저장할 dp배열 초기화 - 체력 수만큼 dp배열 길이를 설정해 따로 체력을 설정하지 않도록 함
	int dp[100];
	for (int i = 0; i < 100; i++) {
		dp[i] = 0;
	}

	//dp 배열을 돌면서 얻을 수 있는 기쁨이 크다면, 그 값을 갱신함
	for (int i = 0; i < size; i++) {
		int cost = life[i];
		int good = joy[i];

		//99부터 시작해야 예를 들어 필요한 에너지가 30인 경우 30~99까지의 배열이 설정됨
		for (int j = 99; j >= cost; j--) {
			//사용한 에너지 칸에 얻을 수 있는 기쁨을 더한 거랑 기존에 가지고 있던 기쁨을 비교
			if (dp[j - cost]+ good > dp[j] ) {
				//새롭게 얻을 수 있는 기쁨이 더 큰 경우 갱신해줌
				dp[j] = dp[j-cost] + good;
			}
		}
	}

	//dp 배열 중 가장 큰 기쁨을 출력
	int final = 0;
	for (int i = 0; i < 100; i++) {
		if (dp[i] > final)
			final = dp[i];
	}

	return final;
}


int main() {
	int size;
	scanf("%d", &size);

	int* life = (int*)malloc(sizeof(int) * size);
	int* joy = (int*)malloc(sizeof(int) * size);

	int n = 0;

	//life배열에 인사 시 드는 생명력 저장
	while (n < size && scanf("%d", &life[n]) == 1) {
		n++;
	}

	//joy 배열에 인사 시 얻을 수 있는 기쁨 저장
	int r = 0;
	while (r < size && scanf("%d", &joy[r]) == 1) {
		r++;
	}


	printf("%d", happy(life, joy, size));

}

    