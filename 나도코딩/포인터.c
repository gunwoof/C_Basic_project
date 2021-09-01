#include <stdio.h>
#include <time.h>


int level; 
int fishPot[6]; 
int * cursor;
void initData();
void printFishes();
void decreaseWater(long previousTime);


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
	initData();

	cursor = fishPot;

	startTime = clock(); // ����ð��� 1/1000�ʷ� ��ȯ

	while(1) {
	printFishes();
	printf("�� �� ���׿� ���� �ֽðھ��?");
	scanf_s("%d", &num);

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

	// ���� ��
	if()
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
