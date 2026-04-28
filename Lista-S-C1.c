//Lista, Los nodos de la lista se ingresan de acuerdo a un campo llamado llave (alfabetico, numerico, alfanumerico)
//sacar, se realiza un recorrido hasra hacer match el elemento buscado(clave) com m elemtos de la lista.

#include<stdio.h>
#include<stdlib.h>

struct nodo{

    int dato;
    int exp;
    float coef;
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

struct nodo nuevoNodo(struct nodo **ptrRef2){}


int listaVacia(struct nodo **ptrRef2){
    if(*ptrRef2 == NULL){
        printf("\n La lista esta vacia");
    }
    return 0;
}


struct nodo* meterNodo(struct nodo **ptrRef2, int dato){
    struct nodo *ptrN;
    ptrN = crearNodo(dato);
    
    
    if(*ptrRef2 == NULL){
        *ptrRef2 = ptrN; 
    }else{
        struct nodo *aux = *ptrRef2;
        while(aux -> ptrSig != NULL){
            aux = aux -> ptrSig;
        }
        aux -> ptrSig = ptrN;
    }
    return 0;
}

int recorrer(struct nodo **ptrRef2){
    struct nodo *aux = *ptrRef2;
    
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


struct nodo* sacarDato(struct nodo **ptrRef2, int datoBorrar){
    struct nodo *temp = *ptrRef2;

    if(*ptrRef2 == NULL) {
        printf("La lista esta vacia\n");
    }
    else if((*ptrRef2) -> dato == datoBorrar){
    *ptrRef2 = (*ptrRef2) -> ptrSig; 
        printf("Dato borrado: [%d]\n", temp -> dato);
        free(temp); 
    }
    else {
        struct nodo *ptrAc = *ptrRef2;
        struct nodo *ptrAn = (*ptrRef2) -> ptrSig;

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
    return *ptrRef2;
}

void ordenarLista(struct nodo **ptrRef2) {
    if (*ptrRef2 == NULL) 
        return; 
    
    int intercambiado;
    struct nodo *ptrAc;
    struct nodo *ultimo = NULL;
    
    do {
        intercambiado = 0;
        ptrAc = *ptrRef2;
        
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

    struct nodo *ptrRef1 = NULL;      
    struct nodo **ptrRef2 = &ptrRef1; 

    struct nodo *ptrRef3 = NULL;
    struct nodo **ptrRef4 = &ptrRef3;
    
    int dato;

    for(;;){
        switch(menu()){
            case 1:
                printf("\n Ingrese Dato(entero)\n");
                scanf("%d", &dato);
 
                meterNodo(ptrRef2, dato);
                break;
            case 2:
                printf("\n Ingrese el dato que desea Eliminar\n");
                scanf("%d", &dato);
                sacarDato(ptrRef2, dato);
                break;
            case 3:
                ordenarLista(ptrRef2);
                recorrer(ptrRef2);
                break;
            case 4:
                exit(0);
                break;
        }
    }
    
    return 0;
}