#include <stdio.h>			//  Para la i/o del programa
#include <stdlib.h>			//  PAra las rutinas de utilería p.e. system() y exit()
#include <malloc.h>			//  Para la gestion dinámica de la memoria malloc()

#define pausa system("pause")
#define cls system("cls")

//   Prototipos
void insert(char dato);
void insert1(char dato);
void insertn(char dato, int pos);
char remueve();
void imprimeLista();

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

void insertn(char dato, int pos)
{
	int cont;
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
		return;
	}
	if( pos == 1) 
	{
		nuevo -> sig = raiz;
		raiz = nuevo;
	}
	else
	{
		nodo *recorre = raiz;
		cont = 1;
		while( recorre->sig != NULL && cont < pos - 1)
		{
			recorre = recorre -> sig;
			cont++;
		}
		nuevo -> sig = recorre -> sig;
		recorre ->sig = nuevo;
	}
}


void insert1(char dato)
{
	nodo *nuevo = NULL;
	nuevo = ( nodo * ) malloc( sizeof(nodo) );
	if( nuevo == NULL )
	{
		printf("Error: No hay Memoria disponible \n");
		exit(1);
	}
	nuevo ->info = dato;
	nuevo ->sig = raiz;
	raiz = nuevo;
}

//  Funciones para remover
char remueve()
{
	nodo *recorre = NULL;
	nodo *ultimo = NULL;
	char dato;
	if( raiz == NULL ) 
	{
		printf("La lista está vacía. No hay nada que remover.");
		return '\0';
	}
	recorre = raiz;
	if(recorre ->sig == NULL)
	{
		raiz = NULL;
		dato = recorre->info;
		free(recorre);
		return dato;
	}
	ultimo = recorre ->sig;
	while(ultimo ->sig != NULL)
	{
		ultimo = ultimo ->sig;
		recorre = recorre ->sig;
	}
	recorre ->sig = NULL;
	dato = ultimo ->info;
	free(ultimo);
	return dato;
}

char remueve1()
{
	nodo *elimina = NULL;
	char dato;
	if( raiz == NULL ) 
	{
		printf("La lista está vacía. No hay nada que remover.");
		return '\0';
	}
	elimina = raiz;
	raiz = raiz ->sig;			//  raiz = elimina -> sig
	dato = elimina->info;
	free(elimina);
	return dato;
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

	insertn('x',3);
	imprimeLista();

	insertn('y', 50);
	imprimeLista();

	printf("El dato que salio: %c\n", remueve1());
	imprimeLista();

	pausa;
	cls;
	return 0;
}