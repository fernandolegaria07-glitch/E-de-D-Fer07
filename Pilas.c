#include<stdio.h>
#define TAM 5
#include<stdlib.h>

//Pilas

struct Pila{
    int arreglo[TAM];
    int *ptrC;
};

int meterPila(struct Pila *ptrP, int dato){
    *ptrP -> ptrC = dato;
    ptrP -> ptrC = ptrP -> ptrC + 1;
    return 0;
}

int estaPilallena(struct Pila *ptrP){
    if(ptrP -> ptrC == &ptrP -> arreglo[TAM])
        return 1;
    else
        return 0;
}

int sacarPila(struct Pila *ptrP){
    ptrP -> ptrC = ptrP -> ptrC -1;
    return(*ptrP -> ptrC);
}

int estaVaciapila(struct Pila *ptrP){

    if(ptrP -> ptrC == ptrP -> arreglo)
        return 1;
    else 
        return 0;

}

int menu(){
int opc;
    printf("\n1 Para meter en pila: ");
    printf("\n2 Para Sacar de pila: ");
    printf("\n3 Para salir: ");
    printf("\n Ingrese opcción: ");
    scanf("%d", &opc);
    return opc;

}


int main(){
    struct Pila pila, *miptrP;
    int miDato;
    miptrP = &pila;
    miptrP -> ptrC = miptrP -> arreglo;  //Esta es mi condición inicial.

for (;;){
switch(menu()){
    case1:
        if(estaPilallena(miptrP))
            printf("la pila esta llena");
        else {
            printf("\nIngrese un entero");
            scanf("%d", &miDato);
            meterPila(miptrP, miDato);
        }
        break;
    case2:
        if(estaVaciapila(miptrP))
            printf("\n La pila esta vacia");
        else{
            printf("\n El valor recuperado es %d", sacarPila(miptrP));
        }
        break;
    case3:
    exit(0);
    break;
    default:
        printf("Ingrese valores del 1 al 3");
}
}
    return 0;
}