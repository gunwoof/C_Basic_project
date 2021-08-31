#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main_array(void) 
{
	// ������Ʈ
	// �ƺ��� ��Ӹ� ����

	srand((unsigned int)time(NULL));
	int treatment_choice = rand() % 4; //�߸��� ����

	int Currentbottle = 0; //�̹� ��鿡�� �����ִ� �� ����
	int Previousbottle = 0; //�� ��鿡�� �����ִ� �� ����
	// ( ��鸶�� �� ������ �ٸ��� �Ͽ�  ����� ��� (ex ó�� 2, ���� 3) )
	
	// 3���� �߸��� ���� �õ�
	for (int i = 1; i <= 3; i++) {
		printf("###%d��°�õ�###\n\n", i);

		do {
			Currentbottle = rand() % 2 + 2; // 0~1 -> 2~3
		} while (Currentbottle == Previousbottle);
		Previousbottle = Currentbottle; // ���ǹ��� ��� �ݺ��� ����

		int bottle[4] = { 0,0,0,0 }; //4���� ��
		int isincluded = 0; // ������ �� �߿� �߸����� �ִ��� ���� (1�̸� �߸��� ����)

		// ������ �� ����
		for (int j = 1; j <= Currentbottle; j++) {
			int randomBottle = rand() % 4; // �� �������� ����

			// ���� ���� ���� ���̸� ����ó��
			if (bottle[randomBottle] == 0) {
				bottle[randomBottle] = 1; //���� ���� ǥ�� (1�̸� ���� ��)
				if (randomBottle == treatment_choice) {
					isincluded = 1;
				}
			}
			// �̹� ���õ� ���̸� �ٽ� ����
			else {
				j--;
			}
		}

		// ����ڿ��� ���� ǥ��   ������ �ȳ���!!!!
		for (int k = 1; k <= 4; k++) {
			if(bottle[k] == 1) {
				printf("%d", k); // ������ �� ����
			}
		}
		printf("������ �Ӹ��� �ٸ��ϴ�\n\n");

		if (isincluded == 1) {
			printf("###���� : �Ӹ��� �����###\n\n"); // �߸��� ���� ���� �ߴٴ� �Ҹ�
		}
		else {
			printf("###���� : �Ӹ��� �״�ο���###\n\n"); // �߸��� ���� �������� �ʾҴٴ� �Ҹ�
		}
		
		printf("..! ����Ϸ��� �ƹ� Ű�� �����ÿ� !...\n\n");
		getchar();
	}

	int answer = 0; //����� �Է� ��
	printf("�߸����� �� �� �ϱ��?");
	scanf_s("%d", &answer);

	if (answer == treatment_choice) {
		printf("�����Դϴ�!");
	}
	else {
		printf("�����Դϴ�! ������ %d�Դϴ�", treatment_choice +1);
	}

}