#include <stdio.h>
int main(void) {
	int arr[100][100] = { 0, };
	int num1,num2, num = 1,i,j;
	scanf("%d %d", &num1,&num2);
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2  
			; j++) {
			if (i % 2 != 0) {
				arr[num1 - j - 1][num2 - i - 1] = num++;
			}
			else {
				arr[num1-num1+j][num2-i-1] = num++;
			}
		}
	}
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}