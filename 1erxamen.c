//Me funciono la el recorrer, checar en el pasado

#include<stdio.h>
#include<stdlib.h>
#define TAM  10

// * ptrC, es el puntero de cabezera/control.

struct Pila{

int dato;
int arreglo[TAM];
int *ptrI, *ptrD, *ptrSig;

};

// Primero inicializamos la pila
void iniciarPila(struct Pila *ptr){
    ptr->ptrI = &ptr->arreglo[0];          
    ptr->ptrD = &ptr->arreglo[TAM - 1];    
}
//Cramos condiciones, si pila esta llena o no:
int estaPilallena(struct Pila *ptr){
    return ptr->ptrI > ptr->ptrD;
}

void recorrerPila(struct Pila *ptr) {
    printf("\n--- Estado del Arreglo [%d elementos] ---\n", TAM);
    
    for (int i = 0; i < TAM; i++) {
        printf("[%d] ", ptr->arreglo[i]);
    }
    
    printf("\n----------------------------------------\n");
}

//Funcion para meter dato por derecha
void meterDatoizquierda(struct Pila *ptr, int dato){
    if(ptr -> ptrI <= ptr -> ptrD){
        *ptr -> ptrI = dato;
        ptr -> ptrI++;
        printf("Dato %d guardado a la izquierda. \n", dato);
    }
    else{
        printf("\n Pial llena por izquierda");
    }
}

void meterDatoderecha(struct Pila *ptr, int dato){
    if(ptr -> ptrD >= ptr -> ptrI){
        *ptr -> ptrD = dato;
         ptr -> ptrD--;
    }
    else{
        printf("\n La pila esta llena por la derecha\n");
    }
}

int sacarIzquierda(struct Pila *ptr) {
    if (ptr->ptrI > &ptr->arreglo[0]) {
        ptr->ptrI--;             
        return *(ptr->ptrI);     
    }
    return -1;
}

int sacarDerecha(struct Pila *ptr) {

    if (ptr->ptrD < &ptr->arreglo[TAM - 1]) {
        ptr->ptrD++;           
        return *(ptr->ptrD);
    }
    return -1;
}


int menu(){
int opc;
printf("\n1.- Ingrese dato por la derecha: ");
printf("\n2.- Ingrese dato por la Izquierda: ");
printf("\n3.- Borrar dato por la dereha");
printf("\n4.- Borrar dato por al Izquierda");
printf("\n5.- Recorrer pila: ");
printf("\n6 -. Exit. ");
scanf("%d", &opc);
return opc;
}

int main(){

    struct Pila pila;
    struct Pila *miPtr = &pila;
    int dato;

    iniciarPila(miPtr); 

    for(;;){
        switch(menu()){
            case 1:
                printf("Dato para derecha: \n");
                scanf("%d", &dato);
                meterDatoderecha(miPtr, dato);
                break;
            case 2:
                printf("Dato para izquierda: \n");
                scanf("%d", &dato);
                meterDatoizquierda(miPtr, dato);
            break;

           case 3:
             dato = sacarDerecha(miPtr);
             if (dato != -1) {
             printf("Dato eliminado por la derecha: %d\n", dato);
             } else {
                printf("No hay datos por la derecha para borrar.\n");
            }
            break;

         case 4:
         dato = sacarIzquierda(miPtr);
            if (dato != -1) {
            printf("Dato eliminado por la izquierda: %d\n", dato);
        }   else {
            printf("No hay datos por la izquierda para borrar.\n");
            }
            break;

            case 5:
                recorrerPila(miPtr);
            break;
            
            case 6:
            exit(0);
            break;
        }
    }
    return 0;
}
