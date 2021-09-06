#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int allAnimalcard[4][5]; // 朝球 朝球 20舌 (4楳 5伸)
char * strAnimal[10];

void initAnimalArray();
void initAnimalName(); 
void shuffleAnimal();
int getEmptyPosition();
int convert_position_x();
int convert_position_y();

int main(void) {
	
	// 覗稽先闘
	// 疑弘 及増奄
	// 10原軒税 辞稽 陥献 疑弘 (唖 朝球 2舌梢)
	// 紫遂切稽採斗 2鯵税 脊径葵聖 閤製 -> 旭精 疑弘 蟹神檎 朝球 及増奄
	// 乞窮 疑弘 瞬聖 限蓄檎 曽戟
	// 恥 叔鳶 判呪 硝形爽奄

	srand(time(NULL));

	initAnimalArray(); // 疑弘 朝球 20舌 識情 (4楳 5伸)
	initAnimalName(); // 疑弘 戚硯 走舛

	shuffleAnimal(); // 朝球 鹿奄

	int failCount = 0; // 叔鳶 判呪

	while (1) {
		int select1 = 0; // 紫遂切亜 識澱廃 坦製 呪
		int select2 = 0; // 紫遂切亜 識澱廃 坦製 呪

		printAnials(); // 疑弘 是帖 窒径
		printQuestion(); // 庚薦 窒径(朝球 走亀)
		printf("及増聖 朝球研 2鯵 壱牽室推 : ");
		scanf_s("%d %d", &select1, &select2);

		// 旭精 朝球 識澱獣 巷反坦軒
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
	strAnimal[0] = "据周戚";
	strAnimal[1] = "塘晦";
	strAnimal[2] = "馬原";
	strAnimal[3] = "鯵";
	strAnimal[4] = "壱丞戚";
	strAnimal[5] = "掬走";
	strAnimal[6] = "坪晦軒";
	strAnimal[7] = "奄鍵";
	strAnimal[8] = "開展";
	strAnimal[9] = "展繕";
}

void shuffleAnimal() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int pos = getEmptyPosition(); //疎妊拭辞 朔 因娃 達奄
			int x = convert_position_x(pos); // x疎妊
			int y = convert_position_y(pos); // y疎妊

			allAnimalcard[4][5] = i;
		}
	}
}

// 疎妊拭辞 朔 因娃 達奄
int getEmptyPosition() {

	//けけけけけ 0  1  2  3  4 
	//けけけけけ 5  6  7  8  9 
	//けけけけけ 10 11 12 13 14 
	//けけけけけ 15 16 17 18 19
	while (1) {
		int Randomposition = rand() % 20; // 0~19

		// ex) 19 -> (3.4)
		int x = convert_position_x(Randomposition); // x疎妊
		int y = convert_position_y(Randomposition); // y疎妊

		if (allAnimalcard[4][5] == -1) {
			return Randomposition;
		}
	}
	return 0; //税耕 蒸製
}

// x疎妊
int convert_position_x(int x) {
	// ex) 19 -> (3,4)   拭辞 3 姥拝 凶
	return x / 5; // x研 5稽 蟹勧 交
}

// y疎妊
int convert_position_y(int y) {
	// ex) 19 -> (3, 4)   拭辞 4姥拝 凶
	return y % 5; // y研 5稽 蟹勧 蟹袴走
}

