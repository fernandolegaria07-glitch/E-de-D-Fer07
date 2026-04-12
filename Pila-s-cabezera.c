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

int recorrer(struct nodo *ptrRef){
    struct nodo *ptrRec;
    ptrRec = ptrRef; 
    while(ptrRec != NULL){
        printf("%s \t %d\n", ptrRec -> dato.nombre, ptrRec -> dato.edad);
        ptrRec = ptrRec -> ptrSig;
    }
    return 0;
}

int borrardato(){
    
}

int main(){

    struct Dato miDato;
    struct nodo *miptrRef = NULL; // Empieza en NULL (Sin nodo fantasma)

    
        printf("\n Ingresar entero, (edad): ");
        scanf("%d", &miDato.edad);
        getchar();
        printf("\n Ingrese nombre: ");
        fgets(miDato.nombre, 30 ,stdin);

        meterNodo(&miptrRef, &miDato);   
        
        printf("\n Recorrer: \n");
        recorrer(miptrRef);
        
        return 0;
}