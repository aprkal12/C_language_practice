#include <stdio.h>
int main(void) {
	int arr[100] = { 0, };
	int num,i;
	scanf("%d",&num);
	arr[0] = 1, arr[1] = 3;
	printf("%d %d ", arr[0], arr[1]);
	for (i = 2; i < num-2; i++) {
		arr[i] = arr[i-2] + arr[i-1];
		printf("%d ", num3);
		arr[i - 2] = arr[i - 1];
		arr[i - 1] = arr[i];
	}
	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}