#include <stdio.h>
#include <time.h>

int main(void) {
	//������Ʈ
	//�ƺ��� ��Ӹ� ����

	srand(time(NULL));
	int answer = 0; //����� �Է� ��
	int treatment_choice = 0; //�߸��� ����

	int Currentbottle = 0; //�̹� ��鿡�� �����ִ� �� ����
	int Previousbottle = 0; //�� ��鿡�� �����ִ� �� ����
	// ( ��鸶�� �� ������ �ٸ��� �Ͽ�  ����� ��� (ex ó�� 2, ���� 3) )
	
	// 3���� �߸��� ���� �õ�
	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0,0,0,0 }; //4���� ��
		do {
			Currentbottle = rand() % 2 + 2; // 0~1 -> 2~3
			Currentbottle = Previousbottle; //���ǹ��� ��� �ݺ��� ����
		} while (Currentbottle == Previousbottle); 
	}

}