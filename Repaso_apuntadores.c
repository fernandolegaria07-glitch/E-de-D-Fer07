#include <stdio.h>

int main() {
	
	int arreglo[5];
	int *ptr;

	for(ptr = arreglo; ptr < &arreglo[5]; ptr++) {
		printf("\nIngresa un entero");
		scanf("%d", ptr);
	}	

	for(ptr = arreglo; ptr < &arreglo[5]; ptr++)
		printf("\nEn la celda %d esta el valor %d en la direccion %p", (int) (ptr - arreglo), *ptr, ptr);

	return 0;
}