#include<stdio.h>
#include<stdlib.h>

int main() {
	FILE *file;
	file = fopen("rainbow.txt", "w");

	if (file == NULL) {
		printf("Error opening file!\n");
		exit(1);
	}

	fprintf(file, "Red\n");
	fprintf(file, "Orange\n");
	fprintf(file, "Yellow\n");
	fprintf(file, "Green\n");
	fprintf(file, "Blue\n");
	fprintf(file, "Purple\n");
	fclose(file);

	printf("File created and text written successfully.\n");
	return 0;
}
