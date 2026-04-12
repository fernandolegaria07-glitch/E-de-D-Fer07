#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dato{
    char nombre[30];
    int edad;
};

struct nodo {
    struct Dato dato;
    struct nodo *ptrSig;
};

struct nodo* crearNodo(struct Dato *ptrDato){
    struct nodo *ptrN;
    ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    ptrN -> dato.edad = ptrDato -> edad;
    strcpy(ptrN -> dato.nombre, ptrDato -> nombre);
    ptrN -> ptrSig = NULL;
    return ptrN;
}

int meterNodo(struct nodo *ptrRef, struct Dato *ptrDato){
struct nodo *ptrN;
ptrN = crearNodo(ptrDato);

    if(ptrRef -> ptrSig == NULL){
        ptrRef -> ptrSig = ptrN;
    }
    else{
        ptrN -> ptrSig = ptrRef -> ptrSig;
        ptrRef -> ptrSig = ptrN;
    }
    return 0;
}

int recorrer(struct nodo *ptrRef){
    struct nodo *ptrRec;
    ptrRec = ptrRef -> ptrSig;
    while(ptrRec != NULL){
        printf("%s \t %d", ptrRec -> dato.nombre, ptrRec -> dato.edad);
        ptrRec = ptrRec -> ptrSig;
    }
    return 0;
}

int borrardato(){
    
}

int main(){

    struct Dato miDato;
    struct nodo *miptrRef;
    miDato.edad = 1000;
    strcpy(miDato.nombre,"xxx"); 
    miptrRef = crearNodo(&miDato);

    
        printf("\n Ingresar entero, (edad): ");
        scanf("%d", &miDato.edad);
        getchar();
        printf("\n Ingrese nombre: ");
        fgets(miDato.nombre, 30 ,stdin);

        for(struct nodo *ptr = miptrRef; ptr != NULL ; ptr = ptr -> ptrSig){
            printf("[%s:%d anios]->", ptr -> dato.nombre, ptr -> dato.edad);
   
        }
        meterNodo(miptrRef, &miDato);   
        
        printf("\n Recorrer: \n");
        recorrer(miptrRef);
}
