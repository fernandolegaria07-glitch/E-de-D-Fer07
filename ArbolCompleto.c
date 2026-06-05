#include<stdio.h>
#include<stdlib.h>

#define ESPACIO 5

struct nodo{

    int dato;
    struct nodo *ptrI, *ptrD;

};

struct nodo* crearNodo(int dato){

        struct nodo* ptrN = (struct nodo*)malloc(sizeof(struct nodo));

        ptrN -> dato = dato;
        ptrN -> ptrI = ptrN -> ptrD = NULL;

    return ptrN; 
}

void imprimirArbol(struct nodo *raiz, int espacio_actual){

    if(raiz == NULL){
        return;
    }
    espacio_actual += ESPACIO;
    
    imprimirArbol(raiz -> ptrD, espacio_actual);
    printf("\n");

    for(int i = ESPACIO; i < espacio_actual; i++){
        printf(" ");
    }
    printf("%d\n", raiz -> dato);
    imprimirArbol(raiz -> ptrI, espacio_actual);
}

void printTree2D(struct nodo *raiz){

    if(raiz == NULL){
        printf("El árbol esta vacio \n");
        return;
    }
    printf("\n--------------------------------------------------\n");
    imprimirArbol(raiz, 0);
    printf("--------------------------------------------------\n");
}

//Vamos a crear las funciones de borrar nodos.

struct nodo* borrarHojas(struct nodo *raiz, int valor){

    if(raiz == NULL)
    return NULL;
    
    if(raiz -> dato == valor){

    if(raiz -> ptrI == NULL && raiz -> ptrD == NULL){
        free (raiz);
        printf("No %d eliminado. \n ", valor);
        return NULL;
        }else{

            printf("El nodo %d tiene hijos, no es una hoja", valor);
            return raiz;
        }
    }   

    raiz -> ptrD = borrarHojas(raiz -> ptrD, valor);
    raiz -> ptrI = borrarHojas(raiz -> ptrI, valor);
    return raiz;
}

void preorden(struct nodo* raiz){

    if(raiz != NULL){
        printf("%d", raiz -> dato);
        preorden(raiz -> ptrI);
        preorden(raiz -> ptrD);
    }
}

void inorden(struct nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->ptrI);       
        printf("%d", raiz->dato);   
        inorden(raiz->ptrD);         
    }
}

void postorden(struct nodo* raiz){
    if(raiz != NULL){
        postorden(raiz -> ptrI);
        postorden(raiz -> ptrD);
        printf("%d", raiz -> dato);
    }
}

void imprimirDescendente(struct nodo* raiz) {
    if (raiz != NULL) {
        imprimirDescendente(raiz -> ptrD);
        printf("%d", raiz -> dato);
        imprimirDescendente(raiz -> ptrI);
    }
}

int contarNodos(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNodos(raiz -> ptrI) + contarNodos(raiz -> ptrD);
}

int sumarNodos(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dato + sumarNodos(raiz -> ptrI) + sumarNodos(raiz -> ptrD);
}

int contarHojas(struct nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->ptrI == NULL && raiz->ptrD == NULL) {
        return 1;
    }
    return contarHojas(raiz->ptrI) + contarHojas(raiz->ptrD);
}

int contarInternos(struct nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->ptrI == NULL && raiz->ptrD == NULL) {
        return 0;
    }
    return 1 + contarInternos(raiz->ptrI) + contarInternos(raiz->ptrD);
}

int contarNodosPares(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    
    if (raiz->dato % 2 == 0) {
        return 1 + contarNodosPares(raiz->ptrI) + contarNodosPares(raiz->ptrD);
    }
    return contarNodosPares(raiz->ptrI) + contarNodosPares(raiz->ptrD);
}

int contarUnHijo(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    
    if ((raiz->ptrI == NULL && raiz->ptrD != NULL) || (raiz->ptrI != NULL && raiz->ptrD == NULL)) {
        return 1 + contarUnHijo(raiz->ptrI) + contarUnHijo(raiz->ptrD);
    }
    return contarUnHijo(raiz->ptrI) + contarUnHijo(raiz->ptrD);
}

