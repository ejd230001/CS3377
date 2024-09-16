#include <stdio.h>
int main() {
	int num1;
	int num2;
	int num3;

	printf("Enter the first integer: ");
	scanf("%d", &num1);

	printf("Enter the second integer: ");
	scanf("%d", &num2);

	printf("Enter the third integer: ");
	scanf("%d", &num3);

	float average = (num1 + num2 + num3) / 3;

	printf("The average is %.2f.\n", average);
}
