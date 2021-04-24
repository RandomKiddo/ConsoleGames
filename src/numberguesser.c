#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int generateNumber(void);

int lower, upper;

int main(void) {
	// Guess A Number From Range [Lower Bound, Upper Bound)
	printf("\nEnter A Lower Bound (Inclusive): ");
	scanf("%d", &lower);
	printf("\nEnter An Upper Bound (Non-Inclusive): ");
	scanf("%d", &upper);
	printf("\nGenerating Number...");
	int value = generateNumber();
	int guess;
	int tries = 0;
	do {
		printf("\nGuess A Number: ");
		scanf("%d", &guess);
		++tries;
	} while (guess != value);
	if (tries == 1) {
		printf("\nCongratulations, you guessed it in 1 try! The number was %d!", value);
	} else {
		printf("\nCongratulations, you gessed it in %d tries! The number was %d!", tries, value);
	}
}

int generateNumber(void) {
	srand(time(NULL));
	int value = rand() % (upper - lower) + lower;
	return (int)value;
}