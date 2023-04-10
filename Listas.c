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

//   Prototipos


 				//  Creamos una lista vacía. 

// Funciones para insertar


insert(nodo *raiz, char dato)
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
	return raiz;
}

nodo *insertn(nodo *raiz, char dato, int pos)
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
		return raiz;
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
	return raiz;
}


nodo *insert1(nodo *raiz, char dato)
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
	return nuevo;
}

//  Funciones para remover
nodo *remueve(nodo *raiz,char *dato)
{
	nodo *recorre = NULL;
	nodo *ultimo = NULL;
	
	if( raiz == NULL ) 
	{
		printf("La lista está vacía. No hay nada que remover.");
		return raiz;
	}
	recorre = raiz;
	if(recorre ->sig == NULL)
	{
		raiz = NULL;
		*dato = recorre->info;
		free(recorre);
		return raiz;
	}
	ultimo = recorre ->sig;
	while(ultimo ->sig != NULL)
	{
		ultimo = ultimo ->sig;
		recorre = recorre ->sig;
	}
	recorre ->sig = NULL;
	*dato = ultimo ->info;
	free(ultimo);
	return raiz;
}

/*char remueve1()
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

char remueven(int pos)
{
	nodo *recorre = NULL;
	nodo *elimina = NULL;
	char dato;
	int cont;
	if( raiz == NULL ) 
	{
		printf("La lista está vacía. No hay nada que remover.");
		return '\0';
	}
	recorre = raiz;
	if(pos == 1)
	{
		raiz = raiz -> sig;
		dato = recorre->info;
		free(recorre);
		return dato;
	}
	elimina = recorre ->sig;
	cont = 1;
	while( recorre->sig != NULL && cont < pos - 1 )
	{
		elimina = elimina ->sig;
		recorre = recorre ->sig;
		cont++;
	}
	if(cont < pos - 1)
	{
		printf("Error: no hay nada que borrar");
		return '\0';
	}
	recorre ->sig = elimina -> sig;
	dato = elimina ->info;
	free(elimina);
	return dato;
}*/

void imprimeLista(nodo *raiz)
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

	lista1 = remueve(lista1, &letra);
	printf("Salio %c\n", letra);
	imprimeLista(lista1);


	pausa;
	cls;
	return 0;
}