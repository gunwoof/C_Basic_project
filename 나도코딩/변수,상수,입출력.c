#include <stdio.h>

int main_variouble(void)
{
	//������Ʈ
	//�����ۼ� : �������� �������� ������ �Լ�
	//�̸�, ����, Ű, ������, ���˸�

	char name[256];
	printf("�̸��� �Է��� �ּ��� :");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("���̸� �Է��� �ּ��� :");
	scanf_s("%d", &age);

	float height;
	printf("Ű�� �Է����ּ��� :");
	scanf_s("%f", &height);

	double weight;
	printf("�����Ը� �Է����ּ��� :");
	scanf_s("%lf", &weight);

	char crime_title[256];
	printf("�˸� �Է����ּ��� :");
	scanf_s("%s", crime_title, sizeof(crime_title));

	//���� ���� ���
	printf("\n\n--������ ����--\n\n");
	printf("�̸���       %s\n", name);
	printf("���̴�       %d��\n", age);
	printf("Ű��         %fcm\n", height);
	printf("�����Դ�     %lfkg\n", weight);
	printf("�˴�         %s\n", crime_title);
}