int contarNodosMayores(struct nodo* raiz, int limite) {
    if (raiz == NULL) return 0;
    
    if (raiz->dato > limite) {
        return 1 + contarNodosMayores(raiz->ptrI, limite) + contarNodosMayores(raiz->ptrD, limite);
    }
    
    return contarNodosMayores(raiz->ptrI, limite) + contarNodosMayores(raiz->ptrD, limite);
}

int sumarHojas(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    
    if (raiz->ptrI == NULL && raiz->ptrD == NULL) {
        return raiz->dato;
    }
    return sumarHojas(raiz->ptrI) + sumarHojas(raiz->ptrD);
}

int sumarInternos(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    
    if (raiz->ptrI == NULL && raiz->ptrD == NULL) {
        return 0;
    }
    return raiz->dato + sumarInternos(raiz->ptrI) + sumarInternos(raiz->ptrD);
}

int sumarNodosPares(struct nodo* raiz) {
    if (raiz == NULL) return 0;
    
    if (raiz->dato % 2 == 0) {
        return raiz->dato + sumarNodosPares(raiz->ptrI) + sumarNodosPares(raiz->ptrD);
    }
    return sumarNodosPares(raiz->ptrI) + sumarNodosPares(raiz->ptrD);
}

int sumarNodosMayores(struct nodo* raiz, int limite) {
    if (raiz == NULL) return 0;
    
    if (raiz->dato > limite) {
        return raiz->dato + sumarNodosMayores(raiz->ptrI, limite) + sumarNodosMayores(raiz->ptrD, limite);
    }
    return sumarNodosMayores(raiz->ptrI, limite) + sumarNodosMayores(raiz->ptrD, limite);
}

int buscarElemento(struct nodo* raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->dato == valor) {
        return 1;
    }
    return buscarElemento(raiz->ptrI, valor) || buscarElemento(raiz->ptrD, valor);
}

int obtenerMayor(struct nodo* raiz) {
    if (raiz == NULL) return -1; 
    
    int max = raiz->dato;
    int maxI = obtenerMayor(raiz->ptrI);
    int maxD = obtenerMayor(raiz->ptrD);
    
    if (maxI > max) max = maxI;
    if (maxD > max) max = maxD;
    
    return max;
}

int obtenerMenor(struct nodo* raiz) {
    if (raiz == NULL) return -1; 
    
    int min = raiz->dato;
    if (raiz->ptrI != NULL) {
        int minI = obtenerMenor(raiz->ptrI);
        if (minI < min) min = minI;
    } 
    if (raiz->ptrD != NULL) {
        int minD = obtenerMenor(raiz->ptrD);
        if (minD < min) min = minD;
    }
    return min;
}

void imprimirMayores(struct nodo* raiz, int limite) {
    if (raiz == NULL) return;
    
    imprimirMayores(raiz->ptrI, limite);
    
    if (raiz->dato > limite) {
        printf("%d ", raiz->dato);
    }
    imprimirMayores(raiz->ptrD, limite);
}

int sumarMayoresQue(struct nodo* raiz, int limite) {
    if (raiz == NULL) return 0;
    
    if (raiz->dato > limite) {
        return raiz->dato + sumarMayoresQue(raiz->ptrI, limite) + sumarMayoresQue(raiz->ptrD, limite);
    }
    return sumarMayoresQue(raiz->ptrI, limite) + sumarMayoresQue(raiz->ptrD, limite);
}




struct nodo* obtenerNodoMaximo(struct nodo* raiz) {
    if (raiz == NULL) return NULL;
    
    struct nodo* max = raiz;
    struct nodo* maxI = obtenerNodoMaximo(raiz->ptrI);
    struct nodo* maxD = obtenerNodoMaximo(raiz->ptrD);
    
    if (maxI != NULL && maxI->dato > max->dato) max = maxI;
    if (maxD != NULL && maxD->dato > max->dato) max = maxD;
    
    return max;
}

void imprimirLigadosAlMayor(struct nodo* raiz) {
    struct nodo* mayor = obtenerNodoMaximo(raiz);
    
    if (mayor == NULL) return;
    
    if (mayor->ptrI == NULL && mayor->ptrD == NULL) {
        printf("Ninguno (el nodo mayor es una hoja)");
        return;
    }
    
    if (mayor->ptrI != NULL) printf("%d ", mayor->ptrI->dato);
    if (mayor->ptrD != NULL) printf("%d ", mayor->ptrD->dato);
}

