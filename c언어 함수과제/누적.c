#include <stdio.h>
int main(void) {
	int arr[100];
	int num, i,sum=1;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < num; i++) {
		if (i >= 1) {
			arr[i] += arr[i - 1];
		}
	}
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}