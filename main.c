#include <stdio.h>
#include "identifier.h"

int main(void)
{
	a = 1;
	int b;
	b++;
	char id[100];
	int result;
	
	printf("Identificador: ");
	scanf("%s", id);
	result = identifier(id);
	
	if(result == 0)
		printf("Válido\n");
	else
		printf("Inválido\n");
}
