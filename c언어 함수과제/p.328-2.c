#include <stdio.h>
int main(void) {
	int num;
	int i, result, next=0,cur=1,car=0;

	printf("10진수 정수 입력 : ");
	scanf_s("%d", &num);

	next = num;

	while (next > 0) {
		i = next %2;
		next /= 2;
		result = i * cur;
		cur *= 10;
		car += result;
	}
	printf("2진수 : %d ", car);
	return 0;
}