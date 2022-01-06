#include <stdio.h>
int main(void) {
	int arr1[10][10];
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf("%d", arr1[i][j]);
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
	return 0;
}