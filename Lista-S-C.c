#include<stdio.h>
#include<stdlib.h>


struct nodo{

    int dato;
    struct nodo *ptrSig, *prtrN;
};

struct nodo* crearNodo(int dato){
struct nodo *ptrN = (struct nodo*)malloc(sizeof(struct nodo));
    if(ptrN != NULL){
ptrN -> dato = dato;
ptrN -> ptrSig = NULL;  
    }
    return ptrN;   
}

int listaVacia(struct nodo **ptrRef2){
    if(*ptrRef2 == NULL){
        printf("Liusta vacia");
    }
    return 0;
}

int meterNodo(struct nodo **ptrRef2, int dato){
    struct nodo *ptrN;
    ptrN = crearNodo(dato);


}



int main(){
struct nodo *ptrRef1 = NULL;
struct nodo **ptrRef2 = &ptrRef1;

}

