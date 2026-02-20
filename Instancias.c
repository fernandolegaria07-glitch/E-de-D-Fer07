#include <stdio.h>
#define TAM 5

struct Dato {
	int arreglo[TAM];
	int i;
};

struct Dato2 {
	int arreglo[TAM];
	int *ptr;
};

struct Dato3 {
	int arreglo[TAM];
	int i;	
};

struct Dato4 {
	int arreglo[TAM];
	int *ptr;
};

struct Dato5 {
	int arreglo[TAM];
	int *ptr, **ptr2;
};

int main() {

	printf("Primera forma\n");
	struct Dato dato;
	for(dato.i = 0; dato.i < TAM; dato.i += 1) {
		printf("Ingrese un entero\n");
		scanf("%d", &dato.arreglo[dato.i]);
	}


	for(dato.i = 0; dato.i < TAM; dato.i += 1) {
		printf("En la celda %d esta el valor %d en la dir %p\n", dato.i, dato.arreglo[dato.i], &dato.arreglo[dato.i]);
	}

	printf("Segunda forma\n");
	struct Dato2 dato2;

	for(dato2.ptr = dato2.arreglo; dato2.ptr < &dato2.arreglo[TAM]; dato2.ptr += 1 ) {
		printf("Ingrese un entero\n");
		scanf("%d", dato2.ptr);
	}

	
	for(dato2.ptr = dato2.arreglo; dato2.ptr < &dato2.arreglo[TAM]; dato2.ptr += 1 ) {
		printf("En la celda %d esta el valor %d en la dir %p\n", (int) (dato2.ptr - dato2.arreglo), *dato2.ptr, dato2.ptr);
	}



	printf("Tercera forma\n");
	struct Dato dato3, *ptrs;
	ptrs = &dato3;


	for(ptrs -> i = 0; ptrs -> i < TAM; ptrs -> i += 1) {
		printf("Ingrese un entero\n");
		scanf("%d", &ptrs->arreglo[ptrs->i]);
	}


	for(ptrs -> i = 0; ptrs -> i < TAM; ptrs -> i += 1) {
		printf("En la celda %d esta el valor %d en la dir %p\n", ptrs -> i, ptrs->arreglo[ptrs->i], &ptrs->arreglo[ptrs->i]);
	}


	printf("Cuarta forma\n");
	struct Dato4 dato4, *ptrs1, **ptrs2;
	ptrs1 = &dato;
	for(ptrs1 -> ptr = ptrs1 -> arreglo; ptrs1 -> ptr < &ptrs1 -> arreglo[TAM]; ptrs1 -> ptr += 1) {
		printf("Ingrese un entero\n");
		scanf("%d", ptrs1->ptr);
	}


	for(ptrs1 -> ptr = ptrs1 -> arreglo; ptrs1 -> ptr < &ptrs1 -> arreglo[TAM]; ptrs1 -> ptr += 1) {
		printf("En la celda %d esta el valor %d en la dir %p\n", (int) (ptrs1 -> ptr - ptrs1 -> arreglo), *ptrs1->ptr, ptrs1->ptr);
	}

	printf("Quinta forma\n");

	struct Dato5 dato5, *ptrs5;
	ptrs5 = &dato5;

	for(ptrs5 -> ptr = ptrs5 -> arreglo, ptrs5 -> ptr2 = &ptrs5 -> ptr; *ptrs5 -> ptr2 < &ptrs5 -> arreglo[TAM]; *ptrs5 -> ptr2 += 1) {
		printf("Ingrese un entero\n");
		scanf("%d", *ptrs5->ptr2);
	}

	
	for(ptrs5 -> ptr = ptrs5 -> arreglo, ptrs5 -> ptr2 = &ptrs5 -> ptr; *ptrs5 -> ptr2 < &ptrs5 -> arreglo[TAM]; *ptrs5 -> ptr2 += 1) {
		printf("En la celda %d esta el valor %d en la dir %p\n",
				(int) (*ptrs5 -> ptr2 - ptrs5 -> arreglo),
				**ptrs5 -> ptr2,
				*ptrs5 -> ptr2
				);
	}

	printf("Sexta forma\n");

	struct Dato2 dato6, *ptrs61, **ptrs62;
	ptrs61 = &dato6;



	return 0;
}