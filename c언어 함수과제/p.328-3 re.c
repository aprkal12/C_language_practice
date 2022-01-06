#include <stdio.h>
int main(void) {
	int arr[10];
	int i, num, a = 0, b = 9;

	printf("정수 10개 입력 \n");
	

	for (i = 0; i < 10; i++) {
		printf("입력 :");
		scanf("%d", &num);

		if (num % 2 != 0) {
			arr[a++] = num;
		}
		else if (num % 2 == 0) {
			arr[b--] = num;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}