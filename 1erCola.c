#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int dato;
    struct nodo *ptrA, *ptrR, *ptrSig;
};

struct nodo* crearNodo(int dato){
    struct nodo *ptrN = (struct nodo*) malloc (sizeof(struct nodo));
    if(ptrN != NULL){
    ptrN -> dato = dato;
    ptrN -> ptrSig = NULL;
    }
    return ptrN;
}

//Despues de crear el nodo lo que tenemos que hacer es ingresarlo

int ingresarNodo(){}


//Creamos nuestra función main
int main(){
    struct nodo *ptrRef;

}