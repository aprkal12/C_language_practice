#include <stdio.h>
int main(void) {
	int arr[5];
	int i,M,m,sum=0;

	printf("5���� ���� �Է� \n");

	for (i = 0; i < 5; i++) {
		printf("�Է� : ");
		scanf("%d", &arr[i]);
	}
	M = m = arr[0];
	for (i = 0; i < 5; i++) {
		if (arr[i] > M) {
			M = arr[i];
		}
		if (arr[i] < m) {
			m = arr[i];
		}
		sum += arr[i];
	}
	printf("�ִ� : %d, �ּڰ� : %d, �� �� : %d", M, m, sum);
	return 0;
}