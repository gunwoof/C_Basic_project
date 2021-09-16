#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int allAnimalcard[4][5]; // 카드 20장 (4행 5열)
char * strAnimal[10];
int checkAnimal[4][5]; // 뒤집혔는지 여부 확인

void initAnimalArray();
void initAnimalName(); 
void shuffleAnimal();
void printAnimals(); 
void printQuestion();
int getEmptyPosition();
int convert_position_x();
int convert_position_y();
int foundAllAnimals();

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

		printAnimals(); // 동물 위치 출력
		printQuestion(); // 문제 출력(카드 지도)
		printf("\n뒤집을 카드를 2개 고르세요 : ");
		scanf_s("%d %d", &select1, &select2);

		// 같은 카드 선택시 무효처리
		if (select1 == select2) {
			continue;
		}

		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 다른지 확인
		// 정수 좌표를 (x,y)로 변환
		int firstSelect_x = convert_position_x(select1);
		int firstSelect_y = convert_position_y(select1);

		int secondSelect_x = convert_position_x(select2);
		int secondSelect_y = convert_position_y(select2);

		// 같은 동물일 경우
		if (checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0  // 뽑히지 않았고

			&&

			allAnimalcard[firstSelect_x][firstSelect_y] == allAnimalcard[secondSelect_x][secondSelect_y] // 첫번째 선택과 두번째 선택의 카드가 같으면
			) {
			printf("\n\n 빙고! : %s발견\n\n", strAnimal[allAnimalcard[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}

		// 다른 동물일 경우
		else {
			printf("\n\n 땡!! (틀렸거나, 이미 뒤집힌 카드 입니다!)\n");
			printf("%d : %s\n", select1, strAnimal[allAnimalcard[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[allAnimalcard[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++; // 틀린횟수
		}

		// 모든 동물을 찾았는지 여부 (참 : 1, 거짓 : 0)
		if (foundAllAnimals() == 1) {
			printf("\n\n 축하합니다 ! 모든 동물을 다 찾았습니다 \n");
			printf("지금까지 총 %d번 실수 하였습니다\n", failCount);
			break;
		}

	}
}

void initAnimalArray() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
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

			allAnimalcard[x][y] = i;
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

		if (allAnimalcard[x][y] == -1) {
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

void printAnimals() {

	// ex
	//ㅁㅁㅁㅁㅁ 0  0  1  1  2 
	//ㅁㅁㅁㅁㅁ 2  3  3  4  4 
	//ㅁㅁㅁㅁㅁ 5  5  6  6  7
	//ㅁㅁㅁㅁㅁ 7  8  8  9  9
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[allAnimalcard[i][j]]);
		}
		printf("\n");
	}
	printf("\n========================\n\n");
}

void printQuestion() {
	printf("\n\n문제\n\n");

	// 0  1  2  3  4 
	// 5  기린  7  8  9
	// 10 11 기린 13 14 
	// 15 16 17 18 19
	int seq = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			// 카드를 뒤집어서 정답을 맞췄으면 '동물이름'
			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[allAnimalcard[i][j]]);
			}
			// 뒤집히지 않았으면 (아직 정답을 못 맞힌) '위치를 나타내는 숫자'
			else {
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (checkAnimal[i][j] == 0) {
				return 0;
			}
		}
	}
	return 1;
}