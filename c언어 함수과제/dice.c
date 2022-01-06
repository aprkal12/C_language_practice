#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
	int arr[6] = { 0, };
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 1000; i++) {
		arr[rand() % 6]++;
	}
	for (i = 0; i < 6; i++) {
		printf("%d = %d¹ø\n", i + 1, arr[i]);
	}
	return 0;
}