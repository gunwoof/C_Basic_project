#include <stdio.h>

int main_repeatation(void)
{
	// 프로잭트
	// 피라미드 쌓기
	// 몇 층, 쌓기 반복

	int floor;
	printf("몇 층을 쌓으실 겁니까?");
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