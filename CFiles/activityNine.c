#include<stdio.h>

int main() {
	char letter;
	printf("Enter a character: ");
	scanf("%c", &letter);

	if (letter >= 'a' && letter <= 'z')
		printf("The character is lowercase\n");
	else if (letter >= 'A' && letter <= 'Z')
		printf("The character is uppercase\n");
	else
		printf("The character is not a part of the alphabet.\n");


	return 0;
}
