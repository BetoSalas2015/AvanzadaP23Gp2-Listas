#include <stdio.h>			//  Para la i/o del programa
#include <stdlib.h>			//  PAra las rutinas de utilería p.e. system() y exit()
#include <malloc.h>			//  Para la gestion dinámica de la memoria malloc()

#define pausa system("pause")
#define cls system("cls")

struct Nodo 
{ 
	char info;
	struct Nodo *sig;				//  el siguiente es un nodo...
};	

typedef struct Nodo nodo;

nodo *raiz = NULL;					//  Creamos una lista vacía. 

void insert(char dato)
{
	nodo *nuevo = NULL;
	nuevo = ( nodo * ) malloc( sizeof(nodo) );
	if( nuevo == NULL )
	{
		printf("Error: No hay Memoria disponible \n");
		exit(1);
	}
	nuevo ->info = dato;
	nuevo ->sig = NULL;
	if( raiz == NULL ) 
	{
		raiz = nuevo;
	}
	else
	{
		nodo *recorre = raiz;
		while( recorre->sig != NULL )
		{
			recorre = recorre -> sig;
		}
		recorre ->sig = nuevo;
	}
}

void imprimeLista()
{
	nodo *recorre = raiz;
	while( recorre != NULL )
	{
		printf("%c, ", recorre->info);
		recorre = recorre -> sig;
	}
	putchar('\n');
}

int main()
{
	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');
	
	imprimeLista();

	pausa;
	cls;
	return 0;
}