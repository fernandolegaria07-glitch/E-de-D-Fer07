#include <stdio.h>
#include <stdlib.h>

#define TAM 

struct nodo {
    int dato;
    struct nodo *ptrSig;
};


struct nodo* crearNodo(int dato) {
    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    if (ptrN != NULL) {
        ptrN->dato = dato;
        ptrN->ptrSig = NULL;
    }
    return ptrN;
}


int meterNodo(struct nodo **frente, struct nodo **final, int dato) {
    struct nodo *ptrN = crearNodo(dato);
    if (ptrN == NULL) return -1; 

    if (*frente == NULL) { 
       
        *frente = ptrN;
        *final = ptrN;
    } else {
       
        (*final)->ptrSig = ptrN;
        *final = ptrN;
    }
    return 0;
}


int sacarDato(struct nodo **frente, struct nodo **final) {
    if (*frente == NULL) {
        printf("La cola está vacía. No hay nada que borrar.\n");
        return -1;
    }

    struct nodo *temp = *frente;
    int datoEliminado = temp->dato;

    *frente = (*frente)->ptrSig; 

    
    if (*frente == NULL) {
        *final = NULL;
    }

    free(temp);
    printf("Dato [%d] eliminado.\n", datoEliminado);

    return datoEliminado;
}


void recorrerCola(struct nodo *frente) {
    if (frente == NULL) {
        printf("Cola vacía.\n");
        return;
    }

    struct nodo *actual = frente;
    while (actual != NULL) {
        printf("[%d]->", actual->dato);
        actual = actual->ptrSig;
    }
    printf("NULL\n");
}

int menu(){
    int opc;
    printf("1.- Meter datos a la Cola: \n");
    printf("2.- Recorrer Cola: \n");
    printf("3.- Sacar dato: \n");
    printf("4.- Exit: \n");
    scanf("%d", &opc);
    return opc;
}

int main() {
    
    struct nodo *frente = NULL;
    struct nodo *final = NULL;
    
    
    for (int i = 0; i < 10; i++) {
        meterNodo(&frente, &final, i);
    }

    printf("Cola Original: \n");
    recorrerCola(frente);

    char tecla;
    printf("\nPresiona 'b' para borrar un nodo o 's' para salir: ");
    
    while (scanf(" %c", &tecla) == 1 && (tecla == 'b' || tecla == 'B')) {
        sacarDato(&frente, &final);
        
        printf("Estado de la cola:\n");
        recorrerCola(frente);
        
        printf("\nPresiona 'b' para seguir borrando o 's' para salir: ");
    }

    return 0;
}