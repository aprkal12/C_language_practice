#include <stdio.h>
int main(void) {
	char arr[100];
	int i,cha=0,result=0;

	printf("문자열 입력 : ");
	scanf("%s", arr);

	for (i = 0; arr[i] != '\0'; i++) {
		cha++;
	}
	for (i = 0; i < cha; i++) {
		if (arr[i] != arr[cha - i-1]) { // 문자열에서 맨 뒷 값은 NULL이기 때문에 
			// 문자열 맨앞과 맨뒤 비교는 0 과 끝-1해야함
			result++;
		}
	}
	if (result == 0) {
		printf("회문입니다. ");
	}
	else {
		printf("ㄴㄴ");
	}

	return 0;
}