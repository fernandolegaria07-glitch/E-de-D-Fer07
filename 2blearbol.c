#include <stdio.h>
#include <stdlib.h>


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

int areIdentical(struct Node* root1, struct Node* root2) {
    // Si ambos están vacíos, son iguales
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    
    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data &&
                areIdentical(root1->left, root2->left) &&
                areIdentical(root1->right, root2->right));
    }
    
    return 0;
}

struct Node* createMirror(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct Node* newNode = createNode(root->data);
    
    newNode->left = createMirror(root->right);
    newNode->right = createMirror(root->left);
    
    return newNode;
}

void printInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
   
    struct Node* arbol1 = createNode(1);
    arbol1->left = createNode(2);
    arbol1->right = createNode(3);
    arbol1->left->left = createNode(4);
    arbol1->left->right = createNode(5);

    struct Node* arbol2 = createNode(1);
    arbol2->left = createNode(2);
    arbol2->right = createNode(3);
    arbol2->left->left = createNode(4);
    arbol2->left->right = createNode(5);

    printf("--- Impresion de los arboles originales (Recorrido In-Order) ---\n");
    printf("Arbol 1: ");
    printInOrder(arbol1);
    printf("\n");

    printf("Arbol 2: ");
    printInOrder(arbol2);
    printf("\n\n");

    printf("--- Verificacion de Igualdad ---\n");
    if (areIdentical(arbol1, arbol2)) {
        printf("Resultado: Los arboles SON IGUALES.\n\n");
    } else {
        printf("Resultado: Los arboles SON DIFERENTES.\n\n");
    }

    
    struct Node* arbolEspejo = createMirror(arbol1);
    
    printf("--- Arbol Espejo (Basado en el Arbol 1) ---\n");
    printf("Arbol Espejo: ");
    printInOrder(arbolEspejo);
    printf("\n");

    return 0;
}