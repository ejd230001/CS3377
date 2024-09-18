#include<stdio.h>

int main() {
	float input;
	float area;
	printf("Do you want to calculate the area of a square (0) or a circle (1): ");
	scanf("%f", &input);

	if (input == 0) {
		printf("How long is the side: ");
		scanf("%f", &input);
		area = input * input;
	        printf("The area is %f.\n", area);	
	}

	else if (input == 1) {
		printf("What is the radius: ");
		scanf("%f", &input);
		area = 3.14 * input * input;
		printf("The area is %f.\n", area);
	}

	return 0;
}
