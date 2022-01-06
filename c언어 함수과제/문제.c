#include <stdio.h>
int main(void) {
	int arr[8][8] = { 0, };
	int i=1,j=1,row,col,k;
	for (i = 1; i < 8; i++) {
		arr[4][i] = 1;
	}
	for (i = 0; i < 3; i++) {
		scanf("%d %d", &row, &col);
		arr[row][col] = 2;
	}
	for (i = 1; i < 8; i++) {
		if (arr[4][i] == 2) {
			for (j = 1; j < 8; j++) {
				if (arr[j][i] != 2) {
					arr[j][i] = 1;
				}
			}
		}
	}
	for (i = 1; i < 8; i++) {
		for (j = 1; j < 8; j++) {
			if (arr[i][j] == 2) {
				if (arr[i + 1][j] == 1 || arr[i - 1][j] == 1) {
					for (k = 1; k < 8; k++) {
						if (arr[i][k] != 2) {
							arr[i][k] = 1;
						}
					}
				}
			}
		}
	}


	for (i = 1; i < 8; i++) {
		for (j = 1; j < 8; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}