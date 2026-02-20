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
struct per *ptr;

};

int main(){
struct Dato dato, *ptrs;
ptrs = &dato;

for(ptrs -> ptr = ptrs -> arreglo; ptrs < TAM; ptrs -> ptr = ptrs -> ptr + 1){

printf("\n Ingrese el nombre");
gets(ptrs -> ptr -> nombre);

printf("\n INgrese edad:");
scanf("%d", &ptrs -> ptr -> edad);

printf("\n Ingrese sexo:");
scanf(ptrs -> ptr -> sexo = getchar());
}
for(ptrs -> ptr = ptrs -> arreglo; ptrs < TAM; ptrs -> ptr = ptrs -> ptr + 1){
printf("\n En la celda %d esta %s con dir %p\t %d con dir %p\t %c con dir %p", (int)(ptrs -> ptr-ptrs -> arreglo), ptrs -> ptr -> nombre, &ptrs ->ptr -> edad, ptrs -> ptr -> sexo);

}

return 0;
}