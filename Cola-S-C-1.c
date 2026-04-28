#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato {
    char nombre[30];
    int edad;
};

struct nodo {
    struct Dato dato;
    struct nodo *ptrSig, *ptrAnt;
};


struct nodo* crearNodo(struct Dato dato) {
    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    if (ptrN != NULL) {
        ptrN->dato = dato;
        ptrN->ptrSig = NULL;
        ptrN->ptrAnt = NULL;
    }
    return ptrN;
}


void meterNodo(struct nodo **frente, struct nodo **final, struct Dato dato) {
    struct nodo *ptrN = crearNodo(dato);
    if (ptrN == NULL) {
        printf("Error: No hay memoria suficiente.\n");
        return;
    }

    if (*frente == NULL) {
        
        *frente = ptrN;
        *final = ptrN;
    } else {
        
        (*final)->ptrSig = ptrN;
        ptrN->ptrAnt = *final;
        *final = ptrN;
    }
    printf("Dato insertado correctamente.\n");
}


int sacarNodo(struct nodo **frente, struct nodo **final, struct Dato *datoSalida) {
    if (*frente == NULL) return 0;

    struct nodo *temp = *frente;
    *datoSalida = temp->dato;

    *frente = (*frente)->ptrSig;

    if (*frente == NULL) {
        *final = NULL; 
    } else {
        (*frente)->ptrAnt = NULL;
    }

    free(temp);
    return 1;
}

int main() {
    
    struct nodo *frente = NULL;
    struct nodo *final = NULL;
    
    int opcion;
    struct Dato tempDato;

    do {
        printf("\n MENU\n");
        printf("1. Meter (Enqueue)\n");
        printf("2. Sacar (Dequeue)\n");
        printf("3. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                printf("Introduce nombre: ");
                fgets(tempDato.nombre, 30, stdin);
                tempDato.nombre[strcspn(tempDato.nombre, "\n")] = 0; 
                printf("Introduce edad: ");
                scanf("%d", &tempDato.edad);
                meterNodo(&frente, &final, tempDato);
                break;

            case 2:
                if (sacarNodo(&frente, &final, &tempDato)) {
                    printf("Dato extraido -> Nombre: %s, Edad: %d\n", tempDato.nombre, tempDato.edad);
                } else {
                    printf("La cola esta vacia.\n");
                }
                break;
            
            case 3:
                printf("Saliendo del programa...\n");
                break;
            
            default:
                printf("Opcion no valida.\n");
        }
    } while (opcion != 3);

    return 0;
}