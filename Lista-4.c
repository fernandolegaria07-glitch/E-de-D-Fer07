#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dato{
    char Nombre[30];
    int clave;
};

struct nodo{
    struct Dato dato;
    struct nodo *ptrSig, *ptrAn, *ptrAc;

};

struct nodo* mcrearNodo(struct nodo *ptrDato){
    struct nodo *ptrN = (struct nodo*) malloc (sizeof(struct nodo));
    if(ptrN != NULL){
        ptrN -> dato = *ptrDato;
        ptrN -> ptrSig = NULL;
        ptrN -> ptrAn = NULL;
    }
    return ptrN;
}
int meterNodo(struct nodo *ptrRef1){
    struct nodo ptrN = crerNodo(&dato);
    
}

int estaVacia(struct nodo *ptrRef1){
    if(ptrRef1 != NULL)
        return 1
    else{
        printf("La lista esta vacia");
        return 0;
    }
}


int main(){

struct nodo *ptrRef1 = NULL;
struct nodo **ptrRef2 = &ptrRef1;

}