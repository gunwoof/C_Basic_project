#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Randomnumber(int level);
void Printnumber(int level, int num1, int num2);
void Correct_conditional(int num1, int num2, int answer);

int main_function(void) {
	//������Ʈ
	//��й�ȣ ����(���� �� ����� ���� Ǯ��)
	
	srand(time(NULL));
	for (int i = 1; i <= 5; i++) {
		int num1 = Randomnumber(i);
		int num2 = Randomnumber(i);
		Printnumber(i,num1, num2);

		int answer = 0;
		scanf_s("%d", &answer);
		Correct_conditional(num1, num2, answer);	
	}
	printf("\n\n###�����մϴ�. ����� �����Ǿ����ϴ�###");
}


//�������� ���� �ޱ�
int Randomnumber(int level) {
	return rand() % (level*5) + 1;
}

//���� �����ֱ�
void Printnumber(int level, int num1, int num2) {
	printf("\n\n\n#### %d��° ��й�ȣ #####\n\n\n", level);
	printf("%d x %d�� �����Դϱ�?", num1, num2);
}

//���� �Ǻ�
void Correct_conditional(int num1, int num2, int answer) {
	if (num1 * num2 == answer) {
		printf("�����Դϴ�");
	}
	else {
		printf("�����Դϴ�");
		exit(0);
	}
}