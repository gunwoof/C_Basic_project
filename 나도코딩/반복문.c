#include <stdio.h>

int main_repeatation(void)
{
	// ������Ʈ
	// �Ƕ�̵� �ױ�
	// �� ��, �ױ� �ݺ�

	int floor;
	printf("�� ���� ������ �̴ϱ�?");
	scanf_s("%d", &floor);

	for (int i = 1; i <= floor; i++) {
		for (int j = 0; j < floor-i; j++) {
			printf(" ");
		}
		for (int l = 0; l < 2*i - 1; l++) {
			printf("*");
		}
		printf("\n");
	}
}