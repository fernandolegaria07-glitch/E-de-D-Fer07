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
    
    imprimirArbol(root -> right, espacio_actual);
    printf("\n");

    for(int i = ESPACIO; i < espacio_actual; i++){
        printf(" ");
    }
    printf("%d\n", root -> data);
    imprimirArbol(root -> left, espacio_actual);
}

void printTree2D(struct Node* root){

    if(root == NULL){
        printf("El árbol esta vacio \n");
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
    // Pon la raíz en medio (20)
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    
    root->right->left = createNode(12);
    root->right->right = createNode(18);

    return root;
}

int main() {

     struct Node* root = construirArbolPrueba();
    int mostrar = 1;

        if(mostrar){
            printf("\n ---Estado actual del arbol--- \n");
            printTree2D(root);
        }

    printf("--- Arbol Original (Recorrido In-Order) ---\n");
    printInOrder(root);
    printf("\n\n");

    int target;
    printf("Ingresa el valor del nodo a partir del cual deseas podar el arbol: ");

    if (scanf("%d", &target) != 1) {
        printf("Error en la entrada de datos.\n");
        return 1;
    }

    if (!nodeExists(root, target)) {

        printf("\n[RESTRICCION] El nodo '%d' no existe en el arbol. No se realizo ninguna poda.\n", target);
    } else {

        root = pruneTree(root, target);
        
        printf("\n--- Arbol Resultante despues de la poda ---\n");
        if (root == NULL) {
            printf("El arbol esta vacio (se podo desde la raiz).\n");
        } else {
            printInOrder(root);
            printf("\n");
        }
    }

    return 0;
}