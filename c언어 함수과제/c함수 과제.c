#define _CRT_NONSTDC_NO_DEPRECATE
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define WIDTH 28+14
#define HEIGHT 41

char bef_x = 18;
char bef_y = 15;

typedef struct block {
	int x;
	int y;
	int shape[3][3];
}Block;

int block_shape[7][4][3][3] = {
	//첫번째 모양
	{
		{
			{1, 1, 1},
			{0, 0, 0},
			{0, 0, 0},
		},
		{
			{0, 0, 1},
			{0, 0, 1},
			{0, 0, 1},
		},
		{
			{0, 0, 0},
			{0, 0, 0},
			{1, 1, 1},
		},
		{
			{1, 0, 0},
			{1, 0, 0},
			{1, 0, 0},
		}
	},
	//두번째 모양
	{
		{
			{1, 1, 1},
			{0, 0, 1},
			{0, 0, 0},
		},
		{
			{0, 0, 1},
			{0, 0, 1},
			{0, 1, 1},
		},
		{
			{0, 0, 0},
			{1, 0, 0},
			{1, 1, 1},
		},
		{
			{1, 1, 0},
			{1, 0, 0},
			{1, 0, 0},
		}
	},
	//세번째 모양
	{
		{
			{1, 1, 1},
			{0, 1, 0},
			{0, 0, 0},
		},
		{
			{0, 0, 1},
			{0, 1, 1},
			{0, 0, 1},
		},
		{
			{0, 0, 0},
			{0, 1, 0},
			{1, 1, 1},
		},
		{
			{1, 0, 0},
			{1, 1, 0},
			{1, 0, 0},
		}
	},
	//네번째 모양
	{
		{
			{1, 1, 0},
			{1, 0, 0},
			{0, 0, 0},
		},
		{
			{1, 1, 0},
			{0, 1, 0},
			{0, 0, 0},
		},
		{
			{0, 1, 0},
			{1, 1, 0},
			{0, 0, 0},
		},
		{
			{1, 0, 0},
			{1, 1, 0},
			{0, 0, 0},
		}
	},
	//다섯번째 모양
	{
		{
			{1, 1, 0},
			{0, 0, 0},
			{0, 0, 0},
		},
		{
			{0, 1, 0},
			{0, 1, 0},
			{0, 0, 0},
		},
		{
			{0, 0, 0},
			{1, 1, 0},
			{0, 0, 0},
		},
		{
			{1, 0, 0},
			{1, 0, 0},
			{0, 0, 0},
		}
	},
	//여섯번째 모양
	{
		{
			{1, 1, 0},
			{0, 1, 1},
			{0, 0, 0},
		},
		{
			{0, 0, 1},
			{0, 1, 1},
			{0, 1, 0},
		},
		{
			{0, 0, 0},
			{1, 1, 0},
			{0, 1, 1},
		},
		{
			{0, 1, 0},
			{1, 1, 0},
			{1, 0, 0},
		}
	},
	//일곱번째 모양
	{
		{
			{1, 1, 1},
			{0, 0, 1},
			{0, 0, 1},
		},
		{
			{0, 0, 1},
			{0, 0, 1},
			{1, 1, 1},
		},
		{
			{1, 0, 0},
			{1, 0, 0},
			{1, 1, 1},
		},
		{
			{1, 1, 1},
			{1, 0, 0},
			{1, 0, 0},
		}
	}
};

int menu();
void gameStart();
void Show(int[HEIGHT][WIDTH]);
//void gameBoardClear(int [30][12]);
//void DBG_checkArr2(int[][12], int, int, char*);
void gotoxy(int x, int y);

void DBG_checkArr2(int B[][12], int col, int row, const char* name) {
	printf("================== DEBUG (%s)================\n", name);
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			printf("%d", B[i][j]);
		}
		printf("\n");
	}
}

void removeCursor() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

COORD getXY() {
	COORD Cur;
	CONSOLE_SCREEN_BUFFER_INFO a;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &a);
	Cur.X = a.dwCursorPosition.X;
	Cur.Y = a.dwCursorPosition.Y;
	return Cur;
}

int main() {
	while (TRUE) {
		removeCursor();
		//printf("!!");
		int menu_select = menu();  //종료 : 0  & 실행 : 1
		//printf("m_s = %d *\n", menu_select);
		if (menu_select == 1) {
			gameStart();
		}
		else if (menu_select == 0) {
			return 0;
		}
	}
}

