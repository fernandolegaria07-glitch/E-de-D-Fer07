#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dato{

        char nombre[30];
        int edad;
};

struct nodo{

        struct Dato dato;
        struct nodo *ptrSig, *ptrAnt;
};

struct nodo* crearNodo(struct Dato *ptrDato){
    struct nodo *ptrN;
    ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    ptrN -> dato.edad = ptrDato -> edad;
    strcpy(ptrN -> dato.nombre, ptrDato -> nombre);
    ptrN -> ptrSig = NULL;
    return ptrN;
}

int meterNodo(struct nodo **ptrRef, struct Dato *ptrDato){
struct nodo *ptrN;
ptrN = crearNodo(ptrDato);

    if(*ptrRef == NULL){
        *ptrRef = ptrN;
    }
    else{
        ptrN -> ptrSig = *ptrRef;
        *ptrRef = ptrN;
    }
    return 0;
}


int colaBacia(struct nodo *ptrRef){
    if(ptrRef -> ptrSig == NULL){
        printf("La cola esta vacia");
    }
    return 0;
}




int main(){
    struct nodo *ptrRef, **ptr;
    ptr = &ptrRef;

    return 0;

}