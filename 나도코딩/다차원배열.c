#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int allAnimalcard[4][5]; // 朝球 20舌 (4楳 5伸)
char * strAnimal[10];
int checkAnimal[4][5]; // 及増縛澗走 食採 溌昔

void initAnimalArray();
void initAnimalName(); 
void shuffleAnimal();
void printAnimals(); 
void printQuestion();
int getEmptyPosition();
int convert_position_x();
int convert_position_y();
int foundAllAnimals();

int main_multidimentionalArray(void) {

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

		printAnimals(); // 疑弘 是帖 窒径
		printQuestion(); // 庚薦 窒径(朝球 走亀)
		printf("\n及増聖 朝球研 2鯵 壱牽室推 : ");
		scanf_s("%d %d", &select1, &select2);

		// 旭精 朝球 識澱獣 巷反坦軒
		if (select1 == select2) {
			continue;
		}

		// 疎妊拭 背雁馬澗 朝球研 及増嬢 左壱 旭精走 陥献走 溌昔
		// 舛呪 疎妊研 (x,y)稽 痕発
		int firstSelect_x = convert_position_x(select1);
		int firstSelect_y = convert_position_y(select1);

		int secondSelect_x = convert_position_x(select2);
		int secondSelect_y = convert_position_y(select2);

		// 旭精 疑弘析 井酔
		if (checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0  // 嗣備走 省紹壱

			&&

			allAnimalcard[firstSelect_x][firstSelect_y] == allAnimalcard[secondSelect_x][secondSelect_y] // 湛腰属 識澱引 砧腰属 識澱税 朝球亜 旭生檎
			) {
			printf("\n\n 桜壱! : %s降胃\n\n", strAnimal[allAnimalcard[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}

		// 陥献 疑弘析 井酔
		else {
			printf("\n\n 強!! (堂携暗蟹, 戚耕 及増微 朝球 脊艦陥!)\n");
			printf("%d : %s\n", select1, strAnimal[allAnimalcard[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[allAnimalcard[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++; // 堂鍵判呪
		}

		// 乞窮 疑弘聖 達紹澗走 食採 (凧 : 1, 暗憎 : 0)
		if (foundAllAnimals() == 1) {
			printf("\n\n 逐馬杯艦陥 ! 乞窮 疑弘聖 陥 達紹柔艦陥 \n");
			printf("走榎猿走 恥 %d腰 叔呪 馬心柔艦陥\n", failCount);
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

			allAnimalcard[x][y] = i;
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

		if (allAnimalcard[x][y] == -1) {
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

void printAnimals() {

	// ex
	//けけけけけ 0  0  1  1  2 
	//けけけけけ 2  3  3  4  4 
	//けけけけけ 5  5  6  6  7
	//けけけけけ 7  8  8  9  9
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[allAnimalcard[i][j]]);
		}
		printf("\n");
	}
	printf("\n========================\n\n");
}

void printQuestion() {
	printf("\n\n庚薦\n\n");

	// 0  1  2  3  4 
	// 5  奄鍵  7  8  9
	// 10 11 奄鍵 13 14 
	// 15 16 17 18 19
	int seq = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			// 朝球研 及増嬢辞 舛岩聖 限宙生檎 '疑弘戚硯'
			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[allAnimalcard[i][j]]);
			}
			// 及増備走 省紹生檎 (焼送 舛岩聖 公 限微) '是帖研 蟹展鎧澗 収切'
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