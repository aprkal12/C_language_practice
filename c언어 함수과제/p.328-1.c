#include <stdio.h>
void arr1(int* ar, int leng) {
	int i;

	printf("짝수 출력 : ");
	for (i = 0; i < leng; i++) {
		if (ar[i] % 2 == 0) {
			printf("%d ", ar[i]);
		}
	}
}
void arr2(int* ar, int leng) {
	int i;

	printf("홀수 출력 : ");
	for (i = 0; i < leng; i++) {
		if (ar[i] % 2 != 0) {
			printf("%d ", ar[i]);
		}
	}
}
int main(void) {
	int ar[10];
	int leng = sizeof(ar) / sizeof(int);
	int i;

	printf("총 10개의 정수 입력\n");

	for (i = 0; i < 10; i++) {
		printf("입력 : ");
		scanf_s("%d", &ar[i]);
	}

	arr1(ar, leng);
	printf("\n");
	arr2(ar, leng);

	return 0;
}