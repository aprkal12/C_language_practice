#include <stdio.h>
int main(void) {
	int arr[100][100] = { 0, };
	int num = 1,num1,num2,i,j;
	scanf("%d %d", &num1,&num2);
	for (i = 0; i < num2; i++) {
		for (j = 0; j < num1; j++) {
			arr[num1-num1+j][num2-i-1] = num++;
			// 2 3 �϶�
			// [1][2], [0][2] , [1][1] , [0][1], [1][0] , [0][0]
			// �ڵ�� Ȩ�������� ��ü �迭Ȱ�� �ڵ� ����
		}
	}
	for (i = 0; i < num1; i++) {
		for (j = 0; j < num2; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}