#include <stdio.h>
void arr1(int* ar, int leng) {
	int i;

	printf("¦�� ��� : ");
	for (i = 0; i < leng; i++) {
		if (ar[i] % 2 == 0) {
			printf("%d ", ar[i]);
		}
	}
}
void arr2(int* ar, int leng) {
	int i;

	printf("Ȧ�� ��� : ");
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

	printf("�� 10���� ���� �Է�\n");

	for (i = 0; i < 10; i++) {
		printf("�Է� : ");
		scanf_s("%d", &ar[i]);
	}

	arr1(ar, leng);
	printf("\n");
	arr2(ar, leng);

	return 0;
}