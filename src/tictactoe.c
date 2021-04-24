#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DIFFICULTY_EASY 1
#define DIFFICULTY_MEDIUM 2
#define DIFFICULTY_HARD 3

int gameIsWon(void);
int gameIsDrawn(void);
int spotNotAvailable(int number);
int takeEasyTurn(void);
int takeMediumTurn(void);
int takeHardTurn(void);
int userPlayedACorner(void);
int userPlayedAnEdge(void);
int turnBasedOnPlayedCorner(void);
int edgesOpen(void);
int cornersOpen(void);
int userAboutToWin(void);
int blockMove(void);
void updateBoard(int number);

int board[3][3] = { {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1} }; // 0 computer, 1 user
char str[49] = "1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9";
int indices = { 0, 4, 8, 20, 24, 28, 40, 44, 48 };
char userChar, cpuChar;
int lastMove;
int turn; // turn 0 = computer, turn 1 = player

int main(void) {
	char first;
	do {
		printf("%s", "\nWould you like to go first? y/n: ");
		scanf("%c", first);
	} while (first != 'y' && first != 'n');
	(first == 'y') ? (turn = 1) : (turn = 0);
	(first == 'y') ? (userChar = 'X') : (userChar = 'O');
	(userChar == 'X') ? (cpuChar = 'O') : (cpuChar = 'X');
	int difficulty;
	do {
		printf("%s", "\nWhich difficulty? 1: Easy, 2: Medium, 3: Hard: ");
		scanf("%d", &difficulty);
	} while (difficulty < 0 || difficulty > 3);
	printf("\n%s", str);
	while (gameIsWon() == 0 && gameIsDrawn() == 0) {
		if (turn == 0) {
			int number;
			do {
				if (difficulty == DIFFICULTY_EASY) {
					number = takeEasyTurn();
				} else if (difficulty == DIFFICULTY_MEDIUM) {
					number = takeMediumTurn();
				} else {
					number = takeHardTurn();
				}
			} while (spotNotAvailable(number) == 1);
			int index = indices[number - 1];
			str[index] = cpuChar;
			lastMove = number;
			updateBoard(number);
			turn = 1;
		} else {
			int number;
			do {
				printf("\nEnter a number from 1-9: ");
				scanf("%d", &number);
			} while (number < 0 || number > 9 || spotNotAvailable(number) == 1);
			int index = indices[number - 1];
			str[index] = userChar;
			lastMove = number;
			updateBoard(number);
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

int gameIsDrawn(void) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == -1) {
				return 0;
			}
		}
	}
	return 1;
}

int spotNotAvailable(int number) {
	int status = 0; // status 0 available
	switch (number) {
		case 1:
			(board[0][0] == -1) ? (status = 0) : (status = 1);
			break;
		case 2:
			(board[0][1] == -1) ? (status = 0) : (status = 1);
			break;
		case 3:
			(board[0][2] == -1) ? (status = 0) : (status = 1);
			break;
		case 4:
			(board[1][0] == -1) ? (status = 0) : (status = 1);
			break;
		case 5:
			(board[1][1] == -1) ? (status = 0) : (status = 1);
			break;
		case 6:
			(board[1][2] == -1) ? (status = 0) : (status = 1);
			break;
		case 7:
			(board[2][0] == -1) ? (status = 0) : (status = 1);
			break;
		case 8:
			(board[2][1] == -1) ? (status = 0) : (status = 1);
			break;
		case 9:
			(board[2][2] == -1) ? (status = 0) : (status = 1);
			break;
		default:
			// TILT: SHOULD NOT GET HERE
			status = 1;
			break;
	}
	return status;
}

