//No de de cabecera es un nodo auxiliar que no tiene infirmación, este se ubica antes de que empiece mi ciclo en el main

#include<stdio.h>
#include<stdlib.h>

struct nodo{

int dato;
struct nodo *ptrSig;

}; //Enlace del mismo tipo o definición de la estructura

/*
int meterNodo(struct nodo *ptrRef, int dato){
    struct nodo *ptrN;
    ptrN = crearNodo(dato);

    if(ptrRef -> ptrSig == NULL)
        ptrRef -> ptrSig = ptrN;
    else {
    ptrN -> ptrSig = ptrRef -> ptrSig;
    ptrRef -> ptrSig = ptrN;
    }
    return 0;
}


//crear una función para crear nodo
int crearNodo(){}
*/
 
int main(){
    // ptrRef es el puntero de referencia de donde empezamos a unir todos los nodos
    struct nodo *ptrRef, *ptrN, *ptrRec, *ptrGar; 
    
    ptrN = (struct nodo*) malloc (sizeof(struct nodo));
    ptrN -> dato = -1000;
    ptrN -> ptrSig = NULL;
    ptrRef = ptrN;

    ptrN = (struct nodo*) malloc (sizeof(struct nodo));
    printf("\n Ingrese entero");
    scanf("%d", &ptrN -> dato);
    ptrN -> ptrSig = NULL;

    ptrRef -> ptrSig = ptrN;

    ptrN = (struct nodo*) malloc (sizeof(struct nodo));
    printf("\n Ingrese entero");
    scanf("%d", &ptrN -> dato);
    ptrN -> ptrSig = NULL;

    ptrN -> ptrSig = ptrRef -> ptrSig ;
    ptrRef -> ptrSig = ptrN;

    ptrN = (struct nodo*) malloc (sizeof(struct nodo));
    printf("\n Ingrese entero");
    scanf("%d", &ptrN -> dato);
    ptrN -> ptrSig = NULL;

    ptrN -> ptrSig = ptrRef -> ptrSig;
    ptrRef -> ptrSig = ptrN;

    ptrRec = ptrRef -> ptrSig;
    while(ptrRec != NULL){
        
        printf("%d", ptrRec -> dato);
        ptrRec = ptrRec -> ptrSig;

    }

    ptrGar = ptrRef -> ptrSig;
    ptrRef -> ptrSig = ptrGar -> ptrSig; 
    printf("\n El dato recuperado es %d", ptrGar -> dato);
    free(ptrGar);

    return 0;
}
//Modificarlo a un programam de funciones