//Funcion: Es un fragmento de codigo que cumple con una funcion especifica, que puede tener multiples entradas
//las biblioteca son funciones en las cuales ya estan echas para que entren datos y nos de una salida
//
#include<stdio.h>

int longcad(char *ptr){
char *ptr2;

for(ptr2 = ptr; *ptr2 != '\0'; ptr2 += 1);
return((int)(ptr2 - ptr));
}
int main(){
	char cad[50];

	printf("\n Ingrese cadena: ");
		fgets(cad,50,stdin);
	printf("\n La cad %s tiene long %d",cad,longcad(cad));
	return 0;

}
