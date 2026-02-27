#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 	5

struct Per {
	char nombre[30];
	int edad;
	char sexo;
};

struct Pila {
	struct Per arreglo[TAM];
	struct Per *ptrC;
};

int iniciarPila(struct Pila *ptr) {
	ptr->ptrC = ptr->arreglo;
	return 0;
}

int estaPilaLlena(struct Pila *ptr) {
	return ptr->ptrC == &ptr->arreglo[TAM];
}

int estaPilaVacia(struct Pila *ptr) {
	return ptr->ptrC == ptr->arreglo;
}

int meterDatoPila(struct Pila *ptr, const struct Per dato) {
	struct Per *datoActual = ptr->ptrC;
	strcpy(datoActual->nombre, dato.nombre);
	datoActual->edad = dato.edad;
	datoActual->sexo = dato.sexo;
	ptr->ptrC += 1;
	return 0;
}

struct Per sacarDatoPila(struct Pila *ptr) {
		ptr->ptrC-=1;
		struct Per datoRecuperado = *ptr->ptrC;
		return datoRecuperado;
}

int menu() {
	int opc;
	printf("1. Para iniciar persona\n");
	printf("2. Para meter dato persona a la pila\n");
	printf("3. Para sacar dato persona de la pila\n");
	printf("4. Para salir\n");
	scanf("%d", &opc);
	return opc;
}

int iniciarPersona(struct Per *miDato) {
		printf("\n Datos persona\n Ingrese el nombre de la persona\n ");
		getchar();
		fgets(miDato->nombre, 30, stdin);
		printf("Ingrese la edad de la persona\n");
		scanf("%d", &miDato->edad);
		printf("Ingrese el sexo de la persona\n");
		scanf(" %c", &miDato->sexo);
}

int main() {
	struct Pila pila, *miPtrp;
	struct Per miDato;

	iniciarPila(&pila);
	miPtrp = &pila;

	while(1) {
		int opc = menu();
		switch(opc) {
			case 1:
				iniciarPersona(&miDato);
			break;
			case 2:
				if(estaPilaLlena(miPtrp)) 
					printf("La pila esta llena\n");
				else {
					meterDatoPila(miPtrp, miDato);
					printf("El dato fue ingresado\n");
				}
			break;
			case 3:
				if(estaPilaVacia(miPtrp))
					printf("La pila esta vacia\n");
				else {
					struct Per dato = sacarDatoPila(miPtrp);
					printf("Datos: \n Persona: %s Edad: %d\n Sexo: %c\n", dato.nombre, dato.edad, dato.sexo);
				}			
			break;
			case 4:
				exit(0);
			break;
		}

	}
}