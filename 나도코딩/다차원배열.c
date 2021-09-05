#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int allAnimalcard[4][5]; // 카드 지도 20장
char * strAnimal[10];

void initAnimalArray();
void initAnimalName();

int main(void) {
	
	// 프로잭트
	// 동물 뒤집기
	// 10마리의 서로 다른 동물 (각 카드 2장씩)
	// 사용자로부터 2개의 입력값을 받음 -> 같은 동물 나오면 카드 뒤집기
	// 모든 동물 쌍을 맞추면 종료
	// 총 실패 횟수 알려주기

	srand(time(NULL));

	initAnimalArray();
	initAnimalName();

}

void initAnimalArray() {
	for (int i; i < 4; i++) {
		for (int j; j < 5; j++) {
			allAnimalcard[4][5] = -1;
		}
	}
}

void initAnimalName() {

}