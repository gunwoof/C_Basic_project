#include <stdio.h>
#include <time.h>


// int level; 필요 없으면 안 적기
int fishPot[6]; //필요 없으면 안 적기
int * cursor;
void initData();


int main(void) {
	
	// 프로잭트
	// 물고기 키우기
	// 물이 증발
	// 증발 하기 전에 부지런히 물주기
	// 시간이 지날 수록 물고기는 커짐 -> 먹기

	long startTime = 0; // 게임 시작 시간
	long totalTime = 0; // 총 경과 시간
	long previousTime = 0; // 직전 것 경과 시간(최근의 물을 준 시간 간격)

	int num = 0; // 몇 번 어항에 물을 줄 것인지, 사용자 입력
	initData();

	cursor = fishPot;

	startTime = clock(); // 현재시간은 1/1000초로 반환
	}

void initData() {
	int level = 1; // 게임 레벨(1~5)
	for (int i = 0; i < 6; i++) {
		fishPot[i] = 100;
	}

}