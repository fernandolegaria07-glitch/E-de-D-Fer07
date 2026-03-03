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

int meterCola(){
    *ptrC -> prtM = dato;
    ptrC -> ptrm = ptrC -> ptrm + 1;
    return 0;
}

int sacarCola(struct Cola *ptrC){
    int dato; 
    dato = *ptrC -> ptrs;
    ptrC -> ptrs = ptrC -> ptrs +1;
    return dato;
}

int estaColallena(){
    if(ptrC -> ptrm == &ptrC -> arreglo[TAM])
        return 1;
    else 
        return 0;
}

int estaColavacia(){
    if(ptrC -> ptrm == ptrC -> ptrs)
        return 1;
    else 
        return 0;\
}

int menu(){
    int opc;
    printf("1.- Para meter dato a la cola");
    pritnf("2.- Para sacar dato de la cola");
    printf("4.- Salir");
    pritnf("5.- Resetaer cola");
    scanf("%d", &opc);
    return opc;
}

int main(){
*struct Cola cola, *miptrC;
int miDato;
miptrC = &cola;

miptrC -> ptrm = miptrC -> arreglo;
miptrC -> ptrs = miptrC -> arreglo;

for(;;){
    int opc = menu();
    switch(opc){
        case 1:
            meterCola();
        break;

        case 2:
        if(estaColallena())
            prinf("\n La cola esta llena");
        else
            meterCola();

        }
    }
}
//Tarea, cola circular para el miercoles