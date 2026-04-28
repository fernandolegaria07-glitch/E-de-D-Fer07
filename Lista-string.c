#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dato{
    char nombre[30];
    int clave;
};

struct nodo{
    struct Dato dato;
    struct nodo *ptrSig, *ptrAc, *ptrAn;
};

struct nodo* crearNodo(struct Dato *ptrDato){
    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    if(ptrN != NULL){
        ptrN -> dato = *ptrDato;
        ptrN -> ptrSig = NULL;
        ptrN -> ptrAn = NULL;
        ptrN -> ptrAc = NULL;
    }
    return ptrN;
}

int meterNodo(struct nodo **ptrRef2, struct Dato dato){
    struct nodo *ptrAux = *ptrRef2;
    struct nodo *ptrN;

    while(ptrAux != NULL){
        if(ptrAux->dato.clave == dato.clave){
            printf("Esta clave ya existe\n");
            return 0;
        }
        ptrAux = ptrAux->ptrSig;
    }

    ptrN = crearNodo(&dato);
    if(ptrN == NULL) return 0;

    ptrN->ptrSig = *ptrRef2;
    if(*ptrRef2 != NULL){
        (*ptrRef2)->ptrAn = ptrN;
    }
    *ptrRef2 = ptrN;

    return 1;
}

int estaVaccia(struct nodo *ptrRef1){
    if(ptrRef1 == NULL){
        printf("La lista esta vacia\n");
        return 1;
    }
    return 0;
}

int recorrer(struct nodo **ptrRef2){
    if(*ptrRef2 == NULL){

        printf("No hay datos para recorrer la lista");
    }
    

}

int menu(){
    int opc;
    printf("1.-Ingrese Dato\n");
    printf("2.-Recorrer Lista\n");
    printf("3.-Eliminar Dato\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    return opc;
}

int main(){
    struct nodo *ptrRef1 = NULL;
    struct nodo **ptrRef2 = &ptrRef1;
    
    struct Dato nueva;
    strcpy(nueva.nombre, "Fernando");
    nueva.clave = 101;
    
    meterNodo(ptrRef2, nueva);
    
    return 0;
}