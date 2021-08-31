#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main_array(void) 
{
	// 프로잭트
	// 아빠는 대머리 게임

	srand((unsigned int)time(NULL));
	int treatment_choice = rand() % 4; //발모제 선택

	int Currentbottle = 0; //이번 장면에서 보여주는 병 개수
	int Previousbottle = 0; //앞 장면에서 보여주는 병 개수
	// ( 장면마다 병 개수를 다르게 하여  정답률 향상 (ex 처음 2, 다음 3) )
	
	// 3번의 발모제 투여 시도
	for (int i = 1; i <= 3; i++) {
		printf("###%d번째시도###\n\n", i);

		do {
			Currentbottle = rand() % 2 + 2; // 0~1 -> 2~3
		} while (Currentbottle == Previousbottle);
		Previousbottle = Currentbottle; // 조건문이 계속 반복될 조건

		int bottle[4] = { 0,0,0,0 }; //4개의 병
		int isincluded = 0; // 보여줄 병 중에 발모제가 있는지 여부 (1이면 발모제 포함)

		// 보여줄 병 선택
		for (int j = 1; j <= Currentbottle; j++) {
			int randomBottle = rand() % 4; // 병 무작위로 선택

			// 선택 되지 않은 병이면 선택처리
			if (bottle[randomBottle] == 0) {
				bottle[randomBottle] = 1; //뽑은 병을 표시 (1이면 뽑은 병)
				if (randomBottle == treatment_choice) {
					isincluded = 1;
				}
			}
			// 이미 선택된 병이면 다시 뽑음
			else {
				j--;
			}
		}

		// 사용자에게 문제 표시   ㅅㅂ왜 안나와!!!!
		for (int k = 1; k <= 4; k++) {
			if(bottle[k] == 1) {
				printf("%d", k); // 보여줄 병 선택
			}
		}
		printf("물약을 머리에 바릅니다\n\n");

		if (isincluded == 1) {
			printf("###성공 : 머리가 났어요###\n\n"); // 발모제 병을 포함 했다는 소리
		}
		else {
			printf("###실패 : 머리가 그대로예요###\n\n"); // 발모제 병을 포함하지 않았다는 소리
		}
		
		printf("..! 계속하려면 아무 키나 누르시오 !...\n\n");
		getchar();
	}

	int answer = 0; //사용자 입력 값
	printf("발모제는 몇 번 일까요?");
	scanf_s("%d", &answer);

	if (answer == treatment_choice) {
		printf("정답입니다!");
	}
	else {
		printf("오답입니다! 정답은 %d입니다", treatment_choice +1);
	}

}