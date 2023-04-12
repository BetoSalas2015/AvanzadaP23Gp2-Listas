#include <stdio.h>
#include "Listas.h"

#define pausa system("pause")
#define cls system("cls")

int main()
{
	nodo *lista1 = NULL, *lista2 = NULL, *lista3 = NULL;
	char letra;

	lista1 = insertn(lista1, 'R', 1);
	lista2 = insert1(lista2, 'o');
	lista1 = insertn(lista1, 'b', 1);
	lista2 = insert1(lista2, 'e');
	lista1 = insertn(lista1, 'r',2);
	lista1 = insertn(lista1, 't', 2);
	lista2 = insert1(lista2, 'o');

	lista3 = insert(lista3, 'S');
	
	imprimeLista(lista1);
	imprimeLista(lista2);
	imprimeLista(lista3);

	lista1 = remueve1(lista1, &letra);
	printf("Salio %c\n", letra);
	imprimeLista(lista1);


	pausa;
	cls;
	return 0;
}