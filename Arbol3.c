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

// --- FUNCIONES DE CONTEO Y SUMA ---

int contarNodos(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNodos(raiz->izquierdo) + contarNodos(raiz->derecho);
}

int sumarNodos(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dato + sumarNodos(raiz->izquierdo) + sumarNodos(raiz->derecho);
}

int sumarHojas(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->izquierdo == NULL && raiz->derecho == NULL) return raiz->dato;
    return sumarHojas(raiz->izquierdo) + sumarHojas(raiz->derecho);
}

int sumarInternos(struct nodo* raiz) {
    if (raiz == NULL || (raiz->izquierdo == NULL && raiz->derecho == NULL)) return 0;
    return raiz->dato + sumarInternos(raiz->izquierdo) + sumarInternos(raiz->derecho);
}

int main() {
    /* Árbol de prueba:
               1 (Interno)
             /   \
            2 (Int) 3 (Hoja)
           / \
          4   5 (Hojas)
       Sumatoria Internos (1 + 2) = 3
    */
    struct nodo* raiz = crearNodo(1);
    raiz->izquierdo = crearNodo(2);
    raiz->derecho = crearNodo(3);
    raiz->izquierdo->izquierdo = crearNodo(4);
    raiz->izquierdo->derecho = crearNodo(5);

    printf("--- Reporte del Árbol ---\n");
    printf("Nodos totales: %d\n", contarNodos(raiz));
    printf("Suma total:    %d\n", sumarNodos(raiz));
    printf("Suma de hojas: %d\n", sumarHojas(raiz));
    printf("Suma de internos (no hojas): %d\n", sumarInternos(raiz));

    return 0;
}