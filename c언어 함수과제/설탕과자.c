#include <stdio.h>
int main(void) {
	int arr[100][100] = { 0, };
	int h, w, n, l, d, x, y,i,j;
	scanf("%d %d", &h, &w);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d %d", &l, &d, &x, &y);
		if (d == 0) {
			for (j = 0; j < l; j++) {
				arr[x-1][y + j-1] = 1;
			}
		}
		else if (d == 1) {
			for (j = 0; j < l; j++) {
				arr[x + j-1][y-1] = 1;
			}
		}
	}
	printf("\n");
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}