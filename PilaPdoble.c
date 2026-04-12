#include<stdio.h>
#include<stdlib.h>

struct nodo{

int dato;
struct nodo *ptrSig;

};

struct nodo* crearNodo(int dato) {
    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    ptrN -> dato  =dato;
    return ptrN;
}

int meterNodo(struct nodo **ptrRef2, int dato){
struct nodo *ptrN;
ptrN = crearNodo(dato);
    if(*ptrRef2 == NULL){
    *ptrRef2 = ptrN;
    }
    else{
        ptrN -> ptrSig = *ptrRef2;
        *ptrRef2 = ptrN;
    }
   return 0;
}


int recorrePila(struct nodo **ptrRef2){
    for(struct nodo *ptr = *ptrRef2; ptr != NULL; ptr = ptr -> ptrSig){
        printf("[%d]->", ptr-> dato);
    }
printf("\n");
return 0;
}

int borrar(struct nodo **ptrRef2) { 
    if (*ptrRef2 == NULL) {
        printf("No hay nada que borrar.\n");
        return -1;
    }
    struct nodo *ptrRef1 = *ptrRef2;
    *ptrRef2 = (*ptrRef2)->ptrSig;
    free(ptrRef1);
    printf("Dato eliminado.\n");
    return 0;
}


int main(){

    struct nodo *miptrRef1, **miptrRef2, *ptrN;
    miptrRef1 = NULL;
    miptrRef2 = &miptrRef1;

    for(int i = 0; i < 10; i++){
        meterNodo(miptrRef2, i);    
    }
    printf("Pila original\n");
    recorrePila(miptrRef2);
    
   
  char tecla;
    printf("\nPresiona 'b' para borrar un nodo o 's' para salir: ");
    
    while(scanf(" %c", &tecla) == 1 && (tecla == 'b' || tecla == 'B')) {
        borrar(miptrRef2);
        
        printf("Estado de la pila:\n");
        recorrePila(miptrRef2);
        
        printf("\nPresiona 'b' para seguir borrando: ");
    }

    return 0;
}