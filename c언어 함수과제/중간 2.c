#include <stdio.h>
int main(void) {
	int i = 1, sum = 0;

	while (i <= 100) {
		sum += i * (2 * i + 5);
		i++;
	}
	printf("sum = %d\n", sum);
	return 0;
}