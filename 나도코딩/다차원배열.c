#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int allAnimalcard[4][5]; // ī�� ���� 20��
char * strAnimal[10];

void initAnimalArray();
void initAnimalName();

int main(void) {
	
	// ������Ʈ
	// ���� ������
	// 10������ ���� �ٸ� ���� (�� ī�� 2�徿)
	// ����ڷκ��� 2���� �Է°��� ���� -> ���� ���� ������ ī�� ������
	// ��� ���� ���� ���߸� ����
	// �� ���� Ƚ�� �˷��ֱ�

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