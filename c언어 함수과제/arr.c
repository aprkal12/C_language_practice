#include <stdio.h>
int main(void) {
	int arr[5];
	int i,M,m,sum=0;

	printf("5개의 정수 입력 \n");

	for (i = 0; i < 5; i++) {
		printf("입력 : ");
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
	printf("최댓값 : %d, 최솟값 : %d, 총 합 : %d", M, m, sum);
	return 0;
}