#include<stdio.h>

int main() {
	int num1, num2, num3;
	int max;

	printf("Enter number 1: ");
	scanf("%d", &num1);

	printf("Enter number 2: ");
        scanf("%d", &num2);

	printf("Enter number 3: ");
        scanf("%d", &num3);

	if (num1 >= num2 && num1 >= num3)
		max = num1;
	else if (num2 >= num1 && num2 >= num3)
		max = num2;
	else
		max = num3;
	
	printf("The maximum number is: %d\n", max);	

	return 0;
}
