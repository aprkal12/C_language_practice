#include <stdio.h>
int main(void) {
	int arr[10];
	
	int i, j=0,tem=9,num;

	printf("�� 10���� ���� �Է� \n");

	for (i = 0; i < 10; i++) {
		printf("�Է� :");
		scanf_s("%d", &num);

		if (num % 2 == 0) {
			arr[tem--] = num;
		}
		else if (num % 2 != 0) {
			arr[j++] = num;
		}
		
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}