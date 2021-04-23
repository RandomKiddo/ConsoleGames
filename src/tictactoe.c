#include <stdio.h>

int gameIsWon(void);
int spotNotAvailable(int number);

int board[3][3] = { {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1} };
char str[49] = "1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9";
int indices = { 0, 4, 8, 20, 24, 28, 40, 44, 48 };

int main(void) {
	char first;
	char userChar, cpuChar;
	do {
		printf("%s", "\nWould you like to go first? y/n: ");
		scanf("%c", first);
	} while (first != 'y' && first != 'n');
	int turn; // turn 0 = computer, turn 1 = player
	(first == 'y') ? turn = 1 : turn = 0;
	(first == 'y') ? userChar = 'X' : userChar = 'O';
	(userChar == 'X') ? cpuChar = 'O' : cpuChar = 'X';
	printf("\n%s", str);
	while (gameIsWon() == 0) {
		if (turn == 0) {
			//CPU LOGIC
		} else {
			int number;
			do {
				printf("\nEnter a number from 1-9: ");
				scanf("%d", &number);
			} while (number < 0 || number > 9 || spotNotAvailable(number) == 1);
			int index = indices[number - 1];
			str[index] = userChar;
			turn = 0;
		}
		printf("\n%s", str);
	}
}

int gameIsWon(void) {
	//Horizontal Checks
	for (int i = 0; i < 3; ++i) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != -1) {
			return 1;
		}
	}
	//Vertical Checks
	for (int i = 0; i < 3; ++i) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != -1) {
			return 1;
		}
	}
	//Diagonal Checks
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != -1) {
		return 1;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][0] != -1) {
		return 1;
	}
	return 0;
}

int spotNotAvailable(int number) {
	int status = 0; // status 0 available
	switch (number) {
		case 1:
			(board[0][0] == -1) ? status = 0 : status = 1;
			break;
		case 2:
			(board[0][1] == -1) ? status = 0 : status = 1;
			break;
		case 3:
			(board[0][2] == -1) ? status = 0 : status = 1;
			break;
		case 4:
			(board[1][0] == -1) ? status = 0 : status = 1;
			break;
		case 5:
			(board[1][1] == -1) ? status = 0 : status = 1;
			break;
		case 6:
			(board[1][2] == -1) ? status = 0 : status = 1;
			break;
		case 7:
			(board[2][0] == -1) ? status = 0 : status = 1;
			break;
		case 8:
			(board[2][1] == -1) ? status = 0 : status = 1;
			break;
		case 9:
			(board[2][2] == -1) ? status = 0 : status = 1;
			break;
		default:
			// TILT: SHOULD NOT GET HERE
			status = 1;
			break;
	}
	return status;
}