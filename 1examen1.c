#include<stdio.h>
#include<stdlib.h>
#define TAM  10

struct Pila {
    int arreglo[TAM];
    int *ptrI, *ptrD; // Quitamos ptrC porque ya no lo usas
};

void iniciarPila(struct Pila *ptr) {
    ptr->ptrI = &ptr->arreglo[0];          
    ptr->ptrD = &ptr->arreglo[TAM - 1];    
}

int estaPilallena(struct Pila *ptr) {
    return ptr->ptrI > ptr->ptrD;
}

// Funciones para meter datos
void meterDatoizquierda(struct Pila *ptr, int dato) {
    if (!estaPilallena(ptr)) {
        *(ptr->ptrI) = dato;
        ptr->ptrI++;
        printf("Dato %d guardado a la izquierda.\n", dato);
    } else {
        printf("\n Error: Pila llena.");
    }
}

void meterDatoderecha(struct Pila *ptr, int dato) {
    if (!estaPilallena(ptr)) {
        *(ptr->ptrD) = dato;
        ptr->ptrD--;
        printf("Dato %d guardado a la derecha.\n", dato);
    } else {
        printf("\n Error: Pila llena.");
    }
}

// Funciones para sacar datos
int sacarIzquierda(struct Pila *ptr) {
    if (ptr->ptrI > &ptr->arreglo[0]) {
        ptr->ptrI--;             
        return *(ptr->ptrI);     
    }
    return -1;
}

int sacarDerecha(struct Pila *ptr) {
    if (ptr->ptrD < &ptr->arreglo[TAM - 1]) {
        ptr->ptrD++;           
        return *(ptr->ptrD);
    }
    return -1;
}

int menu() {
    int opc;
    printf("\n1.- Insertar Derecha");
    printf("\n2.- Insertar Izquierda");
    printf("\n3.- Sacar Derecha");
    printf("\n4.- Sacar Izquierda");
    printf("\n5.- Salir\nOpcion: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    struct Pila pila;
    struct Pila *miPtr = &pila;
    int dato, valorSacado;

    iniciarPila(miPtr); 

    for(;;) {
        switch(menu()) {
            case 1:
                printf("Dato para derecha: ");
                scanf("%d", &dato);
                meterDatoderecha(miPtr, dato);
                break;
            case 2:
                printf("Dato para izquierda: ");
                scanf("%d", &dato);
                meterDatoizquierda(miPtr, dato);
                break;
            case 3:
                valorSacado = sacarDerecha(miPtr);
                if(valorSacado != -1) printf("Dato obtenido: %d\n", valorSacado);
                else printf("La derecha esta vacia.\n");
                break;
            case 4:
                valorSacado = sacarIzquierda(miPtr);
                if(valorSacado != -1) printf("Dato obtenido: %d\n", valorSacado);
                else printf("La izquierda esta vacia.\n");
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}