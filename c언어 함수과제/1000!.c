#include <stdio.h>
#include <windows.h>
int first[10000] = { 0, };
int pre[10000] = { 0, };
int nex[10000] = { 0, };
int result[10000] = { 0, };
// ���� ������ : ��� ����� ���� �˰�����, pre�迭�� ù��° ������
//			     ���ο��� ���� ���� �� ���丮�� ��͸� ������ �����
//               �׷��� pre�迭�� �ȳ�����, nex�迭�� 
//               ��� ���� ����Ǵ� �� ����
int digit1=0;
int digit2=0;
int num = 1;

void NumToArray1(int n, int len) { // �迭�� �Է��� �� ����
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
	} // pre�� ���������� �� �ű�(�ּ�ó�� �Ѱ�)

	for (i = 0; i < len; i++) {
		first[i] = 0;
	} // first �ʱ�ȭ
}
	
void NumToArray2(int n, int len) { // �迭�� �Է��� �� ����
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
	} // pre�� ���������� �� �ű�(�ּ�ó�� �Ѱ�)

	for (i = 0; i < len; i++) {
		first[i] = 0;
	} // first �ʱ�ȭ

}

int fac(int a) { // ���� ����
	int i=0, j=0, k=0;
	int as;
	printf("\nnew loof\n");
	if (a <= 1) {
		return 1;
	}

	as = a;

	while (as > 0) { // �ڸ��� ���ϴ� ��
		digit2++;
		as /= 10;
	} // �ڸ����� Ȱ���Ҷ� digit-1 �ؾ���
	printf("digit2 = %d \n", digit2);
	printf("a = %d \n", a);
	
	NumToArray2(a, digit2);

	// �׳� �迭 ����Ȯ���� �ǹ̴� ���� 
	for (i = 0; i < digit1; i++) {
		printf("%d ", pre[i]);
	}
	printf("\n");
	for (j = 0; j < digit2; j++) {
		printf("%d ", nex[j]);
	}
	printf("\n");
	// ���� ����
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
	
	printf("���� �Է� : ");
	scanf("%d", &n);

	ns = n;

	while (n > 0) { // �ڸ��� ���ϴ� ��
		digit1++;
		n /= 10;
	} // �ڸ����� Ȱ���Ҷ� digit-1 �ؾ���

	// �Է¹��� ���� �迭�� �Ųٷ� ���� 
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

	// �迭�� �Ųٷ� ����� ���� �ǵ����� ���

	for (i = digit1-1; i >= 0; i--) {
		printf("%d ", result[i]);
		Sleep(1000);
	}
	/*for (i = digit1 - 1; i >= 0; i--) {
		printf("%d ", first[i]);
	}*/
	//printf("n�� %d �ڸ��� �Դϴ�.\n", digit1);

	return 0;
}