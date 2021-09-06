#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int allAnimalcard[4][5]; // ī�� ī�� 20�� (4�� 5��)
char * strAnimal[10];

void initAnimalArray();
void initAnimalName(); 
void shuffleAnimal();
int getEmptyPosition();
int convert_position_x();
int convert_position_y();

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

		printAnials(); // ���� ��ġ ���
		printQuestion(); // ���� ���(ī�� ����)
		printf("������ ī�带 2�� ������ : ");
		scanf_s("%d %d", &select1, &select2);

		// ���� ī�� ���ý� ��ȿó��
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

			allAnimalcard[4][5] = i;
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

		if (allAnimalcard[4][5] == -1) {
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