int menu() {
	clock_t cur_time, old_time;
	old_time = clock();
	printf("           ______________________________\n");
	printf("          |                              |\n"); // 공백 포함 가로 41칸. 세로 테두리 포함 28칸.
	printf("          |                              |\n");
	printf("          |         T E T R I S          |\n");
	printf("          |                              |\n");
	printf("          |                         __   |\n");
	printf("          |                        |__|  |\n");
	printf("          |                              |\n");
	printf("          |                _______       |\n");
	printf("          |  _            |_______|      |\n");
	printf("          |_| |                          |\n");
	printf("          |_  |                          |\n");
	printf("          | |_|                          |\n");
	printf("          |                              |\n");
	printf("          |                              |\n");
	printf("          |          1. START            |\n");
	printf("          |                              |\n");
	printf("          |                              |\n");
	printf("          |                              |\n");
	printf("          |          0. EXIT             |\n");
	printf("          |                              |\n");
	printf("          |  _____                       |\n");
	printf("          | |__ __|                      |\n");
	printf("          |   |_|        _         _     |\n");
	printf("          |             | |   _ __|_|_   |\n");
	printf("          |    _ ___    | |__| |__  | |  |\n");
	printf("          |___| |_|_|   | |  |__  |_| |  |\n");
	printf("          |_____|_|_|___|_|_____|_|___|__|\n");

	char input = 0;
	gotoxy(bef_x, bef_y);

	if (kbhit()) {
		input = getch();
		if (input == 72 || input == 49) { //1 위
			gotoxy(18, 15);
			bef_x = 18;
			bef_y = 15;
		}
		else if (input == 80 || input == 48) { //0 아래
			gotoxy(18, 19);
			bef_x = 18;
			bef_y = 19;
		}
		else if (input == 13) {
			if (getXY().X == 18 && getXY().Y == 15) {
				return 1;
			}
			else if (getXY().X == 18 && getXY().Y == 19) {
				return 0;
			}
		}
	}
	printf("*");

	while (1) {

		cur_time = clock();

		if (cur_time - old_time > 33) {

			break;

		}

	}

	gotoxy(0, 0);

	return -1;

}

