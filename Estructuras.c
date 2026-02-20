#include <stdio.h>
#include <stdlib.h>
// Definicion de estructura
// Antes del main()

struct persona { 
	char nombre[30];
	int edad;
	float altura;
	char sexo;
};

int main() {

	// Instancia de la estructura (Operador punto)
	// struct persona per1;
	//
	// Puntero de la instancia (Funcion flecha)
	// struct persona *pws;
	
	struct persona arreglo[5];

	for(int i = 0; i < 1; i++) {
		printf("\nIngrese nombre ");
		gets(arreglo[i].nombre);
		printf("\nIngrese la edad ");
		scanf("%d", &arreglo[i].edad);
		printf("\nIngrese su altura");
		scanf("%f", &arreglo[i].altura);
	}

	for(int i = 0; i < 1; i++) {
		printf("\nEn la celda %d esta %s en la dir %p", i, arreglo[i].nombre, &arreglo[i].nombre);
	}

	// Con apuntadores

	struct persona personas[1], *ptrs;

	for(ptrs = arreglo; ptrs < &arreglo[1]; ptrs+=1) {
		printf("\nIngrese el nombre ");
		gets(ptrs->nombre);
		printf("\nIngrese edad ");
		scanf("%d", &ptrs->edad);
	}

	for(ptrs = arreglo; ptrs < &arreglo[1]; ptrs+=1) 
		printf("\nEn la posicion %d esta %s en la dir %p\n", (int) (ptrs - arreglo), (*ptrs->nombre), (ptrs->nombre));

	return 0;
}