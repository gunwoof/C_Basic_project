#include <stdio.h>
#include <time.h>

int main_conditional(void) {

	// 프로잭트
	// up & down game

	srand(time(NULL));
	int i = rand() % 100 + 1; //1부터 100까지 숫자
	int chance = 5;
	int answer;
	while(chance > 0) {
		printf("%d번 남았습니다\n", chance--);
		printf("숫자를 맞춰보세요(0~100) : ");
		scanf_s("%d", &answer);
		
		if (answer > i) {
			printf("down down\n\n");
		}
		else if(answer < i) {
			printf("up up\n\n");
		}
		else{
			printf("정답입니다\n\n");
			break;
		}
		
		
		if (chance == 0) {
			printf("정답은 %d\n", i);
			printf("기회가 없습니다");
			break;
		}
		
			
	}
	
}