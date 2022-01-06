#include <stdio.h>
int main(void) {
	char arr[4];
	char com[4];
	int a, i,k, j,ball=0,strike=0;
	scanf("%s", arr);
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		scanf("%s", com);
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 3; k++) {
				if (arr[j] == com[k]) {
					if (j == k) {
						strike++;
					}
					else {
						ball++;
					}
					//printf("연산 함\n");
				}
			}
			
		}
		//printf("%dstrike, %dball\n", strike, ball);
		if(strike == 3){
			printf("%dS\n", strike);
			printf("SUCCESS\n");
			break;
		}
		else if (strike == 0 && ball == 0) {
			printf("OUT\n");
		}
		else if (strike == 0 && ball != 0) {
			printf("%dB\n", ball);
		}
		else if (strike != 0 && ball == 0) {
			printf("%dS\n", strike);
		}
		else if(strike != 0 && ball != 0){
			printf("%dS%dB\n", strike, ball);
		}
		if (i == a-1) {
			printf("FAIL");
		}
		strike = 0, ball = 0;
		
		//printf("지나 감\n");
	}
	
	return 0;
}