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


int existeDato(struct nodo* raiz, int k) {
    if (raiz == NULL) return 0; 
    if (raiz->dato == k) return 1;
    
    // Si no es el actual, buscamos en los hijos
    if (k < raiz->dato) 
        return existeDato(raiz->ptrI, k);
    else 
        return existeDato(raiz->ptrD, k);
}


void imprimirMenores(struct nodo* raiz, int k) {
    if (raiz == NULL) return;
    imprimirMenores(raiz->ptrI, k);
    if (raiz->dato < k) {
        printf("%d ", raiz->dato);
    }
    imprimirMenores(raiz->ptrD, k);
}


int sumarMenores(struct nodo* raiz, int k) {
    if (raiz == NULL) return 0;
    int valor = (raiz->dato < k) ? raiz->dato : 0;
    return valor + sumarMenores(raiz->ptrI, k) + sumarMenores(raiz->ptrD, k);
}


int contarMenores(struct nodo* raiz, int k) {
    if (raiz == NULL) return 0;
    int cuenta = (raiz->dato < k) ? 1 : 0;
    return cuenta + contarMenores(raiz->ptrI, k) + contarMenores(raiz->ptrD, k);
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
    printf("Introduce el numero a buscar y filtrar: ");
    scanf("%d", &num);


    if (existeDato(raiz, num)) {
        printf("\n[OK] El numero %d SI pertenece al arbol.\n", num);
    } else {
        printf("\n[!] El numero %d NO se encuentra en el arbol.\n", num);
    }

    printf("\n--- Estadisticas para menores a %d ---\n", num);
    printf("Nodos menores encontrados: ");
    imprimirMenores(raiz, num);
    
    printf("\nSuma de menores: %d", sumarMenores(raiz, num));
    printf("\nTotal de nodos menores: %d\n", contarMenores(raiz, num));

    return 0;
}