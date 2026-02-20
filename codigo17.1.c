#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct DatosEstad {
    float arreglo[20];
    int numDatos;
    float prom;
    float datEst;  
    float *ptr;
};

int meterDatos(struct DatosEstad *ptrs) {
    printf("Ingrese el numero de Datos a ingresar: ");
    scanf("%d", &ptrs->numDatos);

    for(ptrs->ptr = ptrs->arreglo; ptrs->ptr < &ptrs->arreglo[ptrs->numDatos]; ptrs->ptr = ptrs->ptr + 1) {
        printf("Ingrese Dato: ");
        scanf("%f", ptrs->ptr);
    }
    return 0;
}

int calcularDatos(struct DatosEstad *ptrs) { 
    float suma = 0.0; 

    // Cálculo del promedio
    for(ptrs->ptr = ptrs->arreglo; ptrs->ptr < &ptrs->arreglo[ptrs->numDatos]; ptrs->ptr = ptrs->ptr + 1) {
        suma = suma + *ptrs->ptr;
    }
    ptrs->prom = suma / (ptrs->numDatos);

    // Cálculo de desviación estándar
    suma = 0.0;
    for(ptrs->ptr = ptrs->arreglo; ptrs->ptr < &ptrs->arreglo[ptrs->numDatos]; ptrs->ptr = ptrs->ptr + 1) {
        suma = suma + pow((ptrs->prom - *ptrs->ptr), 2);
    }
    // datEst se usa para guardar el resultado estadístico final
    ptrs->datEst = pow(suma / ptrs->numDatos, 0.5); 
    return 0;
}

int menu() {
    int opc;
    printf("\n 1 para ingresar");
    printf("\n 2 para calcular");
    printf("\n 3 para Salir");
    printf("\n Ingrese opción: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    struct DatosEstad datEst;
    struct DatosEstad *ptrs;

    ptrs = &datEst; 

    for(;;) {
        switch(menu()) {
            case 1:
                meterDatos(ptrs);
                break;
            case 2:
                calcularDatos(ptrs);
                
                printf("\n El promedio es %f y la desviación estandar es %f\n", ptrs->prom, ptrs->datEst);
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}