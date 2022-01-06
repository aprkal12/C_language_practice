#include <stdio.h>
int main(void) {
	int hour, min;
	int time;
	scanf("%d %d", &hour, &min);
	// if¹® »ç¿ë X
	if (min - 30 >= 0) {
		min -= 30;
	}
	else if (min - 30 < 0) {
		time = 30 - min;
		min -= min;
		hour -= 1;
		min = 60 - time;
	}
	time = (hour * 60) + min;

	time -= 30;

	time = 24 * 60 + time;

	time = time % (24 * 60);


	hour = time / 60;
	min = time % 60;
	printf("%d %d\n", hour, min);
	return 0;
}