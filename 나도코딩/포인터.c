#include <stdio.h>
#include <time.h>


// int level; �ʿ� ������ �� ����
int fishPot[6]; //�ʿ� ������ �� ����
int * cursor;
void initData();


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
	}

void initData() {
	int level = 1; // ���� ����(1~5)
	for (int i = 0; i < 6; i++) {
		fishPot[i] = 100;
	}

}