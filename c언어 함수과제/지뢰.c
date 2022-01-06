#include <stdio.h>
int main(void) {
	int arr[9][9] = { 0, };
	int i, j,num1, num2,judge=0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}
	scanf("%d %d", &num1, &num2);
	num1 -= 1,num2 -= 1;
	i = 0;
	if (arr[num1][num2] == 0) {
		if (num2 == 0) { // 맨 왼쪽 세로줄 판별
			if (num1 == 0) {
				if (arr[num1][num2 + 1] == 1) {
						judge++;
				}
				if (arr[num1 + 1][num2] == 1) {
						judge++;
				}
				if (arr[num1 + 1][num2 + 1] == 1) {
						judge++;
				}
				i++;
			}
			else if (num1 > 0 && num1 < 8) {
				if (arr[num1 - 1][num2] == 1) {
					judge++;
				}
				if (arr[num1 - 1][num2 + 1] == 1) {
					judge++;
				}
				if (arr[num1][num2 + 1] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2 + 1] == 1) {
					judge++;
				}
				i++;
			}
		}
		if (num1 == 8) { // 맨 아랫줄 판별
			if (num2 == 0) {
				if (arr[num1 - 1][num2] == 1) {
					judge++;
				}
				if (arr[num1 - 1][num2 + 1] == 1) {
					judge++;
				}
				if (arr[num1][num2 + 1] == 1) {
					judge++;
				}
				i++;
			}
			else if (num2 > 0 && num2 < 8) {
				if (arr[num1 - 1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 - 1][num2] == 1) {
					judge++;
				}
				if (arr[num1 - 1][num2 + 1] == 1) {
					judge++;
				}
				if (arr[num1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1][num2 + 1] == 1) {
					judge++;
				}
				i++;
			}
		}
		if (num2 == 8) { // 맨 오른쪽줄 판별
			if (num1 == 8) {
				if (arr[num1 - 1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 - 1][num2] == 1) {
					judge++;
				}
				if (arr[num1][num2 - 1] == 1) {
					judge++;
				}
				i++;
			}
			else if (num1 > 0 && num1 < 8) {
				if (arr[num1 - 1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 - 1][num2] == 1) {
					judge++;
				}
				if (arr[num1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2] == 1) {
					judge++;
				}
				i++;
			}
		}
		if (num1 == 0) { // 맨 윗줄 판별
			if (num2 == 8) {
				if (arr[num1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2] == 1) {
					judge++;
				}
				i++;
			}
			else if (num2 > 0 && num2 < 8) {
				if (arr[num1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2 - 1] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2] == 1) {
					judge++;
				}
				if (arr[num1 + 1][num2 + 1] == 1) {
					judge++;
				}
				if (arr[num1][num2 + 1] == 1) {
					judge++;
				}
				i++;
			}
		}
		if(i == 0){
			if (arr[num1 - 1][num2 - 1] == 1) {
				judge++;
			}
			if (arr[num1 - 1][num2] == 1) {
				judge++;
			}
			if (arr[num1 - 1][num2 + 1] == 1) {
				judge++;
			}
			if (arr[num1][num2 - 1] == 1) {
				judge++;
			}
			if (arr[num1][num2 + 1] == 1) {
				judge++;
			}
			if (arr[num1 + 1][num2 - 1] == 1) {
				judge++;
			}
			if (arr[num1 + 1][num2] == 1) {
				judge++;
			}
			if (arr[num1 + 1][num2 + 1] == 1) {
				judge++;
			}
		}
	}
	else if (arr[num1][num2] == 1) {
			judge = -1;
	}
	printf("%d", judge);
	return 0;
}