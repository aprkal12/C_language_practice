#include <stdio.h>

int first[10000] = { 0, };
int pre[10000] = { 0, };
int nex[10000] = { 0, };
int result[10000] = { 0, };

int digit1 = 0;
int digit2 = 0;
int num = 1;
int JudLoof = 0;
int maxdigit = 0;

void NumToArray1(int n, int len) { // 배열에 입력한 수 저장
	int i = 0;
	if (n >= 10) {
		for (i = 0; n > 0; i++) {
			first[i] = n % 10;
			n /= 10;
		}
	}
	else {
		first[i] = n;
	}

	for (i = 0; i < len; i++) {
		pre[i] = first[i]; /*first[len - i - 1];*/
	} // pre에 정방향으로 수 옮김(주석처리 한것)

	for (i = 0; i < len; i++) {
		first[i] = 0;
	} // first 초기화
}

void NumToArray2(int n, int len) { // 배열에 입력한 수 저장
	int i = 0;
	if (n >= 10) {
		for (i = 0; n > 0; i++) {
			first[i] = n % 10;
			n /= 10;
		}
	}
	else {
		first[i] = n;
	}

	for (i = 0; i < len; i++) {
		nex[i] = first[i]; /*first[len - i - 1];*/
	} // pre에 정방향으로 수 옮김(주석처리 한것)

	for (i = 0; i < len; i++) {
		first[i] = 0;
	} // first 초기화
}

int fac(int a) { // 메인 루프
	int i = 0, j = 0, k = 0;
	int as;

	printf("\nnew loof\n");
	if (a <= 1) {
		for (i = 0; i < 3000; i++) {
			result[i] = pre[i];
		}
		return 1;
	}

	as = a;

	while (as > 0) { // 자릿수 구하는 것
		digit2++;
		as /= 10;
	} // 자릿수로 활용할땐 digit-1 해야함
	printf("digit1 = %d\n",digit1);
	printf("digit2 = %d \n", digit2);
	printf("a = %d \n", a);	

	NumToArray2(a, digit2);

	// 그냥 배열 저장확인임 의미는 없음 
	/*printf("pre = ");
	for (i = 0; i < digit1; i++) {
		printf("%d ", pre[i]);
	}
	printf("\n");
	printf("nex = ");
	for (j = 0; j < digit2; j++) {
		printf("%d ", nex[j]);
	}
	printf("\n");
	*/
	// 곱셈 루프
	for (k = 0; k <= 3000; k++) {
		while (pre[k] >= 10) {
			if (pre[k] >= 10) {
				printf("help me!\n");
				pre[k + 1] += pre[k] / 10;
				pre[k] %= 10;
				/*if (k == digit1 - 1) {
					digit1 += 1;
				}*/
			}
		}
	}
	/*printf("pre = ");
	for (i = 0; i < digit1; i++) {
		printf("%d ", pre[i]);
	}
	printf("\n");*/
	if (JudLoof >= 1) { // 첫 루프가 아닐때
		for (i = 0; i < digit1; i++) {//    1000
			for (j = 0; j < digit2; j++) {// 999
				//printf("hello1\n");
				num = pre[i] * nex[j];
				//printf("%d\n", num);
				while (num >= 0) {
					if (num >= 10) {
						//printf("hello2\n");
						result[i + j + 1] += num / 10;
						num %= 10;
						//result[i+j] += 
					}
					else {
						//printf("hello3\n");
						result[i + j] += num;
						break;
					}
				}

				for (k = 0; k <= 3000; k++) {
					if (pre[k] >= 10) {
						printf("hello4\n");
						pre[k + 1] += pre[k] / 10;
						pre[k] %= 10;
					}
					
				}
				//printf("hello5\n");
				//printf("%d\n", num);		
			}
		}
	}
	else { // 첫 루프일 때
		for (i = 0; i < digit1; i++) {//    1000
			for (j = 0; j < digit2; j++) {// 999
				//printf("hello1\n");

				num = pre[i] * nex[j];
				//printf("%d\n", num);
				while (num > 0) {
					if (num >= 10) {
						//printf("hello2\n");
						result[i + j + 1] += num / 10;
						num %= 10;
						//result[i+j] += 
					}
					else {
						//printf("hello3\n");
						result[i + j] += num;
						break;
					}
				}

				for (k = 0; k <= 3000; k++) {
					if (pre[k] >= 10) {
						printf("hello4\n");
						pre[k + 1] += pre[k] / 10;
						pre[k] %= 10;
					}
					
				}
				//printf("hello5\n");
				//printf("%d\n", num);		
			}
		}
	}
	//printf("result = %d %d \n", result[i + j], result[i+j+1]);
	/*for(i=0; i<10; i++){
		printf("%d ",result[i]);
	}*/
	if ((digit1 + digit2) > maxdigit) {
		maxdigit = digit1 + digit2;
	}

	digit1 = 0;
	digit2 = 0;

	printf("\n");
	for (i = 0; i<maxdigit; i++) {
		digit1 += 1;
	}

	JudLoof += 1;

	for (i = 0; i < 3000; i++) {
		pre[i] = result[i];
	}
	for (i = 0; i < 3000; i++) {
		result[i] = 0;
	}
	return fac(a - 1);
}

int main(void) {
	int i, j, n, ns;
	printf("수를 입력 : ");
	scanf("%d", &n);

	ns = n;

	while (n > 0) { // 자릿수 구하는 것
		digit1++;
		n /= 10;
	} // 자릿수로 활용할땐 digit-1 해야함
	// 입력받은 수를 배열에 거꾸로 저장 
	/*if (ns >= 10) {
		for (i = 0; ns > 0; i++) {
			first[i] = ns % 10;
			ns /= 10;
		}
	}*/
	//printf("%d \n", ns);
	//printf("%d \n", digit1);

	NumToArray1(ns, digit1);

	fac(ns - 1);

	// 배열에 거꾸로 저장된 수를 되돌려서 출력
	for (i = 3000 - 1; i >= 0; i--) {
		printf("%d ", result[i]);
		
	}
	/*for (i = digit1 - 1; i >= 0; i--) {
		printf("%d ", first[i]);
	}*/
	//printf("n은 %d 자릿수 입니다.\n", digit1);
	return 0;
}