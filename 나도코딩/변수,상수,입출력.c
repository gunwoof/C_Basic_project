#include <stdio.h>

int main_variouble(void)
{
	//프로잭트
	//조서작성 : 경찰관이 범죄자의 정보를 입수
	//이름, 나이, 키, 몸무게, 범죄명

	char name[256];
	printf("이름을 입력해 주세요 :");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("나이를 입력해 주세요 :");
	scanf_s("%d", &age);

	float height;
	printf("키를 입력해주세요 :");
	scanf_s("%f", &height);

	double weight;
	printf("몸무게를 입력해주세요 :");
	scanf_s("%lf", &weight);

	char crime_title[256];
	printf("죄를 입력해주세요 :");
	scanf_s("%s", crime_title, sizeof(crime_title));

	//조서 내용 출력
	printf("\n\n--범죄자 정보--\n\n");
	printf("이름은       %s\n", name);
	printf("나이는       %d살\n", age);
	printf("키는         %fcm\n", height);
	printf("몸무게는     %lfkg\n", weight);
	printf("죄는         %s\n", crime_title);
}