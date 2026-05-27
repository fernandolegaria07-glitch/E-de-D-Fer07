#include<stdio.h>
#include<stdlib.h>

struct nodo{

    int dato;
    struct nodo *ptrI, *ptrD;
};


struct nodo* crearNodo(int dato){

    struct nodo* ptrN = (struct nodo*)malloc(sizeof(struct nodo));
    ptrN -> dato = dato;
    ptrN -> ptrI = NULL;
    ptrN -> ptrD = NULL;
    return ptrN;
}

void imprimirDescendente(struct nodo* raiz){
    if (raiz != NULL){

        imprimirDescendente(raiz -> ptrD);
        printf("%d", raiz -> dato);
        imprimirDescendente(raiz -> ptrI);
    }

}
int buscarMinimo(struct nodo* raiz) {
    if (raiz == NULL) 
    return -1;
    
    struct nodo* actual = raiz;
    while (actual -> ptrI != NULL) {
        actual = actual -> ptrI;
    }
    return actual->dato;
}


int buscarMaximo(struct nodo* raiz) {
    if (raiz == NULL) 
    return -1;
    
    struct nodo* actual = raiz;
    while (actual -> ptrD != NULL) {
        actual = actual -> ptrD;
    }
    return actual->dato;
}



int main(){

    struct nodo* raiz  = crearNodo(10);
    raiz -> ptrI = crearNodo(5);
    raiz -> ptrD = crearNodo(15);
    raiz -> ptrI -> ptrI = crearNodo(2);
    raiz -> ptrI -> ptrD = crearNodo(7);
    raiz -> ptrD -> ptrI = crearNodo(12);
    raiz -> ptrD -> ptrD = crearNodo(20);

    printf("Claves en forma descendente \n");
    imprimirDescendente(raiz);
    printf("\n");

    printf("El numero maximo es: %d\n", buscarMaximo(raiz));
    printf("\n");

    printf("El numero minimo es: %d\n", buscarMinimo(raiz));
    printf("\n");

    return 0;
}