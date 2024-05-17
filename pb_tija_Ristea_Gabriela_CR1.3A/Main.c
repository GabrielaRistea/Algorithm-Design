#include"Generater.h"
#include "Utils.h"

long length[10000];
long price[10000];

int main()
{
	long dim;
	long result1;
	long result2;
	//create_test();
	load_data(length, price, &dim);
	printf("Lungimea tijei %ld \n", dim);
	printf("Lungimile bucatilor de tija ");
	for (long i = 0; i < dim; i++) {
		printf("%ld ", length[i]);
	}

	printf("\n");

	printf("Pretul bucatilor de tija ");
	for (long i = 0; i < dim; i++) {
		printf("%ld ", price[i]);
	}

	result1 = cutRod_v1(price, dim);

	printf("\nPretul maxim obtinut V1: %ld", cutRod_v1(price, dim));

	printf("\n");

	result2 = cutRod_kp_v2(price, length, dim, dim);

	printf("\nPretul maxim obtinut V2: %ld", cutRod_kp_v2(price, length, dim, dim));

	save_result(result1, result2);
	
	return 0;
}