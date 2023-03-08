#include <stdio.h>			//  Para la i/o del programa
#include <stdlib.h>			//  PAra las rutinas de utilería p.e. system()
#include <malloc.h>			//  Para la gestion dinámica de la memoria

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
	nuevo ->info = dato;
}


int main()
{

	pausa;


	cls;
	return 0;
}