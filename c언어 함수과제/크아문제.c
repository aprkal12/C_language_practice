#include <stdio.h>
int main(void) {
	int arr[12][12] = { 0, };
	int playerlive[9] = { 0, };
	int i, j, a, col, row, pla = 0, k;
	int num1, num2 = 1, E, W, S, N;

	// a == �÷��̾� ��, col,row == �÷��̾� ��ǥ
	// pla == �÷��̾� ����, k == ��ǳ�� �Ͷ߸������� ��(�ڵ�����)
	// num1 == ���ٱ� ����, E,W,S,N == ��,��,��,�� �� -1 ��ġ �Ǻ�
	// playerlive == �÷��̾� �����Ǻ�

	//��
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 11; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//��ǳ�� ��Ʈ����
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 11; j++) {
			if (arr[i][j] > 0) {
				num1 = arr[i][j];
				E = 0, W = 0, S = 0, N = 0;
				for (k = 1; k <= num1; k++) {
					/* ��� �����ص���
				   printf("%d��° i = %d, j = %d, k = %d \n", num2++, i, j, k);
				   printf("%d ", arr[9][3]);
				   printf("%d\n\n", arr[9][1]); // */


					arr[i][j] = -2;
					if (arr[i + k][j] == -1) {
						N = 1;
					}
					if (i - k > 0) {
						if (arr[i - k][j] == -1) {
							S = 1;
						}
					}
					if (j - k > 0) {
						if (arr[i][j - k] == -1) {
							W = 1;
						}
					}
					if (arr[i][j + k] == -1) {
						E = 1;
					}

					if (i + k <= 10) {
						if (N != 1) {
							if (arr[i + k][j] == 0) {
								arr[i + k][j] = -2;
							}

						}
					}
					if (i - k > 0) {
						if (S != 1) {
							if (arr[i - k][j] == 0) {
								arr[i - k][j] = -2;
							}

						}
					}

					if (j - k > 0) {
						if (W != 1) {
							if (arr[i][j - k] == 0) {
								arr[i][j - k] = -2;
							}
						}
					}
					if (j + k <= 10) {
						if (E != 1) {
							if (arr[i][j + k] == 0) {
								arr[i][j + k] = -2;
							}
						}
					}

					/* printf("%d��° i = %d, j = %d, k = %d \n", num2++, i, j, k);
					printf("%d ", arr[8][10]);
					printf("%d\n\n", arr[8][9]); */

					/*
					if (arr[i + k][j] != -1) {
						arr[i + k][j] = -2;
					}
					if (i - k > 0) {
						if (arr[i - k][j] != -1) {
							arr[i - k][j] = -2;
						}
					}
					if (j-k > 0) {
						if (arr[i][j - k] != -1) {
							arr[i][j - k] = -2;
						}
					}
					if (arr[i][j + k] != -1) {
						arr[i][j + k] = -2;
					}
					*/
				}
			}
		}
	}
	//�÷��̾� �Է�, �����Ǻ�
	scanf("%d", &a);
	for (i = 0; i < a; i++) {
		scanf("%d %d", &col, &row);
		pla++;
		if (arr[col][row] == -2) {
			playerlive[i] = -1;
			continue;
		}
		arr[col][row] = pla;
		playerlive[i] = 1;
	}

	//���
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 11; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("Character Information\n");
	for (i = 0; i < a; i++) {
		if (playerlive[i] == -1) {
			printf("player %d dead\n", i + 1);
		}
		else if (playerlive[i] == 1) {
			printf("player %d survive\n", i + 1);
		}

	}

	return 0;
}
