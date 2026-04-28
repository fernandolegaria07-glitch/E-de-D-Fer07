//Lista, Los nodos de la lista se ingresan de acuerdo a un campo llamado llave (alfabetico, numerico, alfanumerico)
//sacar, se realiza un recorrido hasra hacer match el elemento buscado(clave) com m elemtos de la lista.

#include<stdio.h>
#include<stdlib.h>

struct nodo{
    int dato;
    int clave;
    struct nodo *ptrSig;
};

struct nodo* crearNodo(int dato) {
    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    if(ptrN != NULL){
    ptrN -> dato = dato;
    ptrN -> ptrSig = NULL;
    }
    return ptrN;
}

int listaVacia(struct nodo *ptrRef){
    if(ptrRef == NULL){
    printf("\n La lista esta vacia");
    }
    return 0;
}

struct nodo* meterNodo(struct nodo *ptrRef, int dato){
    struct nodo *ptrN;
    ptrN = crearNodo(dato);
    
    if(ptrRef == NULL){
        return ptrN;
    }else{
        struct nodo *aux = ptrRef;
        while(aux -> ptrSig != NULL){
            aux = aux -> ptrSig;
        }
        aux -> ptrSig = ptrN;
    }
    return ptrRef;
}

int recorrer(struct nodo *ptrRef){

    struct nodo *aux = ptrRef;
    
    if(aux == NULL){
        printf("\nLa lista esta vacia\n");
        return 0;
    }
    printf("Elementos de la lista: ");
    
    while(aux != NULL){
        printf("[%d]->", aux -> dato);

        aux = aux -> ptrSig;
    }
    return 0;
}

struct nodo* sacarDato(struct nodo *ptrRef, int datoBorrar){
    struct nodo *temp = ptrRef;

    if(ptrRef == NULL) {
        printf("La lista esta vacia\n");
    }
    else if(ptrRef -> dato == datoBorrar){
        ptrRef = ptrRef -> ptrSig;
        printf("Dato borrado: [%d]\n", temp -> dato);
        free(temp); 
    }
    else {
        struct nodo *ptrAc = ptrRef;
        struct nodo *ptrAn = ptrRef -> ptrSig;

    
        while(ptrAc != NULL && ptrAc -> dato != datoBorrar){
            ptrAn = ptrAc;           
            ptrAc = ptrAc -> ptrSig;   
        }

        
        if(ptrAc == NULL){
           
            printf("El dato %d no se encontro en la lista\n", datoBorrar);
        } else {
           
            ptrAn -> ptrSig = ptrAc -> ptrSig;
            
            printf("Dato borrado: [%d]\n", ptrAc -> dato);
            free(ptrAc); 
        }
    }
    
    return ptrRef;
}

void ordenarLista(struct nodo *ptrRef) {
    if (ptrRef == NULL) 
    return; 
    
    int intercambiado;
    struct nodo *ptrAc;
    struct nodo *ultimo = NULL;
    
    do {
        intercambiado = 0;
        ptrAc = ptrRef;
        
        while (ptrAc -> ptrSig != ultimo) {
            
            if (ptrAc->dato > ptrAc -> ptrSig->dato) {
                int temp = ptrAc -> dato;
                ptrAc -> dato = ptrAc -> ptrSig->dato;
                ptrAc->ptrSig->dato = temp;
                intercambiado = 1;
            }
            ptrAc = ptrAc -> ptrSig;
        }
        ultimo = ptrAc; 
    } while (intercambiado);
}

int menu(){
    int opc;
    printf("\n1.- Ingrese Dato: ");
    printf("\n2.- Sacar Dato: ");
    printf("\n3.- Recorrer Dato: ");
    printf("\n4.- exit: ");
    scanf("%d", &opc);
    return opc;
}

int main() {

    struct nodo *ptrRef;
    ptrRef = NULL;
    int dato;

    for(;;){
        switch(menu()){
            case 1:
            printf("\n Ingrese Dato(entero)\n");
            scanf("%d", &dato);
            ptrRef = meterNodo(ptrRef, dato);
            break;
            case 2:
            printf("\n Ingrese el dato que desea Eliminar");
            scanf("%d", &dato);
            ptrRef = sacarDato(ptrRef, dato);
            break;
            case 3:
            ordenarLista(ptrRef);
            recorrer(ptrRef);
            break;
            case 4:
            exit(0);
            break;

        }

    }

    return 0;
}