#include <stdio.h>
int main(void) {
	int arr1[11][10];
	int i, j;
	for (i = 0; i < 11; i++) {
		for (j = 0; j < 10; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	for (i = 0; i < 10; i++) {
		if (arr1[10][i] == 1) {
			for (j = 0; j < 10; j++) {
				if (arr1[10-j-1][i] > 0) {
					printf("%d crash\n",i+1);
					break;
				}
				else if (arr1[10-j-1][i] < 0) {
					printf("%d fall\n",i+1);
					break;
				}
			}
			if (j == 10) {
				printf("%d safe\n", i + 1);
			}
		}
	}
	return 0;
}