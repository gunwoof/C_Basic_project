#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int level; 
int fishPot[6]; 
int * cursor;

void initData();
void printFishes();
void decreaseWater(long previousTime);
int checkFishAlive();

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
	initData(); //레벨지정, 어항만들기

	cursor = fishPot;

	startTime = clock(); // 현재시간은 1/1000초로 반환

	// 무한 루프
	while(1) {  
	printFishes(); // 숫자와 어항 보여줌
	printf("\n 몇 번 어항에 물을 주시겠어요?\n");
	scanf_s("%d", &num); // 사용자 번호 입력
	printf("\n");

	// 입력값 체크
	if (num < 1 || num > 6) {
		printf("\n입력값이 잘못되었습니다!\n");
		continue;
	}

	// 총 경과 시간
	totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
	printf("총 경과시간은 %ld초\n", totalTime);

	// 직전에 물을 준 시간 이후로 흐른시간
	previousTime = totalTime - previousTime;
	printf("최근 경과 시간 : %ld초 \n", previousTime);

	// 어항의 물 감소(증발)
	decreaseWater(previousTime);

	// 사용자가 입력한 어항에 물을 준다
	// 1. 어항의 물이 0이면 물을 주지 않는다
	if (cursor[num - 1] <= 0) {
		printf("%d의 물고기는 뒤졌습니다\n", num);
	}
	// 2. 어항의 물이 0이 아니면 물을 준다, 100을 넘지 않는지 체크
	else if(0 < cursor[num - 1] && cursor[num - 1] < 100) {
		printf("%d번 어항에 물을 줍니다\n", num);
		cursor[num - 1] += 1;
	}

	// 레벨 업 (20초마다 한번씩 수행)
	if (totalTime / 20 > level - 1) {
		level++;
		printf("\n\n####level up입니다. %d라운드####\n\n", level);
		
		// 최종 level 5
		if (level == 5) {
			printf("\n\n###축하합니다. 게임을 클리어 하였습니다###\n\n");
			exit(0);
		}
	}

	// 물고기가 죽었는지 확인    
	if (checkFishAlive() == 0) {
		printf("\n\n\n\n###물고기가 모두 뒤졌습니다ㅜㅜ###\n\n\n\n\n\n\n\n"); // 물고기 모두 뒤짐
		exit(0);
	}
	else if(checkFishAlive() == 1){
		printf("\n물고기가 아직 살아 있어요!\n\n\n\n\n\n\n\n"); // 물고기가 한마리라도 살아 있음
	}

	// 다음 시간을 재기위한 기준점
	previousTime = totalTime; 
	}
}

void initData() {
	level = 1; // 게임 레벨(1~5)
	for (int i = 0; i < 6; i++) {
		fishPot[i] = 100;
	}

}

void printFishes() {
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", fishPot[i]);
	}
	printf("\n\n");
}

void decreaseWater(long previousTime) {
	for(int i = 0; i < 6; i++) {
		fishPot[i] -= (level * 3 * /*(long)*/previousTime); // 3은 난이도 조절을 위한 값
		if (fishPot[i] < 0) {
			fishPot[i] = 0;
		}
	}
}

int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (fishPot[i] > 0) {
			return 1; // 물이 있다 (어항이 한개라도 살아있으면 1이 반환 because return값이 반환 되는 순간 함수가 종료됨)
		}
	}
	return 0; // 물이 없다
}
