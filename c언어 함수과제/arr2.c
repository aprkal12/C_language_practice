#include <stdio.h>
int main(void) {
	char arr[100];
	int i, num = 0, get=0;
	printf("���ܾ� �Է� :");
	scanf("%s", arr);

	for (i = 0; arr[i] != '\0'; i++) {
		num++;
	}
	for (i = 0; i < num; i++) {
		if (arr[i] > get) {
			get = arr[i];
		}
	}
	printf("%c\n", get);

	return 0;
}