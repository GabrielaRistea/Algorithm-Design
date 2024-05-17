#include "Utils.h"

long partial_price[10000][10000];
long partial[10000];

long maxim(long a, long b) {
	if (a > b) {
		return a;
	}
	return b;
}

long cutRod_v1(long prices[], long n) {
	
	partial[0] = 0;
	int i, j;
	long max_val;

	for (i = 1; i <= n; i++) {
		max_val = INT_MIN;
		for (j = 0; j < i; j++) {
			max_val = maxim(max_val, prices[j] + partial[i - j - 1]);
		}
		partial[i] = max_val;
	}

	return partial[n];
}

long cutRod_kp_v2(long price[], long length[], long dim_max, long dim) {
	
	if (dim == 0) {
		return 0;
	}

	if (length[dim - 1] <= dim_max) {
		partial_price[dim][dim_max] = maxim(price[dim - 1] + cutRod_kp_v2(price, length, dim_max - length[dim - 1], dim),
			cutRod_kp_v2(price, length, dim_max, dim - 1));
	}
	else {
		partial_price[dim][dim_max] = cutRod_kp_v2(price, length, dim_max, dim - 1);
	}
	return partial_price[dim][dim_max];
}

void save_result(long result1, long result2) {
	FILE* fptr;
	fptr = fopen("result.txt", "a");

	if (fptr == NULL) {
		printf("File cannot be opened");
		exit(-1);
	}
	fprintf(fptr, "%s \n", "Test10");
	fprintf(fptr, "%s", "Rezultat obtinut V1: ");
	fprintf(fptr, "%ld \n", result1);
	fprintf(fptr, "%s", "Rezultat obtinut V2: ");
	fprintf(fptr, "%ld \n\n", result2);
	fclose(fptr);
}