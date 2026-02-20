
//ptrs es Para punteros
#include<stdio.h>
#define TAM 50

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
struct Dato dato, *ptrs;
ptrs = &dato;

for(ptrs -> i = 0; ptrs -> i < TAM; ptrs -> i = ptrs -> i+1){

printf("\n Ingrese el nombre");
gets(ptrs -> arreglo[ptrs -> i].nombre);

printf("\n INgrese edad:");
scanf("%d", &ptrs -> arreglo[ptrs -> i].edad);

printf("\n Ingrese sexo:");
scanf(dato.arreglo[dato.i].sexo = getchar());
}
for(ptrs -> i = 0; ptrs -> i < TAM; ptrs -> i = ptrs -> i+1){
printf("\n En la celda %d esta %s con dir %p\t %d con dir %p\t %c con dir %p", ptrs -> i, ptrs ->arreglo[ptrs -> i].nombre, &ptrs -> arreglo[ptrs -> i].edad, ptrs -> arreglo[ptrs -> i].sexo);

}

return 0;
}