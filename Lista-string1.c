#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dato {
    char nombre[30];
    int clave;
};

struct nodo {
    struct Dato dato;
    struct nodo *ptrSig, *ptrAn;
};

struct nodo* crearNodo(struct Dato *ptrDato) {
    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    if(ptrN != NULL) {
        ptrN->dato = *ptrDato;
        ptrN->ptrSig = NULL;
        ptrN->ptrAn = NULL;
    }
    return ptrN;
}

int estaVacia(struct nodo *ptrRef) {
    return (ptrRef == NULL);
}

void mostrarLista(struct nodo *ptrRef) {
    if(estaVacia(ptrRef)) {
        printf("\n Lista vacia\n");
        return;
    }
    struct nodo *ptrAux = ptrRef;
    printf("\n Contenido \n");
    while(ptrAux != NULL) {
        printf("Clave: %d | Nombre: %s\n", ptrAux->dato.clave, ptrAux->dato.nombre);
        ptrAux = ptrAux->ptrSig;
    }
}

int meterNodo(struct nodo **ptrRef2, struct Dato dato) {
    struct nodo *ptrAux = *ptrRef2;
    
    
    while(ptrAux != NULL) {
        if(ptrAux->dato.clave == dato.clave) {
            printf("\n[Error]: La clave %d ya existe.\n", dato.clave);
            return 0;
        }
        ptrAux = ptrAux->ptrSig;
    }

    struct nodo *ptrN = crearNodo(&dato);
    if(ptrN == NULL) return 0;

    
    if (*ptrRef2 == NULL || (*ptrRef2)->dato.clave > dato.clave) {
        ptrN->ptrSig = *ptrRef2;
        if (*ptrRef2 != NULL) (*ptrRef2)->ptrAn = ptrN;
        *ptrRef2 = ptrN;
    } 
    else {
        
        ptrAux = *ptrRef2;
        while (ptrAux->ptrSig != NULL && ptrAux->ptrSig->dato.clave < dato.clave) {
            ptrAux = ptrAux->ptrSig;
        }
        
        ptrN->ptrSig = ptrAux->ptrSig;
        if (ptrAux->ptrSig != NULL) {
            ptrAux->ptrSig->ptrAn = ptrN;
        }
        ptrAux->ptrSig = ptrN;
        ptrN->ptrAn = ptrAux;
    }
    return 1;
}

void eliminarNodo(struct nodo **ptrRef, int clave) {
    struct nodo *ptrAux = *ptrRef;
    while (ptrAux != NULL && ptrAux->dato.clave != clave) {
        ptrAux = ptrAux->ptrSig;
    }
    if (ptrAux == NULL) {
        printf("Clave no encontrada\n");
        return;
    }
    if (ptrAux->ptrAn != NULL) {
        ptrAux->ptrAn->ptrSig = ptrAux->ptrSig;
    } else {
        *ptrRef = ptrAux->ptrSig;
    }
    if (ptrAux->ptrSig != NULL) {
        ptrAux->ptrSig->ptrAn = ptrAux->ptrAn;
    }
    free(ptrAux);
    printf("Dato eliminado correctamente\n");
}


int menu() {
    int opc;
    printf("\n1. Ingrese Dato\n");
    printf("2. Recorrer Lista\n");
    printf("3. Borrar: \n");
    printf("4. Exit\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    struct nodo *ptrRef1 = NULL;
    struct nodo **ptrRef2 = &ptrRef1;
    struct Dato nueva;
    int opcion;

    for(;;){
        opcion = menu();
        switch(opcion) {
            case 1:
                printf("Ingrese Clave (numero): ");
                scanf("%d", &nueva.clave);
                printf("Ingrese Nombre: ");
                scanf("%s", nueva.nombre);
                
                if(meterNodo(ptrRef2, nueva)) {
                    printf("Dato ingresado correctamente.\n");
                }
                break;
            case 2:
                mostrarLista(ptrRef1);
                break;
            case 3:
                int claveABuscar; 
                printf("Ingrese la clave del dato que desea borrar: ");
                scanf("%d", &claveABuscar); 
                eliminarNodo(ptrRef2, claveABuscar);
            break;
            case 4:
               exit(0);
                break;
        }
    } 

    return 0;
}
