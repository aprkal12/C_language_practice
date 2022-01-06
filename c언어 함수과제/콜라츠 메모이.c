#include <stdio.h>
//메모이는 아무 의미없고 걍 재귀문제였음 ㅋㅋㅋ
int memo[10000001];
int cont=0;
int collatz(int n) {
	if (n == 1) {
		memo[n] = 1;
		return;
	}
	else if (memo[cont] != 0) {
		printf("%d\n", n);
		return memo[cont++];
	}
	else if (n % 2 != 0) {
		n = 3 * n + 1;
		printf("%d\n", n);
		memo[cont++] = collatz(n);
		
		return memo[cont++];
	}
	else if (n % 2 == 0) {
		n /= 2;
		printf("%d\n", n);
		memo[cont++] = collatz(n);
		
		return memo[cont++];
	}
}
int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", n);
	collatz(n);
	return 0;
}