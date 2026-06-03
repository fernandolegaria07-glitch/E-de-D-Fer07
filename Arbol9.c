#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ptrI, *ptrD;
};

struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = dato;
    nuevo->ptrI = nuevo->ptrD = NULL;
    return nuevo;
}


void mostrarArbol(struct Nodo* raiz) {
    if (raiz == NULL) return;
    mostrarArbol(raiz->ptrI);
    printf("[%d] ", raiz->dato);
    mostrarArbol(raiz->ptrD);
}


struct Nodo* borrarHojas(struct Nodo* raiz) {
    if (raiz == NULL) return NULL;

    if (raiz->ptrI == NULL && raiz->ptrD == NULL) {
        free(raiz);
        return NULL;
    }

    raiz->ptrI = borrarHojas(raiz->ptrI);
    raiz->ptrD = borrarHojas(raiz->ptrD);
    return raiz;
}


struct Nodo* borrarUnHijo(struct Nodo* raiz) {
    if (raiz == NULL) return NULL;

    raiz->ptrI = borrarUnHijo(raiz->ptrI);
    raiz->ptrD = borrarUnHijo(raiz->ptrD);

    
    if ((raiz->ptrI != NULL && raiz->ptrD == NULL) || (raiz->ptrI == NULL && raiz->ptrD != NULL)) {
        struct Nodo* hijoUnico = (raiz->ptrI != NULL) ? raiz->ptrI : raiz->ptrD;
        free(raiz);
        return hijoUnico;
    }
    return raiz;
}



struct Nodo* borrarNodosConHijos(struct Nodo* raiz) {
    if (raiz == NULL) return NULL;

    // Si es un nodo interno (tiene al menos un hijo)
    if (raiz->ptrI != NULL || raiz->ptrD != NULL) {
        // Primero liberamos recursivamente a los hijos para no perder memoria
        borrarNodosConHijos(raiz->ptrI);
        borrarNodosConHijos(raiz->ptrD);
        free(raiz);
        return NULL;
    }
    return raiz;
}

int main() {
    
    struct Nodo* raiz = crearNodo(10);
    raiz->ptrI = crearNodo(5);
    raiz->ptrD = crearNodo(15);
    raiz->ptrI->ptrI = crearNodo(2);  
    raiz->ptrI->ptrD = crearNodo(7);  
    raiz->ptrD->ptrD = crearNodo(20); 
    raiz->ptrD->ptrD->ptrI = crearNodo(18); 

    printf("--- ARBOL ORIGINAL ---\n");
    mostrarArbol(raiz);
    printf("\n\n");

    printf("1. Borrando hojas...\n");
    raiz = borrarHojas(raiz);
    mostrarArbol(raiz);
    printf("\n\n");

    printf("2. Borrando nodos con un solo hijo...\n");
    raiz = borrarUnHijo(raiz);
    mostrarArbol(raiz);
    printf("\n\n");

    printf("3. Borrando nodos que tengan hijos (internos)...\n");
    raiz = borrarNodosConHijos(raiz);
    
    if (raiz == NULL) {
        printf("Arbol resultante: [VACIO]\n");
    } else {
        mostrarArbol(raiz);
    }

    return 0;
}