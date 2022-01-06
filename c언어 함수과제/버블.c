#include <stdio.h>
int main(void) {
	int arr[100];
	int i, j,tem,cnt=0, num1;
	scanf("%d", &num1);
	for (i = 0; i < num1; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num1-i-1; j++){
			if (arr[j] > arr[j + 1]) {
				tem = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tem;
				
			}
			
		}
		printf("%d %d %d %d %d\n", arr[0], arr[1],arr[2],arr[3],arr[4]);
		cnt++;
	}
	for (i = 0; i < num1; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n%d\n", cnt);
	return 0;
}