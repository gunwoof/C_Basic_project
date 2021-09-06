#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int allAnimalcard[4][5]; // 카드 카드 20장 (4행 5열)
char * strAnimal[10];

void initAnimalArray();
void initAnimalName(); 
void shuffleAnimal();
int getEmptyPosition();
int convert_position_x();
int convert_position_y();

int main(void) {
	
	// 프로잭트
	// 동물 뒤집기
	// 10마리의 서로 다른 동물 (각 카드 2장씩)
	// 사용자로부터 2개의 입력값을 받음 -> 같은 동물 나오면 카드 뒤집기
	// 모든 동물 쌍을 맞추면 종료
	// 총 실패 횟수 알려주기

	srand(time(NULL));

	initAnimalArray(); // 동물 카드 20장 선언 (4행 5열)
	initAnimalName(); // 동물 이름 지정

	shuffleAnimal(); // 카드 섞기

	int failCount = 0; // 실패 횟수

	while (1) {
		int select1 = 0; // 사용자가 선택한 처음 수
		int select2 = 0; // 사용자가 선택한 처음 수

		printAnials(); // 동물 위치 출력
		printQuestion(); // 문제 출력(카드 지도)
		printf("뒤집을 카드를 2개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		// 같은 카드 선택시 무효처리
		if (select1 == select2) {
			continue;
		}
	}

}

void initAnimalArray() {
	for (int i; i < 4; i++) {
		for (int j; j < 5; j++) {
			allAnimalcard[i][j] = -1;
		}
	}
}

void initAnimalName() {
	strAnimal[0] = "원숭이";
	strAnimal[1] = "토끼";
	strAnimal[2] = "하마";
	strAnimal[3] = "개";
	strAnimal[4] = "고양이";
	strAnimal[5] = "돼지";
	strAnimal[6] = "코끼리";
	strAnimal[7] = "기린";
	strAnimal[8] = "낙타";
	strAnimal[9] = "타조";
}

void shuffleAnimal() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int pos = getEmptyPosition(); //좌표에서 빈 공간 찾기
			int x = convert_position_x(pos); // x좌표
			int y = convert_position_y(pos); // y좌표

			allAnimalcard[4][5] = i;
		}
	}
}

// 좌표에서 빈 공간 찾기
int getEmptyPosition() {

	//ㅁㅁㅁㅁㅁ 0  1  2  3  4 
	//ㅁㅁㅁㅁㅁ 5  6  7  8  9 
	//ㅁㅁㅁㅁㅁ 10 11 12 13 14 
	//ㅁㅁㅁㅁㅁ 15 16 17 18 19
	while (1) {
		int Randomposition = rand() % 20; // 0~19

		// ex) 19 -> (3.4)
		int x = convert_position_x(Randomposition); // x좌표
		int y = convert_position_y(Randomposition); // y좌표

		if (allAnimalcard[4][5] == -1) {
			return Randomposition;
		}
	}
	return 0; //의미 없음
}

// x좌표
int convert_position_x(int x) {
	// ex) 19 -> (3,4)   에서 3 구할 때
	return x / 5; // x를 5로 나눈 몫
}

// y좌표
int convert_position_y(int y) {
	// ex) 19 -> (3, 4)   에서 4구할 때
	return y % 5; // y를 5로 나눈 나머지
}

