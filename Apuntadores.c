#include <stdio.h>

int main() {
	int* x;
	float* y;
	char* c;
	double* d;

	printf("Bytes: %d %d %p %p \n", sizeof(x), sizeof(y), sizeof(c), sizeof(d));
}