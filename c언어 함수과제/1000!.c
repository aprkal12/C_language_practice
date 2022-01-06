#include <stdio.h>
#include <windows.h>
int first[10000] = { 0, };
int pre[10000] = { 0, };
int nex[10000] = { 0, };
int result[10000] = { 0, };
// 예상 문제점 : 출력 결과를 보면 알겠지만, pre배열을 첫번째 강제로
//			     메인에서 저장 해준 후 팩토리얼 재귀를 돌릴땐 누락됌
//               그래서 pre배열은 안나오고, nex배열만 
//               계속 값이 저장되는 것 같음
int digit1=0;
int digit2=0;
int num = 1;

void NumToArray1(int n, int len) { // 배열에 입력한 수 저장
	int i=0;
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
	int i=0;
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
	int i=0, j=0, k=0;
	int as;
	printf("\nnew loof\n");
	if (a <= 1) {
		return 1;
	}

	as = a;

	while (as > 0) { // 자릿수 구하는 것
		digit2++;
		as /= 10;
	} // 자릿수로 활용할땐 digit-1 해야함
	printf("digit2 = %d \n", digit2);
	printf("a = %d \n", a);
	
	NumToArray2(a, digit2);

	// 그냥 배열 저장확인임 의미는 없음 
	for (i = 0; i < digit1; i++) {
		printf("%d ", pre[i]);
	}
	printf("\n");
	for (j = 0; j < digit2; j++) {
		printf("%d ", nex[j]);
	}
	printf("\n");
	// 곱셈 루프
	for (i = 0; i < digit1; i++) {//    1000
		for (j = 0; j < digit2; j++) {// 999
			printf("hello1\n");
			num = pre[i] * nex[j];
			
			//printf("%d\n", num);

			if (num >= 10) {
				printf("hello2\n");
				result[i + j + 1] += num % 10;
				num /= 10;
				printf("num = %d \n", num);
				//result[i+j] += 
			}
			else {
				printf("hello3\n");
				result[i + j] += num;
			}

			if (result[i + j + k] >= 10) {
				for (k = 0; k <= i + j; k++) {
					printf("hello4\n");
					result[i + j + k + 1] += 1;
				}
			}
			printf("hello5\n");
			//printf("%d\n", num);
			
		}
	}
	printf("result = %d %d \n", result[i + j], result[i+j+1]);

	digit1 = 0;
	digit2 = 0;

	return fac(a - 1);
}
int main(void) {
	int i, j, n,ns;
	
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
	printf("%d \n", ns);
	printf("%d \n", digit1);

	NumToArray1(ns, digit1);

	fac(ns - 1);

	// 배열에 거꾸로 저장된 수를 되돌려서 출력

	for (i = digit1-1; i >= 0; i--) {
		printf("%d ", result[i]);
		Sleep(1000);
	}
	/*for (i = digit1 - 1; i >= 0; i--) {
		printf("%d ", first[i]);
	}*/
	//printf("n은 %d 자릿수 입니다.\n", digit1);

	return 0;
}