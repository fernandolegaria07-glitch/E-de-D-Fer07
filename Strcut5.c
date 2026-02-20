//Ahora con puntero doble
#include<stdio.h>
#define TAM 50

struct per{
    char nombre[30];
    int edad;
    char sexo;
    
};

struct Dato{
struct per arreglo[TAM];
struct per *ptr1, *ptr2;

};

int main(){
struct Dato dato, *ptrs;
ptrs = &dato;

for(ptrs -> ptr1 = ptrs -> arreglo, ptrs -> ptr2 = &ptrs -> ptr1; *ptrs -> ptr2 < ptrs -> arreglo[TAM]; *ptrs -> ptr2 = *ptrs -> ptr2 + 1){

printf("\n Ingrese el nombre");
gets((*ptrs -> ptr2) -> nombre);

printf("\n INgrese edad:");
scanf("%d", &(*ptrs -> ptr2) -> edad);

printf("\n Ingrese sexo:");
scanf((*ptrs -> ptr) -> sexo = getchar());
}
for(ptrs -> ptr1 = ptrs -> arreglo, ptrs -> ptr2 = &ptrs -> ptr1; *ptrs -> ptr2 < ptrs -> arreglo[TAM]; *ptrs -> ptr2 = *ptrs -> ptr2 + 1){
printf("\n En la celda %d esta %s con dir %p\t %d con dir %p\t %c con dir %p", (int)(*ptrs -> ptr2-ptrs -> arreglo), *ptrs -> ptr2 -> nombre, &(*ptrs -> ptr2 -> edad), *ptrs -> ptr2 -> sexo);

}

return 0;
}