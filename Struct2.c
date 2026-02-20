#include<stdio.h>
#define TAM 1

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
struct Dato dato;

for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[TAM]; dato.ptr = dato.ptr + 1){
printf("\n Ingrese el nombre");
gets(dato.ptr -> nombre);

printf("\n INgrese edad:");
scanf("%d", &dato.ptr -> edad);

printf("\n Ingrese sexo:");
scanf(dato.ptr -> sexo = getchar());
}
for(dato.ptr = dato.arreglo; dato.ptr < &dato.arreglo[TAM]; dato.ptr = dato.ptr + 1){
printf("\n En la celda %d esta %s con dir %p\t %d con dir %p\t %c con dir %p",(int)(dato.ptr-dato.arreglo), dato.ptr -> nombre, &dato.ptr ->nombre, &dato.ptr -> edad, dato.ptr -> sexo);

}

return 0;
}