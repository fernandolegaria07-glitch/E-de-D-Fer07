#include<stdio.h>
#include<stdlib.h>

struct nodo {
    int dato;
    struct nodo *ptrI, *ptrD;
};

struct nodo* crearNodo(int dato) {
    struct nodo* ptrN = (struct nodo*)malloc(sizeof(struct nodo));
    ptrN->dato = dato;
    ptrN->ptrI = NULL;
    ptrN->ptrD = NULL;
    return ptrN;
}


void imprimirMayores(struct nodo* raiz, int k) {
    if (raiz == NULL) return;
    
    
    imprimirMayores(raiz->ptrI, k);
    if (raiz->dato > k) {
        printf("%d ", raiz->dato);
    }
    imprimirMayores(raiz->ptrD, k);
}


int sumarMayores(struct nodo* raiz, int k) {
    if (raiz == NULL) return 0;
    
    int valorActual = (raiz->dato > k) ? raiz->dato : 0;
    return valorActual + sumarMayores(raiz->ptrI, k) + sumarMayores(raiz->ptrD, k);
}


int contarMayores(struct nodo* raiz, int k) {
    if (raiz == NULL) return 0;
    
    int cuenta = (raiz->dato > k) ? 1 : 0;
    return cuenta + contarMayores(raiz->ptrI, k) + contarMayores(raiz->ptrD, k);
}


int buscarMaximo(struct nodo* raiz) {
    if (raiz == NULL) return -1;
    struct nodo* actual = raiz;
    while (actual->ptrD != NULL) actual = actual->ptrD;
    return actual->dato;
}

int buscarMinimo(struct nodo* raiz) {
    if (raiz == NULL) return -1;
    struct nodo* actual = raiz;
    while (actual->ptrI != NULL) actual = actual->ptrI;
    return actual->dato;
}

int main() {
    struct nodo* raiz = crearNodo(10);
    raiz->ptrI = crearNodo(5);
    raiz->ptrD = crearNodo(15);
    raiz->ptrI->ptrI = crearNodo(2);
    raiz->ptrI->ptrD = crearNodo(7);
    raiz->ptrD->ptrI = crearNodo(12);
    raiz->ptrD->ptrD = crearNodo(20);

    int num;
    printf("Introduce el numero limite: ");
    scanf("%d", &num);

    printf("\n--- Resultados para nodos mayores a %d ---\n", num);
    
    printf("Nodos encontrados: ");
    imprimirMayores(raiz, num);
    
    printf("\nSuma de estos nodos: %d", sumarMayores(raiz, num));
    
    printf("\nTotal de nodos mayores a %d: %d\n", num, contarMayores(raiz, num));

    printf("\nMaximo del arbol: %d", buscarMaximo(raiz));
    printf("\nMinimo del arbol: %d\n", buscarMinimo(raiz));

    return 0;
}