#include <stdio.h>
#include "identifier.h"

int main(int argc, char *argv[])
{
	//char id[100];
	int result;
	
	printf("Identificador: %s\n",argv[1]);
	//scanf("%s", id);
	result = identifier(argv[1]);
	
	if(result == 0)
		printf("Válido\n");
	else
		printf("Inválido\n");
}
