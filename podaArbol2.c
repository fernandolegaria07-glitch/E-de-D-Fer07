#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ESPACIO 5

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void imprimirArbol(struct Node* root, int espacio_actual){
    if(root == NULL){
        return;
    }
    espacio_actual += ESPACIO;
    
    imprimirArbol(root->right, espacio_actual);
    printf("\n");

    for(int i = ESPACIO; i < espacio_actual; i++){
        printf(" ");
    }
    printf("%d\n", root->data);
    imprimirArbol(root->left, espacio_actual);
}

void printTree2D(struct Node* root){
    if(root == NULL){
        printf("El arbol esta vacio \n");
        return;
    }
    printf("\n--------------------------------------------------\n");
    imprimirArbol(root, 0);
    printf("--------------------------------------------------\n");
}

void freeSubtree(struct Node* root) {
    if (root == NULL) {
        return;
    }
    freeSubtree(root->left);
    freeSubtree(root->right);
    
    printf("  -> Liberando memoria del nodo: %d\n", root->data);
    free(root);
}

bool nodeExists(struct Node* root, int target) {
    if (root == NULL) {
        return false;
    }
    if (root->data == target) {
        return true;
    }
    return nodeExists(root->left, target) || nodeExists(root->right, target);
}

struct Node* findNode(struct Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == target) {
        return root;
    }
    struct Node* leftSearch = findNode(root->left, target);
    if (leftSearch != NULL) {
        return leftSearch;
    }
    return findNode(root->right, target);
}

struct Node* pruneTree(struct Node* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == target) {
        printf("\nIniciando proceso de poda y liberacion de memoria...\n");
        freeSubtree(root);
        return NULL;
    }

    root->left = pruneTree(root->left, target);
    root->right = pruneTree(root->right, target);

    return root;
}

void printInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

struct Node* construirArbolPrueba() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    
    root->right->left = createNode(12);
    root->right->right = createNode(18);

    return root;
}

struct Node* construirSegundoArbol() {
    struct Node* root2 = createNode(100);
    root2->left = createNode(90);
    root2->right = createNode(110);
    return root2;
}

int main() {
    struct Node* root = construirArbolPrueba();
    int opcion;
    int target;
    int mostrar = 1;

    do {
        if(mostrar){
            printf("\n ---Estado actual del arbol--- \n");
            printTree2D(root);
        }

        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Ver estado actual del arbol\n");
        printf("2. Podar arbol desde un nodo\n");
        printf("3. Agregar segundo arbol a un nodo hoja\n");
        printf("5.- Mostrar / Ocultar arbol. \n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Entrada invalida. Limpiando buffer...\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (opcion) {

            case 1:
                printTree2D(root);
                printf("\nRecorrido In-Order: ");
                printInOrder(root);
                printf("\n");
                break;

            case 2:
                if (root == NULL) {
                    printf("El arbol ya esta vacio.\n");
                    break;
                }
                printf("Ingresa el valor del nodo a partir del cual deseas podar el arbol: ");
                scanf("%d", &target);

                if (!nodeExists(root, target)) {
                    printf("\n[RESTRICCION] El nodo '%d' no existe en el arbol. No se realizo ninguna poda.\n", target);
                } else {
                    root = pruneTree(root, target);
                    printf("\n--- Arbol Resultante despues de la poda ---\n");
                    printTree2D(root);
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("El arbol esta vacio. No existen nodos hoja para agregar el segundo arbol.\n");
                    break;
                }
                printf("Ingresa el valor del nodo hoja donde deseas agregar el segundo arbol: ");
                scanf("%d", &target);

                struct Node* nodoDestino = findNode(root, target);

                if (nodoDestino == NULL) {
                    printf("\n[RESTRICCION] El nodo '%d' no existe en el arbol.\n", target);
                } else if (nodoDestino->left != NULL || nodoDestino->right != NULL) {
                    printf("\n[RESTRICCION] El nodo '%d' NO es una hoja. Tiene hijos actualmente.\n", target);
                } else {
                    nodoDestino->left = construirSegundoArbol();
                    printf("\n--- Segundo arbol agregado con exito al nodo %d ---\n", target);
                    printTree2D(root);
                }
                break;

            case 4:
                printf("Terminando la ejecucion del programa...\n");
                break;

            case 5:
                mostrar = !mostrar;
                break;

            default:
                printf("Opcion no reconocida. Por favor intenta de nuevo.\n");
        }

    } while (opcion != 4);

    return 0;
}