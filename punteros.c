#include <stdio.h>

int main() {
	int a,b;
	int *ptr1;
	int **ptr2;

	ptr1 = &a;
	ptr2 = &ptr1;
	// Se obtiene el valor de a
	b = **ptr2;
	
	int arreglo[5];

	for(ptr1 = arreglo, ptr2 = &ptr1; *ptr2 < &arreglo[5]; *ptr2 += 1) {
		printf("Ingresa entero \n");
		scanf("%d", *ptr2);

	}

	for(ptr1 = arreglo, ptr2 = &ptr1; *ptr2 < &arreglo[5]; *ptr2 += 1)
		printf("En la celda %d esta el valor %d en la dir %p\n", (int) (*ptr2 - arreglo), **ptr2, *ptr2);
	return 0;
}