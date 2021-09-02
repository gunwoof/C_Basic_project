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
	
	// ������Ʈ
	// ����� Ű���
	// ���� ����
	// ���� �ϱ� ���� �������� ���ֱ�
	// �ð��� ���� ���� ������ Ŀ�� -> �Ա�

	long startTime = 0; // ���� ���� �ð�
	long totalTime = 0; // �� ��� �ð�
	long previousTime = 0; // ���� �� ��� �ð�(�ֱ��� ���� �� �ð� ����)

	int num = 0; // �� �� ���׿� ���� �� ������, ����� �Է�
	initData(); //��������, ���׸����

	cursor = fishPot;

	startTime = clock(); // ����ð��� 1/1000�ʷ� ��ȯ

	// ���� ����
	while(1) {  
	printFishes(); // ���ڿ� ���� ������
	printf("\n �� �� ���׿� ���� �ֽðھ��?\n");
	scanf_s("%d", &num); // ����� ��ȣ �Է�
	printf("\n");

	// �Է°� üũ
	if (num < 1 || num > 6) {
		printf("\n�Է°��� �߸��Ǿ����ϴ�!\n");
		continue;
	}

	// �� ��� �ð�
	totalTime = (clock() - startTime) / CLOCKS_PER_SEC;
	printf("�� ����ð��� %ld��\n", totalTime);

	// ������ ���� �� �ð� ���ķ� �帥�ð�
	previousTime = totalTime - previousTime;
	printf("�ֱ� ��� �ð� : %ld�� \n", previousTime);

	// ������ �� ����(����)
	decreaseWater(previousTime);

	// ����ڰ� �Է��� ���׿� ���� �ش�
	// 1. ������ ���� 0�̸� ���� ���� �ʴ´�
	if (cursor[num - 1] <= 0) {
		printf("%d�� ������ �������ϴ�\n", num);
	}
	// 2. ������ ���� 0�� �ƴϸ� ���� �ش�, 100�� ���� �ʴ��� üũ
	else if(0 < cursor[num - 1] && cursor[num - 1] < 100) {
		printf("%d�� ���׿� ���� �ݴϴ�\n", num);
		cursor[num - 1] += 1;
	}

	// ���� �� (20�ʸ��� �ѹ��� ����)
	if (totalTime / 20 > level - 1) {
		level++;
		printf("\n\n####level up�Դϴ�. %d����####\n\n", level);
		
		// ���� level 5
		if (level == 5) {
			printf("\n\n###�����մϴ�. ������ Ŭ���� �Ͽ����ϴ�###\n\n");
			exit(0);
		}
	}

	// ����Ⱑ �׾����� Ȯ��    
	if (checkFishAlive() == 0) {
		printf("\n\n\n\n###����Ⱑ ��� �������ϴ٤̤�###\n\n\n\n\n\n\n\n"); // ����� ��� ����
		exit(0);
	}
	else if(checkFishAlive() == 1){
		printf("\n����Ⱑ ���� ��� �־��!\n\n\n\n\n\n\n\n"); // ����Ⱑ �Ѹ����� ��� ����
	}

	// ���� �ð��� ������� ������
	previousTime = totalTime; 
	}
}

void initData() {
	level = 1; // ���� ����(1~5)
	for (int i = 0; i < 6; i++) {
		fishPot[i] = 100;
	}

}

void printFishes() {
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", fishPot[i]);
	}
	printf("\n\n");
}

void decreaseWater(long previousTime) {
	for(int i = 0; i < 6; i++) {
		fishPot[i] -= (level * 3 * /*(long)*/previousTime); // 3�� ���̵� ������ ���� ��
		if (fishPot[i] < 0) {
			fishPot[i] = 0;
		}
	}
}

int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (fishPot[i] > 0) {
			return 1; // ���� �ִ� (������ �Ѱ��� ��������� 1�� ��ȯ because return���� ��ȯ �Ǵ� ���� �Լ��� �����)
		}
	}
	return 0; // ���� ����
}
