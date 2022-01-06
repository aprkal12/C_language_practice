#include <stdio.h>
int main(void) {
	int i = 0,num,fac =1;

	printf("계승을 구할 수를 입력하세요 : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		fac*= i;
	}
	printf("%d! = %d \n",num, fac);

	return 0;
}