#include <stdio.h>
#include <stdlib.h>

// 1. Definición de la estructura del nodo
struct nodo {
    int dato;
    struct nodo *izquierdo;
    struct nodo *derecho;
};

// 2. Función para inicializar y asignar memoria a un nuevo nodo
struct nodo* crearNodo(int dato) {
    struct nodo* nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

// 3. Recorrido Preorden (Raíz -> Izquierdo -> Derecho)
void preorden(struct nodo* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);      // Visitar la raíz
        preorden(raiz->izquierdo);      // Recorrer subárbol izquierdo
        preorden(raiz->derecho);        // Recorrer subárbol derecho
    }
}

// 4. Recorrido Inorden (Izquierdo -> Raíz -> Derecho)
void inorden(struct nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierdo);       // Recorrer subárbol izquierdo
        printf("%d ", raiz->dato);      // Visitar la raíz
        inorden(raiz->derecho);         // Recorrer subárbol derecho
    }
}

// 5. Recorrido Postorden (Izquierdo -> Derecho -> Raíz)
void postorden(struct nodo* raiz) {
    if (raiz != NULL) {
        postorden(raiz->izquierdo);     // Recorrer subárbol izquierdo
        postorden(raiz->derecho);       // Recorrer subárbol derecho
        printf("%d ", raiz->dato);      // Visitar la raíz
    }
}

// 6. Función para contar el número total de nodos
int contarNodos(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNodos(raiz->izquierdo) + contarNodos(raiz->derecho);
}

// Función para obtener la suma de los valores de todos los nodos
int sumarNodos(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dato + sumarNodos(raiz->izquierdo) + sumarNodos(raiz->derecho);
}

// 7. Función Principal
int main() {
    /* Creación del siguiente árbol de prueba:
               1
             /   \
            2     3
           / \
          4   5
    */
    
    // Asignación de apuntadores para enlazar los nodos
    struct nodo* raiz = crearNodo(1);
    raiz->izquierdo = crearNodo(2);
    raiz->derecho = crearNodo(3);
    
    raiz->izquierdo->izquierdo = crearNodo(4);
    raiz->izquierdo->derecho = crearNodo(5);

    // Llamadas a las funciones de recorrido
    printf("Recorrido en Preorden: \n");
    preorden(raiz);
    
    printf("\n\nRecorrido en Inorden: \n");
    inorden(raiz);
    
    printf("\n\nRecorrido en Postorden: \n");
    postorden(raiz);
    
    // Llamada a la nueva función de conteo
    printf("\n\nNúmero total de nodos en el árbol: %d\n", contarNodos(raiz));

    printf("La suma es: %d\n", sumarNodos(raiz));

    return 0;
}