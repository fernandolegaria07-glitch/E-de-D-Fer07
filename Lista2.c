#include<stdio.h>
#include<stdlib.h>


struct nodo{
    int Num;
    int exp;
    struct nodo *ptrSig;
};


struct nodo* crearNodo(int coef, int exp) {
    struct nodo *ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    if(ptrN != NULL){
        ptrN -> Num = coef;
        ptrN -> exp = exp;
        ptrN -> ptrSig = NULL;
    }
    return ptrN;
}


void meterTermino(struct nodo **cabeza, int coef, int exp){
    if (coef == 0) 
    return;

    struct nodo *ptrN = crearNodo(coef, exp);
    struct nodo *actual = *cabeza;
    struct nodo *anterior = NULL;

    
    while(actual != NULL && actual->exp > exp){
        anterior = actual;
        actual = actual->ptrSig;
    }

    
    if(actual != NULL && actual->exp == exp){
        actual->Num += coef;
        
        
        free(ptrN); 
        return;
    }

    
    if(anterior == NULL){
        
        ptrN->ptrSig = *cabeza;
        *cabeza = ptrN;
    } else {
        
        anterior->ptrSig = ptrN;
        ptrN->ptrSig = actual;
    }
    
}



void sacarTermino(struct nodo **cabeza, int expBorrar){
    if(*cabeza == NULL) {
        printf("\n[El polinomio esta vacio]\n");
        return;
    }

    struct nodo *temp = *cabeza;

    
    if(temp->exp == expBorrar){
        *cabeza = temp->ptrSig; 
        printf("\n[Termino con exp %d eliminado con exito]\n", expBorrar);
        free(temp); 
        return;
    }

    
    struct nodo *anterior = NULL;
    
    while(temp != NULL && temp->exp != expBorrar){
        anterior = temp;
        temp = temp->ptrSig;
    }

    if(temp == NULL){
        printf("\n[Error: No se encontro el exp %d]\n", expBorrar);
    } else {
        anterior->ptrSig = temp->ptrSig;
        printf("\n[Termino con exp %d eliminado con exito]\n", expBorrar);
        free(temp); 
    }
}


void recorrerPolinomio(struct nodo **cabeza){
    struct nodo *aux = *cabeza;
    
    if(aux == NULL){
        printf("0\n");
        return;
    }
    
    while(aux != NULL){
        
        if (aux->Num > 0 && aux != *cabeza) {
            printf("+ ");
        }
        printf("%dx^%d ", aux->Num, aux->exp);
        aux = aux -> ptrSig;
    }
    printf("\n");
}


void sumarPolinomios(struct nodo **poly1, struct nodo **poly2, struct nodo **poly3){
    struct nodo *p1 = *poly1;
    struct nodo *p2 = *poly2;
    

    *poly3 = NULL; 


    while(p1 != NULL && p2 != NULL){
        if(p1->exp > p2->exp){
            meterTermino(poly3, p1->Num, p1->exp);
            p1 = p1->ptrSig;
        } 
        else if(p1->exp < p2->exp){
            meterTermino(poly3, p2->Num, p2->exp);
            p2 = p2->ptrSig;
        } 
        else {
        
            meterTermino(poly3, p1->Num + p2->Num, p1->exp);
            p1 = p1->ptrSig;
            p2 = p2->ptrSig;
        }
    }

    
    while(p1 != NULL){
        meterTermino(poly3, p1->Num, p1->exp);
        p1 = p1->ptrSig;
    }

    
    while(p2 != NULL){
        meterTermino(poly3, p2->Num, p2->exp);
        p2 = p2->ptrSig;
    }
}


int menu(){
    int opc;
    printf("\n--- SUMA DE POLINOMIOS CON LISTAS ---");
    printf("\n1.- Ingresar termino al Polinomio 1");
    printf("\n2.- Ingresar termino al Polinomio 2");
    printf("\n3.- Mostrar Polinomios (1 y 2)");
    printf("\n4.- SUMAR y mostrar resultado (Polinomio 3)");
    printf("\n5.- Eliminar un termino");
    printf("\n6.- Salir");
    printf("\nOpcion: ");
    scanf("%d", &opc);
    return opc;
}


int main() {
    
    struct nodo *lista1 = NULL;
    struct nodo **poly1 = &lista1;
    
    struct nodo *lista2 = NULL;
    struct nodo **poly2 = &lista2;
    
    struct nodo *lista3 = NULL;
    struct nodo **poly3 = &lista3;

    int coef, exp, opcionLista;

    for(;;){
        switch(menu()){
            case 1:
                printf("\n--- POLINOMIO 1 ---");
                printf("\nIngrese el Num (ej. 3 para 3x^2): ");
                scanf("%d", &coef);
                printf("Ingrese el exp (ej. 2 para 3x^2): ");
                scanf("%d", &exp);
                meterTermino(poly1, coef, exp);
                break;
                
            case 2:
                printf("\n--- POLINOMIO 2 ---");
                printf("\nIngrese el Num: ");
                scanf("%d", &coef);
                printf("Ingrese el exp: ");
                scanf("%d", &exp);
                meterTermino(poly2, coef, exp);
                break;
                
            case 3:
                printf("\nPolinomio 1: ");
                recorrerPolinomio(poly1);
                printf("Polinomio 2: ");
                recorrerPolinomio(poly2);
                break;
                
            case 4:
                sumarPolinomios(poly1, poly2, poly3);
                printf("\n=== RESULTADO DE LA SUMA (POLINOMIO 3) ===\n");
                recorrerPolinomio(poly3);
                break;
                
            case 5:
                printf("\n--- ELIMINAR TERMINO ---");
                printf("\nDe cual polinomio desea eliminar un termino? (1 o 2): ");
                scanf("%d", &opcionLista);
                printf("Ingrese el exp del termino que desea borrar: ");
                scanf("%d", &exp);
                
                if(opcionLista == 1){
                    sacarTermino(poly1, exp);
                } 
                else if(opcionLista == 2){
                    sacarTermino(poly2, exp);
                } 
                else {
                    printf("\nOpcion de polinomio no valida.\n");
                }
                break;
                
            case 6:
                exit(0);
                break;
                
            default:
                printf("\nOpcion no valida\n");
        }
    }

    return 0;
}
