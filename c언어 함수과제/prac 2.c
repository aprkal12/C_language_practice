#include <stdio.h>
int main(void) {
	int i = 0,num,fac =1;

	printf("����� ���� ���� �Է��ϼ��� : ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		fac*= i;
	}
	printf("%d! = %d \n",num, fac);

	return 0;
}