struct nodo* eliminarAuxiliar(struct nodo* raiz, int valor) {
    if (raiz == NULL) return NULL;
    
    if (raiz->dato == valor) {
        if (raiz->ptrI == NULL) {
            struct nodo* temp = raiz->ptrD;
            free(raiz);
            return temp;
        } else if (raiz->ptrD == NULL) {
            struct nodo* temp = raiz->ptrI;
            free(raiz);
            return temp;
        }
        
        struct nodo* temp = raiz->ptrI;
        struct nodo* aux = temp;
        while (aux->ptrD != NULL) {
            aux = aux->ptrD;
        }
        aux->ptrD = raiz->ptrD;
        free(raiz);
        return temp;
    }
    
    raiz->ptrI = eliminarAuxiliar(raiz->ptrI, valor);
    raiz->ptrD = eliminarAuxiliar(raiz->ptrD, valor);
    return raiz;
}

struct nodo* eliminarNodoMenor(struct nodo* raiz) {
    if (raiz == NULL) return NULL;
    int min = obtenerMenor(raiz);
    return eliminarAuxiliar(raiz, min);
}

struct nodo* eliminarNodoMayor(struct nodo* raiz) {
    if (raiz == NULL) return NULL;
    int max = obtenerMayor(raiz);
    return eliminarAuxiliar(raiz, max);
}

struct nodo* eliminarUnHijoRecursivo(struct nodo* raiz, int valor, int* estado) {
    if (raiz == NULL) return NULL;
    
    if (raiz->dato == valor) {
        if ((raiz->ptrI == NULL && raiz->ptrD != NULL) || (raiz->ptrI != NULL && raiz->ptrD == NULL)) {
            *estado = 1;
            struct nodo* temp;
            if (raiz->ptrI != NULL) {
                temp = raiz->ptrI;
            } else {
                temp = raiz->ptrD;
            }
            free(raiz);
            return temp;
        } else {
            *estado = 2;
            return raiz;
        }
    }
    
    if (*estado == 0) raiz->ptrI = eliminarUnHijoRecursivo(raiz->ptrI, valor, estado);
    if (*estado == 0) raiz->ptrD = eliminarUnHijoRecursivo(raiz->ptrD, valor, estado);
    
    return raiz;
}

struct nodo* eliminarNodoUnHijo(struct nodo* raiz, int valor) {
    int estado = 0;
    raiz = eliminarUnHijoRecursivo(raiz, valor, &estado);
    
    if (estado == 0) {
        printf("\nAdvertencia: El nodo %d no se encuentra en el arbol.\n", valor);
    } else if (estado == 2) {
        printf("\nAdvertencia: El nodo %d no tiene exactamente un hijo.\n", valor);
    } else if (estado == 1) {
        printf("\nEl nodo %d fue eliminado correctamente.\n", valor);
    }
    
    return raiz;
}

struct nodo* eliminarDosHijosRecursivo(struct nodo* raiz, int valor, int* estado) {
    if (raiz == NULL) return NULL;
    
    if (raiz->dato == valor) {
        if (raiz->ptrI != NULL && raiz->ptrD != NULL) {
            *estado = 1;
            
            struct nodo* padreSucesor = raiz;
            struct nodo* sucesor = raiz->ptrD;
            
            while (sucesor->ptrI != NULL) {
                padreSucesor = sucesor;
                sucesor = sucesor->ptrI;
            }
            
            raiz->dato = sucesor->dato;
            
            if (padreSucesor == raiz) {
                padreSucesor->ptrD = sucesor->ptrD;
            } else {
                padreSucesor->ptrI = sucesor->ptrD;
            }
            
            free(sucesor);
            return raiz;
        } else {
            *estado = 2;
            return raiz;
        }
    }
    
    if (*estado == 0) raiz->ptrI = eliminarDosHijosRecursivo(raiz->ptrI, valor, estado);
    if (*estado == 0) raiz->ptrD = eliminarDosHijosRecursivo(raiz->ptrD, valor, estado);
    
