#include <stdio.h>
// 2019.7.26 �ݿ���
// �ϳ���Ÿ�� 3,4�� �غ���
void hanoi(int num, char from, char by, char to) {
	// printf("hanoi0 %d\n", c);
	if (num == 1) { // �̵��� ���� ���� 1��
		printf("hanoi0 ��� �� %d\n", num);
		printf("����1�� %c���� %c�� �̵� \n", from, to);
	}
	else {
		printf("hanoi1 down %d\n", num);
		hanoi(num - 1, from, to, by);
		printf("\n");
		printf("hanoi1 up %d\n", num);

		printf("���� %d�� %c���� %c�� �̵� \n", num, from, to);

		printf("hanoi2 down %d\n", num);
		printf("\n");
		hanoi(num - 1, by, from, to);
		printf("hanoi2 up %d\n", num);

	}
}
int main(void) {
	// ���� a�� ���� 3���� ����b�� �����Ͽ� ���� c�� �ű��
	hanoi(4, 'A', 'B', 'C');
	return 0;
}