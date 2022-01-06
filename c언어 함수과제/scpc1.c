#include <stdio.h>
int Answer;
int main(void) {
	int T, test_case;
	int j,num1,num2;
	int cnt = 0,cal;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++){
		scanf("%d %d", &num1, &num2);
		cnt = 0;
		for (j = num1; j <= num2; j++) {
			cal = j;
			while(1) {
				if (cal % 2 == 0) {
					cal /= 2;
					cnt++;
				}
				else if (cal % 2 != 0 && cal > 1) {
					cal++;
					cnt++;
				}
				else {
					break;
				}
			}
			
		}
		Answer = 0;
		Answer += cnt;
		printf("case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}
	
	return 0;
}