#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* day; //dp를 저장할 배열, 반납일자까지 남은 기한이 됨

int main() {
	int n; //반납 일자
	int chap;

	//dp배열 생성 및 초기화
	scanf("%d %d", &n, &chap);
	day = (int*)malloc(sizeof(int) * (n+1));
	for (int i = 0; i <= n; i++)
		day[i] = 0;

	//한 챕터를 읽는 데 필요한 날짜와 읽을 수 있는 페이지를 저장할 배열들 초기화
	int* need = (int*)malloc(sizeof(int) * chap);
	int* page = (int*)malloc(sizeof(int) * chap);

	for (int i = 0; i < chap; i++) {
		scanf("%d %d", &need[i], &page[i]);
	}

	//dp 배열을 돌림
	for (int i = 0; i < chap; i++) {
		int cost = need[i]; //i번째 챕터를 읽는 데 드는 시간
		int read = page[i]; //i번째 챕터를 읽으면 얻을 수 있는 page

		//중복으로 세는 것을 방지하기 위해 거꾸로 시작함
		for (int j = n; j >= cost; j--) {
			if (day[j - cost] + read > day[j]) 
				day[j] = day[j - cost] + read; //현재 cost를 썼을 때 최대인가? 를 판단해야 하므로 day[j] (cost를 사용한 인덱스) 값을 변경해줌
		}
	}

	//최댓값 확인해 출력
	int result = 0;
	for (int i = 0; i <= n; i++) {
		if (day[i] > result)
			result = day[i];
	}

	printf("%d", result);
	free(day);
	free(need);
	free(page);
}