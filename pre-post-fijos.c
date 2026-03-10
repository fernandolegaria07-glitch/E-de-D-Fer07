//En progrmación tenemos terminos como infijo, prefijo y postfijo 

//Ahora veremos la Cola Estática

// First IN- Firts OUT

//El ejemplo de una cola estatica, tiene una limitación por que cuando esta llena
//ya no puede entrar nadie mas, pero si puedes sacar los datos

//En una cola, vamos a decir que el pirmer dato que llega es el primero en ser atendido.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define TAM 5


struct Cola{

    int arreglo[TAM];
    int *ptrm, *ptrs;
};

int meterCola(struct Cola *ptrC, int dato){
    *ptrC -> ptrm = dato;
    ptrC -> ptrm = ptrC -> ptrm + 1;
    return 0;
}

int sacarCola(struct Cola *ptrC){
    int dato; 
    dato = *ptrC -> ptrs;
    ptrC -> ptrs = ptrC -> ptrs + 1;
    return dato;
}

int estaColallena(struct Cola *ptrC){
    if(ptrC -> ptrm == &ptrC -> arreglo[TAM])
        return 1;
    else 
        return 0;
}

int estaColavacia(struct Cola *ptrC){
    if(ptrC -> ptrm == ptrC -> ptrs)
        return 1;
    else 
        return 0;
}

int menu(){
    int opc;
    printf("\n1.- Para meter dato a la cola");
    printf("\n2.- Para sacar dato de la cola");
    printf("\n4.- Salir");
    printf("\n5.- Resetear cola\n");
    printf("Opcion: ");
    scanf("%d", &opc);
    return opc;
}

int main(){
struct Cola cola, *miptrC;
int miDato;
miptrC = &cola;

miptrC -> ptrm = miptrC -> arreglo;
miptrC -> ptrs = miptrC -> arreglo;

for(;;){
    int opc = menu();
    switch(opc){
        case 1:
            if(estaColallena(miptrC))
                printf("\n La cola esta llena");
            else{
                printf("\n Dame el dato a meter: ");
                scanf("%d", &miDato);
                meterCola(miptrC, miDato);
            }
        break;

        case 2:
            if(estaColavacia(miptrC))
                printf("\n La cola esta vacia");
            else{
                miDato = sacarCola(miptrC);
                printf("\n El dato sacado es: %d", miDato);
            }
        break;

        case 4:
            exit(0);
        break;

        case 5:
            miptrC -> ptrm = miptrC -> arreglo;
            miptrC -> ptrs = miptrC -> arreglo;
            printf("\n Cola reseteada");
        break;
        
        default:
            printf("\n Opcion no valida");
        break;
        }
    }
    return 0;
}