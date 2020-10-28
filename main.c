#include <stdio.h>
#include "identifier.h"

int main(void)
{
	char id[100];
	char test = id[101];
	int result;
	
	printf("Identificador: ");
	scanf("%s", id);
	result = identifier(id);
	
	if(result == 0)
		printf("Válido\n");
	else
		printf("Inválido\n");
}
