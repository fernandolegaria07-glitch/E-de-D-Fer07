#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int dato;
    struct nodo *izquierdo;
    struct nodo *derecho;
};

struct nodo* crearNodo(int dato) {
    struct nodo* nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

// Función para sumar el contenido de TODOS los nodos
int sumarNodos(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dato + sumarNodos(raiz->izquierdo) + sumarNodos(raiz->derecho);
}

// NUEVA: Función para sumar solo los nodos HOJA
int sumarHojas(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izquierdo == NULL && raiz->derecho == NULL) {
        return raiz->dato;
    }
    return sumarHojas(raiz->izquierdo) + sumarHojas(raiz->derecho);
}

int main() {
    /* Árbol de prueba:
               1 (Raíz)
             /   \
            2     3 (Hoja)
           / \
          4   5 (Hojas)
    */
    struct nodo* raiz = crearNodo(1);
    raiz->izquierdo = crearNodo(2);
    raiz->derecho = crearNodo(3);
    raiz->izquierdo->izquierdo = crearNodo(4);
    raiz->izquierdo->derecho = crearNodo(5);

    printf("--- Análisis de Sumas ---");
    printf("\nSuma total de todos los nodos (1+2+3+4+5): %d", sumarNodos(raiz));
    
    // Las hojas son 3, 4 y 5. La suma debe ser 12.
    printf("\nSuma de solo los nodos hoja (3+4+5): %d\n", sumarHojas(raiz));

    return 0;
}