void gameStart() {
	//gameBoardClear(game_Board);
	system("cls");
	int index = 1;
	Block* block2 = NULL;
	int block_rand;
	int cur_board_y;
	int cur_board_x;

	while (1) {
		
		int example1 = 15; // 블럭의 최댓값 검사를 위한 블럭생성 기본위치 
		int example2 = 15; // 블럭의 최솟값 검사를 위한 블럭생성 기본위치
		int game_Board[HEIGHT][WIDTH] =
		{
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //10
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},//20
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //30
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,  1,1,1,1,1,1,1,1,1,1,1,1,1,1}, //40
			{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,  1,1,1,1,1,1,1,1,1,1,1,1,1,1} //41
		};
		//gameBoardClear(game_Board);
		char game_Input = NULL;

		if (kbhit()) {
			game_Input = getch();
		}

		gotoxy(0, 0);

		if (block2 == NULL) {
			block2 = (Block*)malloc(sizeof(Block));
			block2->x = 15;
			block2->y = 3;
			srand((unsigned int)time(NULL));
			block_rand = rand() % 7;
			//================= 구조체에 적용 =================
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					block2->shape[i][j] = block_shape[block_rand][0][i][j];
				}
			}
		}
		else if (block2 != NULL) {
			
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {				
					


					if (block2->shape[i][j] == 1) {
						cur_board_y = block2->y + i;
						cur_board_x = block2->x + j;

						if (example1 < cur_board_x) { // example1 = shape[i][j]의 x의 최댓값 (가장 오른쪽블럭의 x좌표)
							example1 = cur_board_x;
						}
						if (example2 > cur_board_x) { // example2 = shape[i][j]의 x의 최솟값 (가장 왼쪽블럭의 x좌표)
							example2 = cur_board_x;
						}
						printf("example1 = %d", example1);
						printf("example2 = %d", example2);
						/* if (game_Board[cur_board_y][cur_board_x + 3] != 3 && game_Board[cur_board_y][cur_board_x + 3] != 2
							|| game_Board[cur_board_y][cur_board_x - 3] != 3 && game_Board[cur_board_y][cur_board_x - 3] != 2){
							printf("주변에 벽이 없습니다.");
							if (game_Input == 75)
								block2->x--;
							else if (game_Input == 77)
								block2->x++;
							}
						if (game_Board[cur_board_y][cur_board_y + 3] != 3 && game_Board[cur_board_y][cur_board_y + 3] != 2
							|| game_Board[cur_board_y][cur_board_y - 3] != 3 && game_Board[cur_board_y][cur_board_y - 3] != 2)
							if (game_Input == 72)
								block2->y++; */
						
						
						/* if (game_Board[cur_board_y][cur_board_x - 2] == 3 || game_Board[cur_board_y][cur_board_x - 2] == 2) {
							printf("주변에 벽이 있습니다.");
							if (game_Input == 77) {
								block2->x++;
							}
						} */
						if (game_Board[cur_board_y+2][cur_board_x] != 3 && game_Board[cur_board_y+2][cur_board_x] != 2) {
							if (game_Input == 72) {
								block2->y++;
							}
						}
						
						if (game_Input == 72) {
							block2->y++;
						}
						
					}
				}
			}
			/* if (game_Board[cur_board_y][example1 + 1] == 3 || game_Board[cur_board_y][example1 + 1] == 2) {
				
				if (game_Input == 75) {
					block2->x--;
				}
			}
			else if (game_Board[cur_board_y][example1 + 1] != 3 && game_Board[cur_board_y][example1 + 1] != 2 ) {
				
				if (game_Input == 75) {
					block2->x--;
				}
				if (game_Input == 77) {
					block2->x++;
				}
			} */
			if(example1 > 15){ // 블럭의 가장 오른쪽이 생성된 곳 기준으로 오른쪽이라면 => 오른쪽 벽 검사가 필요한경우 or 블럭이 오른쪽으로 진행중인 경우
				if (game_Board[cur_board_y][example1 + 1] == 3 || game_Board[cur_board_y][example1 + 1] == 2) {
					printf("오른쪽에 벽이 있습니다.");
					if (game_Input == 75) {
						block2->x--;
					}
				}
				else if (game_Board[cur_board_y][example1 + 1] != 3 && game_Board[cur_board_y][example1 + 1] != 2) {
					printf("오른쪽에 벽이 없습니다.");
					if (game_Input == 75) {
						block2->x--;
					}
					if (game_Input == 77) {
						block2->x++;
					}
				}
			}
			else {
				if (game_Board[cur_board_y][example2 - 1] == 3 || game_Board[cur_board_y][example2 - 1] == 2) {
					printf("왼쪽에 벽이 있습니다.");
					if (game_Input == 77) {
						block2->x++;
					}
				}
				if (game_Board[cur_board_y][example2 - 1] != 3 && game_Board[cur_board_y][example2 - 1] != 2) {
					printf("왼쪽에 벽이 없습니다.");
					if (game_Input == 75) {
						block2->x--;
					}
					if (game_Input == 77) {
						block2->x++;
					}
				}
			}
		}
		Sleep(200);
		block2->y++;

		//================= 게임 보드에 적용 =================
		/* for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (block2->shape[i][j] == 1)
					game_Board[block2->y + i][block2->x + j] = 1;
				else if (block2->shape[i][j] == 0 && game_Board[block2->y + i][block2->x + j] == 0)
					game_Board[block2->y + i][block2->x + j] = 0;
			}
		} */
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (block2->shape[i][j] == 1 && game_Board[block2->y + i][block2->x + j] == 0)
					game_Board[block2->y + i][block2->x + j] = 1;
				else if (block2->shape[i][j] == 0 && game_Board[block2->y + i][block2->x + j] == 0)
					game_Board[block2->y + i][block2->x + j] = 0;
			}
		}
		/*
		free(block2);
		block2 = NULL;
	`	*/
		Show(game_Board);
	}

}


void gameBoardClear(int map[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || i == HEIGHT - 1 || j == 0 || j == 27) {
				map[i][j] = 3;
			}
			else {
				map[i][j] = 0;
			}
		}
	}
}

void gotoxy(int x, int y) {
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void Show(int arr[HEIGHT][WIDTH]) {
	Sleep(100);
	removeCursor();
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (arr[i][j] == 0)
				printf(" ");
			else if (arr[i][j] == 1)
				printf("1");
			else if (arr[i][j] == 2)
				printf("2");
			else
				printf("3");
		}
		printf("\n");
	}
	printf("\n");
}

void gameBoard() {



}