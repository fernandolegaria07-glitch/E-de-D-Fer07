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

// --- TODAS LAS FUNCIONES RECURSIVAS ---

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

int contarPares(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    int esPar = (raiz->dato % 2 == 0) ? 1 : 0;
    return esPar + contarPares(raiz->izquierdo) + contarPares(raiz->derecho);
}

int sumarPares(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    int valor = (raiz->dato % 2 == 0) ? raiz->dato : 0;
    return valor + sumarPares(raiz->izquierdo) + sumarPares(raiz->derecho);
}

int main() {
    /* Árbol de prueba:
               1 
             /   \
            2     3 
           / \
          4   5 
       Pares: 2 y 4. 
       Conteo pares: 2 | Suma pares: 6
    */
    struct nodo* raiz = crearNodo(1);
    raiz->izquierdo = crearNodo(2);
    raiz->derecho = crearNodo(3);
    raiz->izquierdo->izquierdo = crearNodo(4);
    raiz->izquierdo->derecho = crearNodo(5);

    printf("--- REPORTE FINAL DEL ÁRBOL ---\n");
    printf("1. Nodos totales:      %d\n", contarNodos(raiz));
    printf("2. Suma total:         %d\n", sumarNodos(raiz));
    printf("3. Suma de hojas:      %d\n", sumarHojas(raiz));
    printf("4. Suma de internos:   %d\n", sumarInternos(raiz));
    printf("5. Cantidad de pares:  %d\n", contarPares(raiz));
    printf("6. Suma de pares:      %d\n", sumarPares(raiz));

    return 0;
}