void updateBoard(int number) {
	switch (number) {
		case 1:
			(turn == 0) ? (board[0][0] = 0) : (board[0][0] = 1);
			break;
		case 2:
			(turn == 0) ? (board[0][1] = 0) : (board[0][1] = 1);
			break;
		case 3:
			(turn == 0) ? (board[0][2] = 0) : (board[0][2] = 1);
			break;
		case 4:
			(turn == 0) ? (board[1][0] = 0) : (board[1][0] = 1);
			break;
		case 5:
			(turn == 0) ? (board[1][1] = 0) : (board[1][1] = 1);
			break;
		case 6:
			(turn == 0) ? (board[1][2] = 0) : (board[1][2] = 1);
			break;
		case 7:
			(turn == 0) ? (board[2][0] = 0) : (board[2][0] = 1);
			break;
		case 8:
			(turn == 0) ? (board[2][1] = 0) : (board[2][1] = 1);
			break;
		case 9:
			(turn == 0) ? (board[2][2] = 0) : (board[2][2] = 1);
			break;
		default:
			// TILT: SHOULD NOT GET HERE
			break;
	}
}

// Random Generated Turn; Likely To Be Bad
int takeEasyTurn(void) {
	srand(time(NULL));
	int number = (rand() % 8) + 1;
	return number;
}

// Uses Basic Logic To Formulate A Turn; Randomized Placement -> No Logic On Player Placement Accuracy
int takeMediumTurn(void) {
	if (spotNotAvailable(5) == 0) {
		return 5;
	} else if (userAboutToWin() == 1) {
		return blockMove();
	} else if (userPlayedACorner() == 1) {
		return turnBasedOnPlayedCorner();
	} else if (userPlayedAnEdge() == 1) {

	}
	return 0;
}

int userPlayedACorner(void) {
	if ((lastMove == 1 || lastMove == 3 || lastMove == 7 || lastMove == 9) && turn == 0 /* last turn was player */) {
		return 1;
	}
	return 0;
}

int userPlayedAnEdge(void) {
	if ((lastMove == 2 || lastMove == 4 || lastMove == 6 || lastMove == 8) && turn == 0 /* last turn was player */) {
		return 1;
	}
	return 0;
}

int userAboutToWin(void) {
	// Horizontal Checks
	for (int i = 0; i < 3; ++i) {
		int check = 0;
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 1) { ++check; }
		}
		if (check >= 2) {
			return 1;
		}
	}
	// Vertical Checks
	for (int i = 0; i < 3; ++i) {
		int check = 0;
		for (int j = 0; j < 3; ++j) {
			if (board[j][i] == 1) { ++check; }
		}
		if (check >= 2) {
			return 1;
		}
	}
	// Diagonal Checks
	if ((board[0][0] == 1 && board[1][1] == 1) || (board[1][1] == 1 && board[2][2] == 1) || (board[0][0] == 1 && board[2][2] == 1)) {
		return 1;
	}
	if ((board[0][2] == 1 && board[1][1] == 1) || (board[1][1] == 1 && board[2][0] == 1) || (board[0][2] == 1 && board[2][0] == 1)) {
		return 1;
	}
	return 0;
}

int blockMove(void) {

}

int turnBasedOnPlayedCorner(void) {
	if (lastMove == 1 && edgesOpen() == 1) {

	} else if (lastMove == 1 && edgesOpen() == 0) {

	} else if (lastMove == 3 && edgesOpen() == 1) {

	} else if (lastMove == 3 && edgesOpen() == 0) {

	} else if (lastMove == 7 && edgesOpen() == 1) {

	} else if (lastMove == 7 && edgesOpen() == 0) {

	} else if (lastMove == 9 && edgesOpen() == 1) {

	} else /* lastMove == 9 && edgesOpen() == 0 */ {

	}
	return 0;
}

int edgesOpen(void) {
	if (board[0][0] == -1 || board[0][2] == -1 || board[2][0] == -1 || board[2][2] == -1) {
		return 1;
	}
	return 0;
}

int cornersOpen(void) {
	if (board[0][1] == -1 || board[1][0] == -1 || board[1][2] == -1 || board[2][1] == -1) {
		return 1;
	}
	return 0;
}

// Employs An Engine To Play A Turn
int takeHardTurn(void) {
	return 0;
}