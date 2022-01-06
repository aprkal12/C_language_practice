#include <stdio.h>
int main(void) {
	int arr[10];
	
	int i, j=0,tem=9,num;

	printf("총 10개의 정수 입력 \n");

	for (i = 0; i < 10; i++) {
		printf("입력 :");
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