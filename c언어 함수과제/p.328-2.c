#include <stdio.h>
int main(void) {
	int num;
	int i, result, next=0,cur=1,car=0;

	printf("10���� ���� �Է� : ");
	scanf_s("%d", &num);

	next = num;

	while (next > 0) {
		i = next %2;
		next /= 2;
		result = i * cur;
		cur *= 10;
		car += result;
	}
	printf("2���� : %d ", car);
	return 0;
}