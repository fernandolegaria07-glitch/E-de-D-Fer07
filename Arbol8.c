#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ptrI;
    struct Nodo *ptrD;
};

struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = dato;
    nuevo->ptrI = NULL;
    nuevo->ptrD = NULL;
    return nuevo;
}

void mostrarHojas(struct Nodo* raiz) {
    if (raiz == NULL) return;


    if (raiz->ptrI == NULL && raiz->ptrD == NULL) {
        printf("[%d] ", raiz->dato);
    }

    mostrarHojas(raiz->ptrI);
    mostrarHojas(raiz->ptrD);
}

// Función para nodos con EXACTAMENTE un hijo
void mostrarUnSoloHijo(struct Nodo* raiz) {
    if (raiz == NULL) return;

    // Verificamos si tiene solo un hijo (izquierdo o derecho)
    if ((raiz->ptrI != NULL && raiz->ptrD == NULL) || 
        (raiz->ptrI == NULL && raiz->ptrD != NULL)) {
        printf("[%d] ", raiz->dato);
    }

    mostrarUnSoloHijo(raiz->ptrI);
    mostrarUnSoloHijo(raiz->ptrD);
}

int main() {
    /* Árbol de prueba:
             10 (Tiene 2 hijos)
           /    \
          5      15 (Tiene 1 hijo: el 12)
         / \    /
        2   7  12 (Hojas)
       
       Resultado esperado: [15]
    */

    struct Nodo* raiz = crearNodo(10);
    raiz->ptrI = crearNodo(5);
    raiz->ptrD = crearNodo(15);
    
    raiz->ptrI->ptrI = crearNodo(2);
    raiz->ptrI->ptrD = crearNodo(7);
    
    raiz->ptrD->ptrI = crearNodo(12); // El 15 solo tiene hijo izquierdo

    printf("Nodos con un solo hijo: ");
    mostrarUnSoloHijo(raiz);
    printf("\n");

    return 0;
}