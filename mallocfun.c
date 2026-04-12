#include<stdio.h>
#include<stdlib.h>

struct nodo{

    int dato;
    struct nodo *ptrSig;

};

struct nodo* crearNodo(int dato){

    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    if(ptrN != NULL){
    ptrN -> dato = dato;
    ptrN ->ptrSig = NULL;
    }
    return ptrN;
}

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



int recorrer(struct nodo *ptrRef){
struct nodo *ptrRec;
    ptrRec = ptrRef->ptrSig;

    if (ptrRec == NULL) {
        printf("\nPila vacia.");
    } else {
        while (ptrRec != NULL) {
            printf("\n%d", ptrRec->dato);
            ptrRec = ptrRec->ptrSig;
        }
    }
    return 0;
}

int borrar(struct nodo *ptrRef){
    struct nodo *ptrB; 
    if(ptrRef -> ptrSig == NULL){
        printf("No hay nada que borrar.\n");
    }
    else{
        ptrB = ptrRef -> ptrSig;
        ptrRef -> ptrSig = ptrB -> ptrSig;
        free(ptrB);
        printf("Dato eliminado.\n");
    }
    return 0;
}

int menu(){
    int opc;
printf("\n Pila dinamica");
printf("\n 1.- Ingresar datos: ");
printf("\n 2.- Recorrer Dato: ");
printf("\n 3.- Borrar Dato: ");
printf("\n 4.- Exit.\n");
scanf("%d", &opc);
return  opc;

}

int main(){

struct nodo *ptrRef;
int valor;

ptrRef = (struct nodo*) malloc(sizeof(struct nodo));
ptrRef->dato = -1000;
ptrRef->ptrSig = NULL;

    for(;;){
        switch(menu()){
        
        case 1:
        printf("\n Ingrese dato entero: ");
        scanf("%d", &valor);
        meterNodo(ptrRef, valor);
        break;

        case 2:
        recorrer(ptrRef);
        break;

        case 3:
        borrar(ptrRef);
        break;

        case 4:
            exit(0);
        }   
    }
return 0;
}

//int Recorrer nodo, int borrar nodo
//Recorrer nodo 