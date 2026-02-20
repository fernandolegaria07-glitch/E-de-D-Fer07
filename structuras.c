#include <stdio.h>
#define TAM 1 

struct per{
    char nombre[30];
    int edad;
    char sexo;
};

struct Dato{
    struct per arreglo[TAM];
    int i;
};

int main(){
    struct Dato dato;

    for(dato.i = 0; dato.i < TAM; dato.i = dato.i + 1){
        printf("\n Ingrese el nombre: ");
        fgets(dato.arreglo[dato.i].nombre, 30, stdin);

        printf("\n Ingrese edad: ");
        scanf("%d", &dato.arreglo[dato.i].edad);

        printf("\n Ingrese sexo: ");
        scanf(" %c", &dato.arreglo[dato.i].sexo);
        
        //Limpieza del bufer
        while(getchar() != '\n');
    }

    for(dato.i = 0; dato.i < TAM; dato.i = dato.i + 1){
        // Se deben colocar la cantidad de argumentos sobre la cantidad de porcentajes que se coloquen
        printf("\n En la celda %d esta %s con edad %d (dir %p) y sexo %c (dir %p)", dato.i, dato.arreglo[dato.i].nombre, dato.arreglo[dato.i].edad, &dato.arreglo[dato.i].edad, dato.arreglo[dato.i].sexo, &dato.arreglo[dato.i].sexo);
    }

    return 0;
}