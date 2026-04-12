#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Dato{
    char nombre[30];
    int edad;
};

struct nodo{
    struct Dato dato;
    struct nodo *ptrSig;
};

struct nodo* crearNodo(struct Dato *ptrDato){
    struct nodo *ptrN;
    ptrN = (struct nodo*) malloc(sizeof(struct nodo));
    
    if (ptrN == NULL) {
        printf("Error: No hay memoria suficiente.\n");
        return NULL;
    }

    ptrN -> dato.edad = ptrDato -> edad;
    strcpy(ptrN -> dato.nombre, ptrDato -> nombre);
    ptrN -> ptrSig = NULL;
    return ptrN;
}

int meterNodo(struct nodo **ptrRef, struct Dato *ptrDato){
    struct nodo *ptrN;
    ptrN = crearNodo(ptrDato);

    if (ptrN == NULL) return -1; 

    if(*ptrRef == NULL){ 
        *ptrRef = ptrN;
    }
    else{
        ptrN -> ptrSig = *ptrRef;
        *ptrRef = ptrN;
    }
    return 0;
}

int recorrerNodo(struct nodo *ptrRef){
    struct nodo *ptrRec;
    ptrRec = ptrRef;
    
    while(ptrRec != NULL){ 
        printf("%s \t %d \n", ptrRec -> dato.nombre, ptrRec -> dato.edad);
        ptrRec = ptrRec -> ptrSig;
    }
    return 0;
}

int borrardato(struct nodo **ptrRef) {
    if (*ptrRef == NULL) {
        printf("\nLa lista esta vacia. No hay nada que borrar.\n");
        return -1;
    }

    struct nodo *temp = *ptrRef; 
    *ptrRef = (*ptrRef)->ptrSig; 
    free(temp);                  

    printf("\nNodo eliminado exitosamente.\n");
    return 0;
}

int menu(){
    int opc;
    printf("\n 1- Ingresar dato \n");
    printf("\n 2.- recorrer Dato \n");
    printf("\n 3- borrar dato \n");
    printf("\n 4.- Exit: \n");
    scanf("%d", &opc);
    return opc;
}

int main(){
    struct Dato miDato;
    struct nodo *ptrRef1 = NULL;
    struct nodo **ptrRef2 = &ptrRef1;

    for(;;) {
        switch(menu()){

            case 1:
                printf("Ingresar edad: ");
                scanf("%d", &miDato.edad);
                getchar(); 
            
                printf("Ingrese nombre: ");
                fgets(miDato.nombre, 30, stdin);
                miDato.nombre[strcspn(miDato.nombre, "\n")] = '\0';
                
                meterNodo(ptrRef2, &miDato);
                break;

            case 2:
                printf("\n--- Mostrando Datos ---\n");
                recorrerNodo(ptrRef1);
                break;

            case 3:
                borrardato(ptrRef2);
                break;

            case 4:
               exit(0);
        }
    }

    return 0;
}

