#include <stdio.h>
#include <windows.h>
#include <process.h>
int a = 0;
unsigned _stdcall threadfunc(void* arg) {
	while (1) {
		printf("%d Hello\n", a++);
		Sleep(1000);
	}
}
int main(void) {
	_beginthreadex(NULL, 0, threadfunc, 0, 0, NULL);
	char c = '0';
	while (1) {
		printf("%d main\n", a++);
		c = getc(stdin);
		
		if (c) {
			break;
		}
		Sleep(1000);
	}
}