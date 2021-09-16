#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int allAnimalcard[4][5]; // ī�� 20�� (4�� 5��)
char * strAnimal[10];
int checkAnimal[4][5]; // ���������� ���� Ȯ��

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

	// ������Ʈ
	// ���� ������
	// 10������ ���� �ٸ� ���� (�� ī�� 2�徿)
	// ����ڷκ��� 2���� �Է°��� ���� -> ���� ���� ������ ī�� ������
	// ��� ���� ���� ���߸� ����
	// �� ���� Ƚ�� �˷��ֱ�

	srand(time(NULL));

	initAnimalArray(); // ���� ī�� 20�� ���� (4�� 5��)
	initAnimalName(); // ���� �̸� ����

	shuffleAnimal(); // ī�� ����

	int failCount = 0; // ���� Ƚ��

	while (1) {
		int select1 = 0; // ����ڰ� ������ ó�� ��
		int select2 = 0; // ����ڰ� ������ ó�� ��

		printAnimals(); // ���� ��ġ ���
		printQuestion(); // ���� ���(ī�� ����)
		printf("\n������ ī�带 2�� ������ : ");
		scanf_s("%d %d", &select1, &select2);

		// ���� ī�� ���ý� ��ȿó��
		if (select1 == select2) {
			continue;
		}

		// ��ǥ�� �ش��ϴ� ī�带 ������ ���� ������ �ٸ��� Ȯ��
		// ���� ��ǥ�� (x,y)�� ��ȯ
		int firstSelect_x = convert_position_x(select1);
		int firstSelect_y = convert_position_y(select1);

		int secondSelect_x = convert_position_x(select2);
		int secondSelect_y = convert_position_y(select2);

		// ���� ������ ���
		if (checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0  // ������ �ʾҰ�

			&&

			allAnimalcard[firstSelect_x][firstSelect_y] == allAnimalcard[secondSelect_x][secondSelect_y] // ù��° ���ð� �ι�° ������ ī�尡 ������
			) {
			printf("\n\n ����! : %s�߰�\n\n", strAnimal[allAnimalcard[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}

		// �ٸ� ������ ���
		else {
			printf("\n\n ��!! (Ʋ�Ȱų�, �̹� ������ ī�� �Դϴ�!)\n");
			printf("%d : %s\n", select1, strAnimal[allAnimalcard[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[allAnimalcard[secondSelect_x][secondSelect_y]]);
			printf("\n\n");

			failCount++; // Ʋ��Ƚ��
		}

		// ��� ������ ã�Ҵ��� ���� (�� : 1, ���� : 0)
		if (foundAllAnimals() == 1) {
			printf("\n\n �����մϴ� ! ��� ������ �� ã�ҽ��ϴ� \n");
			printf("���ݱ��� �� %d�� �Ǽ� �Ͽ����ϴ�\n", failCount);
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
	strAnimal[0] = "������";
	strAnimal[1] = "�䳢";
	strAnimal[2] = "�ϸ�";
	strAnimal[3] = "��";
	strAnimal[4] = "�����";
	strAnimal[5] = "����";
	strAnimal[6] = "�ڳ���";
	strAnimal[7] = "�⸰";
	strAnimal[8] = "��Ÿ";
	strAnimal[9] = "Ÿ��";
}

void shuffleAnimal() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			int pos = getEmptyPosition(); //��ǥ���� �� ���� ã��
			int x = convert_position_x(pos); // x��ǥ
			int y = convert_position_y(pos); // y��ǥ

			allAnimalcard[x][y] = i;
		}
	}
}

// ��ǥ���� �� ���� ã��
int getEmptyPosition() {

	//���������� 0  1  2  3  4 
	//���������� 5  6  7  8  9 
	//���������� 10 11 12 13 14 
	//���������� 15 16 17 18 19
	while (1) {
		int Randomposition = rand() % 20; // 0~19

		// ex) 19 -> (3.4)
		int x = convert_position_x(Randomposition); // x��ǥ
		int y = convert_position_y(Randomposition); // y��ǥ

		if (allAnimalcard[x][y] == -1) {
			return Randomposition;
		}
	}
	return 0; //�ǹ� ����
}

// x��ǥ
int convert_position_x(int x) {
	// ex) 19 -> (3,4)   ���� 3 ���� ��
	return x / 5; // x�� 5�� ���� ��
}

// y��ǥ
int convert_position_y(int y) {
	// ex) 19 -> (3, 4)   ���� 4���� ��
	return y % 5; // y�� 5�� ���� ������
}

void printAnimals() {

	// ex
	//���������� 0  0  1  1  2 
	//���������� 2  3  3  4  4 
	//���������� 5  5  6  6  7
	//���������� 7  8  8  9  9
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%8s", strAnimal[allAnimalcard[i][j]]);
		}
		printf("\n");
	}
	printf("\n========================\n\n");
}

void printQuestion() {
	printf("\n\n����\n\n");

	// 0  1  2  3  4 
	// 5  �⸰  7  8  9
	// 10 11 �⸰ 13 14 
	// 15 16 17 18 19
	int seq = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			// ī�带 ����� ������ �������� '�����̸�'
			if (checkAnimal[i][j] != 0) {
				printf("%8s", strAnimal[allAnimalcard[i][j]]);
			}
			// �������� �ʾ����� (���� ������ �� ����) '��ġ�� ��Ÿ���� ����'
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