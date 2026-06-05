#include <stdio.h>
#include <stdlib.h>

#define ESPACIO 5

struct Nodo {
    int dato;
    struct Nodo *ptrI, *ptrD;
};

struct Nodo* crearNodo(int dato) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = dato;
    nuevo->ptrI = nuevo->ptrD = NULL;
    return nuevo;
}

// --- FUNCIONES DE IMPRESIÓN VISUAL ---
void imprimir2DRecursivo(struct Nodo *raiz, int espacio_actual) {
    if (raiz == NULL) return;
    espacio_actual += ESPACIO;

    imprimir2DRecursivo(raiz->ptrD, espacio_actual);
    printf("\n");
    for (int i = ESPACIO; i < espacio_actual; i++) {
        printf(" ");
    }
    printf("%d\n", raiz->dato);
    imprimir2DRecursivo(raiz->ptrI, espacio_actual);
}

void imprimir2D(struct Nodo *raiz) {
    if (raiz == NULL) {
        printf("\n[ El arbol esta VACIO ]\n");
        return;
    }
    printf("\n--------------------------------------------------\n");
    imprimir2DRecursivo(raiz, 0);
    printf("--------------------------------------------------\n");
}

// --- FUNCIONES DE BORRADO ---

// 1. Borrar Nodos Hoja
struct Nodo* borrarHojas(struct Nodo* raiz) {
    if (raiz == NULL) return NULL;

    if (raiz->ptrI == NULL && raiz->ptrD == NULL) {
        free(raiz);
        return NULL;
    }

    raiz->ptrI = borrarHojas(raiz->ptrI);
    raiz->ptrD = borrarHojas(raiz->ptrD);
    return raiz;
}

// 2. Borrar Nodos con UN solo hijo
struct Nodo* borrarUnHijo(struct Nodo* raiz) {
    if (raiz == NULL) return NULL;

    raiz->ptrI = borrarUnHijo(raiz->ptrI);
    raiz->ptrD = borrarUnHijo(raiz->ptrD);

    if ((raiz->ptrI != NULL && raiz->ptrD == NULL) || (raiz->ptrI == NULL && raiz->ptrD != NULL)) {
        struct Nodo* hijoUnico = (raiz->ptrI != NULL) ? raiz->ptrI : raiz->ptrD;
        free(raiz);
        return hijoUnico;
    }
    return raiz;
}

// 3. Borrar Nodos Internos (Destrucción de ramas)
struct Nodo* borrarNodosConHijos(struct Nodo* raiz) {
    if (raiz == NULL) return NULL;

    if (raiz->ptrI != NULL || raiz->ptrD != NULL) {
        borrarNodosConHijos(raiz->ptrI);
        borrarNodosConHijos(raiz->ptrD);
        free(raiz);
        return NULL;
    }
    return raiz;
}

// 4. NUEVA: Borrar Nodos con EXACTAMENTE DOS hijos (Adopción)
struct Nodo* borrarDosHijos(struct Nodo* raiz) {
    if (raiz == NULL) return NULL;

    raiz->ptrI = borrarDosHijos(raiz->ptrI);
    raiz->ptrD = borrarDosHijos(raiz->ptrD);

    if (raiz->ptrI != NULL && raiz->ptrD != NULL) {
        // Guardamos las referencias a los dos hijos
        struct Nodo* subIzquierdo = raiz->ptrI;
        struct Nodo* subDerecho = raiz->ptrD;

        // Buscamos el nodo más a la derecha del subárbol izquierdo
        struct Nodo* temp = subIzquierdo;
        while (temp->ptrD != NULL) {
            temp = temp->ptrD;
        }

        // Conectamos todo el subárbol derecho al extremo que encontramos
        temp->ptrD = subDerecho;

        // Liberamos al padre actual
        free(raiz);

        // Retornamos el subárbol izquierdo para que se conecte con el abuelo
        return subIzquierdo;
    }
    return raiz;
}

// --- FUNCIÓN AUXILIAR PARA REINICIAR EL ÁRBOL ---
struct Nodo* construirArbolPrueba() {
    struct Nodo* raiz = crearNodo(20);
    raiz->ptrI = crearNodo(10);
    raiz->ptrD = crearNodo(30);
    
    raiz->ptrI->ptrI = crearNodo(5);   
    raiz->ptrI->ptrD = crearNodo(15);  
    
    raiz->ptrD->ptrD = crearNodo(40);  
    raiz->ptrD->ptrD->ptrI = crearNodo(35); 
    
    return raiz;
}

// --- FUNCIÓN PRINCIPAL ---
int main() {
    struct Nodo* raiz = construirArbolPrueba();
    int opcion = -1;

    printf("=== BIENVENIDO AL PODADOR DE ARBOLES ===\n");

    while (opcion != 0) {
        printf("\nESTADO ACTUAL DEL ARBOL:\n");
        imprimir2D(raiz);

        printf("\n--- MENU DE OPCIONES ---\n");
        printf("1. Borrar TODOS los nodos HOJA (sin hijos)\n");
        printf("2. Borrar TODOS los nodos con EXACTAMENTE UN HIJO (Bypass)\n");
        printf("3. Borrar TODOS los nodos INTERNOS (Destruccion estructural)\n");
        printf("4. Borrar TODOS los nodos con EXACTAMENTE DOS HIJOS (Fusion)\n");
        printf("5. Restaurar el arbol de prueba original\n");
        printf("0. Salir\n");
        printf("Elige una opcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            printf("[!] Entrada invalida. Saliendo...\n");
            break;
        }

        switch (opcion) {
            case 1:
                raiz = borrarHojas(raiz);
                printf("\n[OK] Hojas eliminadas.\n");
                break;
            case 2:
                raiz = borrarUnHijo(raiz);
                printf("\n[OK] Nodos con un solo hijo eliminados.\n");
                break;
            case 3:
                raiz = borrarNodosConHijos(raiz);
                printf("\n[OK] Nodos internos eliminados.\n");
                break;
            case 4:
                raiz = borrarDosHijos(raiz);
                printf("\n[OK] Nodos con dos hijos eliminados y ramas fusionadas.\n");
                break;
            case 5:
                raiz = construirArbolPrueba();
                printf("\n[OK] Arbol restaurado a su estado original.\n");
                break;
            case 0:
                printf("\n[!] Saliendo del programa...\n");
                break;
            default:
                printf("\n[!] Opcion no valida. Intenta de nuevo.\n");
        }
    }

    return 0;
}