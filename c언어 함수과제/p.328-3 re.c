#include <stdio.h>
int main(void) {
	int arr[10];
	int i, num, a = 0, b = 9;

	printf("���� 10�� �Է� \n");
	

	for (i = 0; i < 10; i++) {
		printf("�Է� :");
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