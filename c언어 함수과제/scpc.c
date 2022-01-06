#include <stdio.h>
int Answer;
int main(void) {
	int T, test_case;
	int r, start, end;
	int N, leftx, rightx, height;
	int i,judge;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d %d %d", &r, &start, &end);
		scanf("%d", &N);
		judge = start + r;
		for (i = 0; i < N; i++) {
			scanf("%d %d %d", &leftx, &rightx, &height);
			for (; start < leftx; start++;) {
				judge++;
				Answer++;
				if (judge = leftx) {
					Answer += height*2;
				}
			}
		}
		printf("case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}
	
	return 0;
}