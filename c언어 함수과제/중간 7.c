#include <stdio.h>
int main(void) {
	int i=0, j=0, cnt = 0,ne=1;

	while (ne < 100) {
		
		cnt++;
		while (j <= i) {
			printf("%d ", cnt);
			if (ne == 100) {
				break;
			}
			if (ne % 10 == 0) {
				printf("\n");
			}
			ne++;
			j++;
		}
		i++;
		j = 0;
		
	}
	printf("\n100��° ���� %3d��.\n", cnt);

	return 0;
}