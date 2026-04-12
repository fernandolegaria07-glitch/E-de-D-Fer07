//Hacemos el manejo de un doble apuntador
#include<stdio.h>
#include<stdlib.h>

struct nodo {
    int dato;
    struct nodo *ptrSig;
    struct nodo *ptrA; 
};

struct nodo* crearNodo(int dato) {
    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    if(ptrN == NULL) return NULL;
    ptrN->dato = dato;
    ptrN->ptrSig = NULL;
    ptrN->ptrA = NULL;
    return ptrN;
}

// Cambiado a ** para poder modificar la cabeza de la pila
int meterNodo(struct nodo **ptrRef1, int dato) {
    struct nodo *ptrN = crearNodo(dato);
    if (*ptrRef1 == NULL) {
        *ptrRef1 = ptrN;
    } else {
        ptrN->ptrSig = *ptrRef1;
        (*ptrRef1)->ptrA = ptrN;
        *ptrRef1 = ptrN;
    }
    return 0;
}

int recorrePila(struct nodo *ptrRef1) {
    struct nodo *ptr = ptrRef1;
    struct nodo *ultimo = NULL;

    if (ptr == NULL) {
        printf("\n La pila esta vacia\n");
        return 0;
    }

    printf("\nRecorrido de la pila \n");
    printf("Ida (Tope -> Base):   ");
    while (ptr != NULL) {
        printf("[%d] -> ", ptr->dato);
        ultimo = ptr; 
        ptr = ptr->ptrSig;
    }
    printf("NULL\n");

    printf("Regreso (Base -> Tope): ");
    ptr = ultimo;
    while (ptr != NULL) {
        printf("[%d] -> ", ptr->dato);
        ptr = ptr->ptrA;
    }
    printf("NULL\n");
    return 0;
}


int borrar(struct nodo **ptrRef1) { 
    if (*ptrRef1 == NULL) {
        printf("\nError: No hay elementos para borrar.\n");
        return -1;
    }
    struct nodo *temp = *ptrRef1;
    *ptrRef1 = (*ptrRef1)->ptrSig;
    
    if (*ptrRef1 != NULL) {
        (*ptrRef1)->ptrA = NULL;
    }
    
    printf("\nElemento [%d] eliminado.\n", temp->dato);
    free(temp);
    return 0;
}

int menu(){
    int opc;
    printf("\n1.- Meter dato\n2.- Borrar dato\n3.- Recorrer Pila\n4.- Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    struct nodo *miptrRef1 = NULL;
    int valor;

    for(;;){
        switch(menu()) {
            case 1:
                printf("Ingrese el valor a meter: ");
                scanf("%d", &valor);
                meterNodo(&miptrRef1, valor); // Enviamos la dirección (&)
                break;
            case 2:
                borrar(&miptrRef1); // Enviamos la dirección (&)
                break;
            case 3:
                recorrePila(miptrRef1);
                break;
            case 4:
                printf("Saliendo...\n");
                exit(0);
            default:
                printf("Opcion invalida\n");
        }
    } 
    return 0;
}