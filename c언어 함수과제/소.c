#include <stdio.h>
#define cur 9
int main(void) {
	int arr[10][10];
	int start, i, j;
	int(*cur_ant)[10] = arr;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n");
	i = 1, j = 1;
	cur_ant[1][1] = cur;
	while (1) {
		if (cur_ant[8][8] == 9) {
			break;
		}
		if (cur_ant[i][j + 1] == 1 || cur_ant[i][j + 1] == 2) {
			if (cur_ant[i + 1][j] == 1) {
				cur_ant[i][j] = cur;
				break;
			}
			else if (cur_ant[i + 1][j] == 2) {
				cur_ant[i][j] = cur;
				cur_ant[i + 1][j] = cur;
				break;
			}
			cur_ant[i][j] = cur;
			i += 1;
		}
		else {
			cur_ant[i][j] = cur;
			j+=1;
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}