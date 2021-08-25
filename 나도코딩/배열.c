#include <stdio.h>
#include <time.h>

int main(void) {
	//프로잭트
	//아빠는 대머리 게임

	srand(time(NULL));
	int answer = 0; //사용자 입력 값
	int treatment_choice = 0; //발모제 선택

	int Currentbottle = 0; //이번 장면에서 보여주는 병 개수
	int Previousbottle = 0; //앞 장면에서 보여주는 병 개수
	// ( 장면마다 병 개수를 다르게 하여  정답률 향상 (ex 처음 2, 다음 3) )
	
	// 3번의 발모제 투여 시도
	for (int i = 1; i <= 3; i++) {
		int bottle[4] = { 0,0,0,0 }; //4개의 병
		do {
			Currentbottle = rand() % 2 + 2; // 0~1 -> 2~3
			Currentbottle = Previousbottle; //조건문이 계속 반복될 조건
		} while (Currentbottle == Previousbottle); 
	}

}