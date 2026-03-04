//Pagina 276 del libro C

//void *malloc(size_t size) ../.. Donde void es el retorno de un apuntador y lo que esta entre parentesis es
//el tamañ en bytes que reserva de forma dinamica

//El espacion para usarse se llama por costumbre nodo (Elementos, item, ...) cuando tiene un enlace
//Estructura autoreferenciada: Estructura que tiene un enlaze del mismo tipo de la definición de la estructura 

#include<stdio.h>
#include<stdlib.h>

struct nodo{

int dato;
struct nodo *ptrSig;

};


int main(){
 
struct nodo *ptrRef, *ptrN, *ptrRec, *ptrGar;
ptrRef = NULL;

ptrN = (struct nodo*)malloc(sizeof(struct nodo));
printf("\n Ingrese dato:");
scanf("%d", &ptrN -> dato);
ptrN -> ptrSig = NULL;
 
ptrRef = ptrN;

ptrN = (struct nodo*)malloc(sizeof(struct nodo));
printf("\n Ingrese dato: ");
scanf("%d", &ptrN -> dato);
ptrN -> ptrSig = NULL;

ptrN -> ptrSig = ptrRef;
ptrRef = ptrN;

ptrN = (struct nodo*)malloc(sizeof(struct nodo));
printf("\n Ingrese dato: ");
scanf("%d", &ptrN -> dato);
ptrN -> ptrSig = NULL;

ptrN -> ptrSig = ptrRef;
ptrRef = ptrN;

ptrN = (struct nodo*)malloc(sizeof(struct nodo));
printf("\n Ingrese dato: ");
scanf("%d", &ptrN -> dato);
ptrN -> ptrSig = NULL;

ptrN -> ptrSig = ptrRef;
ptrRef = ptrN;

ptrRec = ptrRef;
while(ptrRec != NULL){
printf("\nEl dato es: %d", ptrRec -> dato);
ptrRec = ptrRec -> ptrSig;
}

ptrGar = ptrRef;
ptrRef = ptrGar -> ptrSig;
printf("\nBorrando: %d\n", ptrGar -> dato);
free(ptrGar); 

ptrRec = ptrRef;
while(ptrRec != NULL){
printf("\nEl dato borrado es: %d", ptrRec -> dato);
ptrRec = ptrRec -> ptrSig;
}

}

//void free(void *p){} //Apuntador creado por malloc 