    return raiz;
}

struct nodo* eliminarNodoDosHijos(struct nodo* raiz, int valor) {
    int estado = 0;
    raiz = eliminarDosHijosRecursivo(raiz, valor, &estado);
    
    if (estado == 0) {
        printf("\nAdvertencia: El nodo %d no se encuentra en el arbol.\n", valor);
    } else if (estado == 2) {
        printf("\nAdvertencia: El nodo %d no tiene dos hijos.\n", valor);
    } else if (estado == 1) {
        printf("\nEl nodo %d fue eliminado correctamente.\n", valor);
    }
    
    return raiz;
}

struct nodo* construirArbolPrueba() {
    // Pon la raíz en medio (20)
    struct nodo* raiz = crearNodo(20); 
    
    
    raiz->ptrI = crearNodo(10);
    raiz->ptrI->ptrI = crearNodo(5);
    raiz->ptrI->ptrD = crearNodo(15);
    
    
    raiz->ptrD = crearNodo(30);
    raiz->ptrD->ptrD = crearNodo(40);
    raiz->ptrD->ptrI = crearNodo(25); 
    
    return raiz;
}

int main(){

    struct nodo* raiz = construirArbolPrueba();
    int opcion = -1;
    int valor;
    int mostrar = 1;


    while(opcion != 0){
        if(mostrar){
            printf("\n ---Estado actual del arbol--- \n");
            printTree2D(raiz);
        }

            printf("\n ---MENU DE OPCIONES---\n");
            printf("1.- Borrar nodos hoja. \n");
            printf("2.- Restaurar Arbol original. \n");
            printf("3.- Mostrar / Ocultar arbol. \n");
            printf("4.- Recorrido Preorden. \n");
            printf("5.- Recorrido Inorden. \n");
            printf("6.- Recorrido postorden. \n");
            printf("7.- Imprimir descendente. \n");
            printf("8.- Contar nodos. \n");
            printf("9.- Sumar nodos");
            printf("10.- Contar nodos hoja.\n");
            printf("11.- Contar nodos internos. \n");
            printf("12.- Contar nodos pares. \n");
            printf("13.- Contar nodos con un solo hijo. \n");
            printf("14.- Contar nodos mayores a un valor. \n");
            printf("15.- Sumar nodos hoja. \n");
            printf("16.- Sumar nodos internos. \n");
            printf("17.- Sumar nodos pares. \n");
            printf("18.- Sumar nodos mayores a un valor. \n");
            printf("19.- Buscar un elemento. \n");
            printf("20.- Obtener elemento mayor. \n");
            printf("21.- Obtener elemento menor. \n");
            printf("22.- Imprimir nodos mayores a un valor. \n");
            printf("23.- Sumar nodos mayores a un numero. \n");
            printf("24.- Imprimir nodos ligados al mayor. \n");
            printf("25.- Eliminar nodo menor. \n");
            printf("26.- Eliminar nodo mayor. \n");
            printf("27.- Eliminar nodo con un solo hijo. \n");
            printf("28.- Eliminar nodo con dos hijos. \n");
            printf("0. Salir\n");
            printf("Elige una opcion: ");
            
        if(scanf("%d", &opcion) != 1){
            printf("Entrada invalida. Saliendo...");
            break;
        }

        switch(opcion) {

            case 1:
                printf("Ingrese el nodo que deseas eliminar: \n");
                scanf("%d", &valor);
                raiz = borrarHojas(raiz, valor);
                break;

            case 2:
                raiz = construirArbolPrueba();
                printf("\n[OK] Arbol restaurado a su estado original.\n");
                break;

            case 3:
                mostrar = !mostrar;
                break;

            case 4: 
                printf("\n El recorrido en preorden es: \n");
                preorden(raiz);
                break;
            
            case 5:
                printf("\n El recorrido Inorden es: \n");
                inorden(raiz);
                break;

            case 6:
                printf("\n El recorrido postorden es: \n");
                postorden(raiz);
                break;

            case 7:
                printf("\n Imprimir descendente \n");
                imprimirDescendente(raiz);
                break;

            case 8:
                printf("La cantidad de nodos total en el árbol es: %d\n", contarNodos(raiz));
                break;

            case 9:
                printf("La suma total de nodos en el árbol es: %d\n", sumarNodos(raiz));
                break;

            case 10:
                printf("\nLa cantidad de nodos hoja en el arbol es: %d\n", contarHojas(raiz));
                break;

            case 11:
                printf("\nLa cantidad de nodos internos en el arbol es: %d\n", contarInternos(raiz));
                break;
                
            case 12:
                printf("\nLa cantidad de nodos pares en el arbol es: %d\n", contarNodosPares(raiz));
                break;

            case 13:
                printf("\nLa cantidad de nodos con un solo hijo en el arbol es: %d\n", contarUnHijo(raiz));
                break;

            case 14:
                printf("Ingrese el valor a comparar: \n");
                scanf("%d", &valor);
                printf("\nLa cantidad de nodos mayores a %d en el arbol es: %d\n", valor, contarNodosMayores(raiz, valor));
                break;

            case 15:
                printf("\nLa suma de los nodos hoja en el arbol es: %d\n", sumarHojas(raiz));
                break;

            case 16:
                printf("\nLa suma de los nodos internos en el arbol es: %d\n", sumarInternos(raiz));
                break;

            case 17:
                printf("\nLa suma de los nodos pares en el arbol es: %d\n", sumarNodosPares(raiz));
                break;

            case 18:
                printf("Ingrese el valor a comparar: \n");
                scanf("%d", &valor);
                printf("\nLa suma de los nodos mayores a %d en el arbol es: %d\n", valor, sumarNodosMayores(raiz, valor));
                break;

            case 19:
                printf("Ingrese el valor a buscar: \n");
                scanf("%d", &valor);
                if (buscarElemento(raiz, valor)) {
                    printf("\nEl elemento %d SI se encuentra en el arbol.\n", valor);
                } else {
                    printf("\nEl elemento %d NO se encuentra en el arbol.\n", valor);
                }
                break;

            case 20:
                if (raiz == NULL) {
                    printf("\nEl arbol esta vacio.\n");
                } else {
                    printf("\nEl elemento mayor en el arbol es: %d\n", obtenerMayor(raiz));
                }
                break;

            case 21:
                if (raiz == NULL) {
                    printf("\nEl arbol esta vacio.\n");
                } else {
                    printf("\nEl elemento menor en el arbol es: %d\n", obtenerMenor(raiz));
                }
                break;

            case 22:
                printf("Ingrese el valor limite: \n");
                scanf("%d", &valor);
                printf("\nLos nodos mayores a %d son: ", valor);
                imprimirMayores(raiz, valor);
                printf("\n");
                break;

            case 23:
                printf("Ingrese el numero: \n");
                scanf("%d", &valor);
                printf("\nLa suma de los nodos mayores a %d es: %d\n", valor, sumarMayoresQue(raiz, valor));
                break;

            case 24:
                if (raiz == NULL) {
                    printf("\nEl arbol esta vacio.\n");
                } else {
                    printf("\nLos nodos ligados al mayor son: ");
                    imprimirLigadosAlMayor(raiz);
                    printf("\n");
                }
                break;

            case 25:
                if (raiz == NULL) {
                    printf("\nEl arbol esta vacio.\n");
                } else {
                    int menor = obtenerMenor(raiz);
                    raiz = eliminarNodoMenor(raiz);
                    printf("\nEl nodo menor (%d) ha sido eliminado.\n", menor);
                }
                break;

            case 26:
                if (raiz == NULL) {
                    printf("\nEl arbol esta vacio.\n");
                } else {
                    int mayor = obtenerMayor(raiz);
                    raiz = eliminarNodoMayor(raiz);
                    printf("\nEl nodo mayor (%d) ha sido eliminado.\n", mayor);
                }
                break;

            case 27:
                printf("Ingrese el nodo que deseas eliminar: \n");
                scanf("%d", &valor);
                raiz = eliminarNodoUnHijo(raiz, valor);
                break;

            case 28:
                printf("Ingrese el nodo que deseas eliminar: \n");
                scanf("%d", &valor);
                raiz = eliminarNodoDosHijos(raiz, valor);
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
