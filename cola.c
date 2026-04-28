#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
} Nodo;

typedef struct {
    Nodo *ptrRef1;
    Nodo *ptrRef2;
} Cola;


void inicializar(Cola *q) {
    q->ptrRef1 = (Nodo *)malloc(sizeof(Nodo));
    q->ptrRef2 = (Nodo *)malloc(sizeof(Nodo));


    q->ptrRef1->ptrSig = q->ptrRef2;
    q->ptrRef2->ptrAnt = q->ptrRef1;


    q->ptrRef1->ptrAnt = NULL;
    q->ptrRef2->ptrSig = NULL;
}


void encolar(Cola *q, int valor) {
    Nodo *ptrN = (Nodo *)malloc(sizeof(Nodo));
    ptrN->dato = valor;


    ptrN->ptrSig = q->ptrRef2;
    ptrN->ptrAnt = q->ptrRef2->ptrAnt;


    q->ptrRef2->ptrAnt->ptrSig = ptrN;
    q->ptrRef2->ptrAnt = ptrN;
}


int desencolar(Cola *q) {
    if (q->ptrRef1->ptrSig == q->ptrRef2) {
        printf("Cola vacia\n");
        return -1;
    }

    Nodo *ptrA = q->ptrRef1->ptrSig;
    int valor = ptrA->dato;
    
   
    q->ptrRef1->ptrSig = ptrA->ptrSig;
    ptrA->ptrSig->ptrAnt = q->ptrRef1;

    free(ptrA);
    return valor;
}

void imprimir(Cola q) {
    Nodo *ptrA = q.ptrRef1->ptrSig;
    if (ptrA == q.ptrRef2) {
        printf("La cola esta vacia.\n");
        return;
    }

    printf("Cabecera <-> ");
    while (ptrA != q.ptrRef2) {
        printf("[%d] <-> ", ptrA->dato);
        ptrA = ptrA->ptrSig;
    }
    printf("Trailer\n");
}

int main() {
    Cola miCola;
    
    
    inicializar(&miCola);

    encolar(&miCola, 10);
    encolar(&miCola, 20);
    encolar(&miCola, 30);
    imprimir(miCola);

    printf("Desencolado: %d\n", desencolar(&miCola));
    imprimir(miCola);

    return 0;
}