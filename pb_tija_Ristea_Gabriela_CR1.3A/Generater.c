#include "Generater.h"

void create_test()
{
	FILE* fptr;
	int dim_tija;
	
	fptr = fopen("test10.txt", "w");
	if (fptr == NULL) {
		printf("File cannot be opened");
		exit(1);
	}

	fprintf(fptr, "%s", "Dimensiunea tijei: ");
	dim_tija = 128;
	fprintf(fptr, "%d\n", dim_tija);
	for (int i = 0; i < dim_tija; i++) {
		fprintf(fptr, "%d ", i+1);
	}

	fprintf(fptr, "%s", "\n");

	int* set = (int*)malloc(dim_tija * sizeof(int));
	srand(time(0));
	set[0] = rand()%10 +1;
	fprintf(fptr, "%d ", set[0]);

	for (int i = 1; i < dim_tija; i++) {
		set[i] = set[i - 1] + rand() % 10;
		fprintf(fptr, "%d ", set[i]);
	}
	
	free(set);
}


void load_data(int length[], int price[], int* dim_tija) {
	FILE* fptr;
	fptr = fopen("test10.txt", "r");

	if (fptr == NULL) {
		printf("File cannot be opened");
		exit(-1);
	}

	fscanf(fptr, "Dimensiunea tijei: %d", dim_tija);
	
	for (int i = 0; i < *dim_tija; i++) {
		fscanf(fptr, "%d", &length[i]);
	}

	for (int i = 0; i < *dim_tija; i++) {
		fscanf(fptr, "%d", &price[i]);
	}

	fclose(fptr);
}