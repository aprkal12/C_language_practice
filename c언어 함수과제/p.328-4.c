#include <stdio.h>
int main(void) {
	char arr[100];
	int i,cha=0,result=0;

	printf("���ڿ� �Է� : ");
	scanf("%s", arr);

	for (i = 0; arr[i] != '\0'; i++) {
		cha++;
	}
	for (i = 0; i < cha; i++) {
		if (arr[i] != arr[cha - i-1]) { // ���ڿ����� �� �� ���� NULL�̱� ������ 
			// ���ڿ� �Ǿհ� �ǵ� �񱳴� 0 �� ��-1�ؾ���
			result++;
		}
	}
	if (result == 0) {
		printf("ȸ���Դϴ�. ");
	}
	else {
		printf("����");
	}

	return 0;
}