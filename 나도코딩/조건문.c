#include <stdio.h>
#include <time.h>

int main_conditional(void) {

	// ������Ʈ
	// up & down game

	srand(time(NULL));
	int i = rand() % 100 + 1; //1���� 100���� ����
	int chance = 5;
	int answer;
	while(chance > 0) {
		printf("%d�� ���ҽ��ϴ�\n", chance--);
		printf("���ڸ� ���纸����(0~100) : ");
		scanf_s("%d", &answer);
		
		if (answer > i) {
			printf("down down\n\n");
		}
		else if(answer < i) {
			printf("up up\n\n");
		}
		else{
			printf("�����Դϴ�\n\n");
			break;
		}
		
		
		if (chance == 0) {
			printf("������ %d\n", i);
			printf("��ȸ�� �����ϴ�");
			break;
		}
		
			
	}
	
}