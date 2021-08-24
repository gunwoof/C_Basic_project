#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int Randomnumber(int level);
void Printnumber(int level, int num1, int num2);
void Correct_conditional(int num1, int num2, int answer);

int main_function(void) {
	//프로잭트
	//비밀번호 해제(점점 더 어려운 문제 풀기)
	
	srand(time(NULL));
	for (int i = 1; i <= 5; i++) {
		int num1 = Randomnumber(i);
		int num2 = Randomnumber(i);
		Printnumber(i,num1, num2);

		int answer = 0;
		scanf_s("%d", &answer);
		Correct_conditional(num1, num2, answer);	
	}
	printf("\n\n###축하합니다. 잠금이 해제되었습니다###");
}


//랜덤으로 숫자 받기
int Randomnumber(int level) {
	return rand() % (level*5) + 1;
}

//문제 보여주기
void Printnumber(int level, int num1, int num2) {
	printf("\n\n\n#### %d번째 비밀번호 #####\n\n\n", level);
	printf("%d x %d는 무엇입니까?", num1, num2);
}

//정답 판별
void Correct_conditional(int num1, int num2, int answer) {
	if (num1 * num2 == answer) {
		printf("정답입니다");
	}
	else {
		printf("오답입니다");
		exit(0);
	}
}