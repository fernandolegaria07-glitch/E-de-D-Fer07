#include <stdio.h>
#include <string.h>

int main() {

	// Es palindromo
	
	int bandera = 1;
	char cadena[60], *ptr1, *ptr2;

	printf("Ingrese la cadena\n");
	fgets(cadena, 60, stdin);

	cadena[strcspn(cadena, "\n")] = '\0';

	for(ptr2 = cadena; *ptr2 != '\0'; ptr2++);

	for(ptr1 = cadena, ptr2--;ptr1 < ptr2 ;ptr1++, ptr2--) {
		if(*ptr1 == *ptr2) {
			continue;
		} else {
			bandera = 0;
			break;
		}
	}

	if(bandera == 1) {
		printf("Es palindromo");
	} else {
		printf("No es palindromo");
	}
	return 0;
}