#include <stdio.h>
// 2019.7.26 금요일
// 하노이타워 3,4개 해보기
void hanoi(int num, char from, char by, char to) {
	// printf("hanoi0 %d\n", c);
	if (num == 1) { // 이동할 원반 수가 1개
		printf("hanoi0 재귀 끝 %d\n", num);
		printf("원반1을 %c에서 %c로 이동 \n", from, to);
	}
	else {
		printf("hanoi1 down %d\n", num);
		hanoi(num - 1, from, to, by);
		printf("\n");
		printf("hanoi1 up %d\n", num);

		printf("원반 %d를 %c에서 %c로 이동 \n", num, from, to);

		printf("hanoi2 down %d\n", num);
		printf("\n");
		hanoi(num - 1, by, from, to);
		printf("hanoi2 up %d\n", num);

	}
}
int main(void) {
	// 막대 a의 원반 3개를 막대b를 경유하여 막대 c로 옮기기
	hanoi(4, 'A', 'B', 'C');
	return 0;
}