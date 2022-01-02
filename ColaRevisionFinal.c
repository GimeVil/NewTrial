/**********************************************************Cola.H**********************************************************/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct dato {
	int dia;
	int mes;
	int anio;
	char * eventoAgendado;
}Dato;

typedef struct nodo {
	Dato elDato;
	struct nodo *siguiente;
}Nodo;

typedef struct cola {
	int cantidadNodos;
	Nodo *frente;
	Nodo *fondo;
}Cola;

		/* 1) Crear una cola.
// Precondicion:
// Entrada:
// Salida: una cola.
//Postcondicion: se crea una cola vacia*/
Cola crearCola();

		/*2) Determinar si una cola se encuentra vacía.
// Precondicion: la cola recibida debe ser válida.
// Entrada: una cola.
// Salida: un entero que determina si la cola contiene elementos (TRUE) o no (FALSE).
// Postcondicion: se determina si la cola tiene o no elementos*/
int esColaVacia(Cola laCola);

		/*3) Determinar la cantidad de elementos de la cola.
// Precondicion: la cola recibida debe ser válida.
// Entrada: una cola.
// Salida: un entero que determina cuantos elementos tiene la cola.
// Postcondicion: se sabe la cantidad de elementos de la cola*/
int cantidadElementosCola(Cola laCola);

		/*4) Agregar un nodo en la fondo de la cola.           
// Precondicion: la cola y el nodo recibido deben ser validos.
// Entrada: una cola y un nodo.
// Salida: un entero que determina si se pudo agregar el nodo recibido a la fondo de la cola (TRUE) o no (FALSE)
// Postcondicion: se agrega un nodo en la fondo de la cola*/
int encolar(Cola *laCola, Nodo *elNodo);

		/*5)Obtener el nodo de la frente de la cola.
// Precondicion: la cola recibida debe ser valida.
// Entrada: una cola.
// Salida: un nodo que es la copia del nodo que se encuentra en la frente de la cola o un nodo vacio si la cola esta vacia.
// Postcondicion: se obtiene una copia del nodo que se encuentra en la frente de la cola*/
Nodo obtenerNodoCima(Cola *laCola);

		/*6) Obtener el nodo de la fondo de la cola.
// Precondicion: la lista recibida debe ser valida.
// Entrada: una lista.
// Salida: un nodo que es la copia del nodo que se encuentra en la fondo de la cola o un nodo vacio si la cola esta vacia
// Postcondicion: se obtiene una copia del nodo que se encuentra en la fondo de la cola*/
Nodo obtenerNodoFinal(Cola *laCola);

		/*7) Eliminar el nodo de la frente de la cola.
// Precondicion: la cola recibida debe ser valida.
// Entrada: una cola.
// Salida: un entero que determina si se pudo eliminar el nodo recibido en la frente de la cola (TRUE) o no (FALSE)
// Postcondicion: se elimina un nodo en la frente de la cola*/
int desencolar(Cola *laCola);

		/*8) Destruir una cola.
// Precondicion: la cola debe ser valida.
// Entrada: una cola.
// Salida:
// Postcondicion: se elimina la cola*/
void destruirCola(Cola *laCola);

/**********************************************************PruebaCola.C**********************************************************/
//#include "Cola.h"
		/* A) Mostrar lista tipo cola.
// Precondicion: la cola recibida debe ser válida.
// Entrada: una cola.
// Salida: los elementos que componen la cola.
//Postcondicion: se visualizan los elementos que componen la cola*/
void mostrarCola(Cola miCola);

int main(int argc, char **argv)
{
	int opcion, RTA;
	Cola miCola;
	Nodo *elNodo = NULL;
	Nodo auxiliar;
	
	do{
		puts("1) Crear una cola.");
		puts("2) Determinar si la cola se encuentra vacia.");
		puts("3) Determinar la cantidad de elementos de la cola.");
		puts("4) Encolar un elemento en la cola.");
		puts("5) Obtener un elemento de la frente de la cola.");
		puts("6) Desencolar un elemento de la cola.");
		puts("7) Destruir la cola.");
		puts("8) Ver el contenido de la cola completa");
		puts("\nPRESIONE 0 PARA SALIR");
		puts("\nSeleccione su opcion: ");
		scanf("%d", &opcion);
		switch(opcion){

			case 1: /*(1) Crear una cola.*/
				miCola = crearCola();
				printf("\nCantidad de elementos %d\n", miCola.cantidadNodos);
				printf("Direccion primer nodo: %p\n\n", miCola.frente);
			break;

			case 2: /*(2) Determinar si una cola se encuentra vacía.*/
				RTA = esColaVacia(miCola);
		
				if(RTA == 1 || miCola.cantidadNodos == 0){
					puts("\nLa cola esta VACIA");
				}else{
					puts("\nTiene contenido");
				}
			break;
			
			case 3:	/*(3) Determinar la cantidad de elementos de la cola.*/
				cantidadElementosCola(miCola);
		
				printf("\nCantidad de elementos: %d\n", miCola.cantidadNodos);
			    puts("\n");				
			break;
			
			case 4: /*(4) Encolar un elemento en la cola..*/
			    elNodo = (Nodo *)malloc(sizeof(Nodo));
				/*Para ingresar datos manualmente*/
				puts("Dia: ");
				scanf("%d", &elNodo->elDato.dia);
				puts("Mes: ");
				scanf("%d", &elNodo->elDato.mes);
				puts("Anio: ");
				scanf("%d", &elNodo->elDato.anio);
		
				encolar(&miCola, elNodo);

				printf("Cantidad de elementos: %d\n", miCola.cantidadNodos);
				printf("Direccion primer nodo: %p\n", miCola.frente);
				auxiliar = obtenerNodoFinal(&miCola);
				printf("Dia: %d/%d/%d\n", auxiliar.elDato.dia, auxiliar.elDato.mes, auxiliar.elDato.anio);
			    puts("\n");
			break;
			
			case 5: /*(5)Obtener el nodo de la frente de la cola.*/
				auxiliar = obtenerNodoCima(&miCola);
				printf("Dia: %d/%d/%d\n", auxiliar.elDato.dia, auxiliar.elDato.mes, auxiliar.elDato.anio);				
			    puts("\n");
			break;
			
			case 6:	/*(6) Desencolar un elemento de la cola.*/
				desencolar(&miCola);
			    puts("\n");
			break;
			
			case 7:	/*(7) Destruir la cola.*/
				destruirCola(&miCola);
			    puts("\n");
			break;
			
			case 8: /*(8) Ver el contenido de la cola completa*/
				RTA = esColaVacia(miCola);
		
				if(RTA == 1){
					puts("La cola esta VACIA");
				}else{
					mostrarCola(miCola);
				}
			    puts("\n");
			break;	
		}
	}while(opcion != 0);
	
	free(elNodo);
	return 0;
}

		/* A) Mostrar lista tipo cola.
// Precondicion: la cola recibida debe ser válida.
// Entrada: una cola.
// Salida: los elementos que componen la cola.
//Postcondicion: se visualizan los elementos que componen la cola*/

void mostrarCola(Cola miCola){
	/*Desencolar y encolar para recorrer la cola*/
	Nodo auxiliar;
	int i = 0;
	while(i < miCola.cantidadNodos){
		auxiliar = obtenerNodoCima(&miCola);
		printf("Posicion: %d - %d/%d/%d\n", i,auxiliar.elDato.dia,auxiliar.elDato.mes,auxiliar.elDato.anio);
		desencolar(&miCola);
		i++;
		encolar(&miCola, &auxiliar);
	}
}

/**********************************************************Cola.C**********************************************************/
//#include "Cola.h"

		/* 1) Crear una cola.
// Precondicion:
// Entrada:
// Salida: una cola.
//Postcondicion: se crea una cola vacia*/
Cola crearCola(){
	Cola nuevaCola;
 
	nuevaCola.cantidadNodos = 0;
	nuevaCola.frente = NULL;
	nuevaCola.fondo = NULL;
	
	return nuevaCola;
}

		/*2) Determinar si una cola se encuentra vacía.
// Precondicion: la cola recibida debe ser válida.
// Entrada: una cola.
// Salida: un entero que determina si la cola contiene elementos (TRUE) o no (FALSE).
// Postcondicion: se determina si la cola tiene o no elementos*/
int esColaVacia(Cola laCola){
	if ((laCola.cantidadNodos == 0) && (laCola.frente == (Nodo *)NULL)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

		/*3) Determinar la cantidad de elementos de la cola.
// Precondicion: la cola recibida debe ser válida.
// Entrada: una cola.
// Salida: un entero que determina cuantos elementos tiene la cola.
// Postcondicion: se sabe la cantidad de elementos de la cola*/
int cantidadElementosCola(Cola laCola){
	return laCola.cantidadNodos;
}

		/*4) Agregar un nodo en la fondo de la cola.           
// Precondicion: la cola y el nodo recibido deben ser validos.
// Entrada: una cola y un nodo.
// Salida: un entero que determina si se pudo agregar el nodo recibido a la fondo de la cola (TRUE) o no (FALSE)
// Postcondicion: se agrega un nodo en la fondo de la cola*/

int encolar(Cola *laCola, Nodo *elNodo){
	elNodo->siguiente = NULL;
	if (esColaVacia(*laCola)) {
		laCola->frente = elNodo;
		laCola->fondo = elNodo;
		laCola->cantidadNodos++;
		return TRUE;
	} else {
		laCola->fondo->siguiente = elNodo;
		laCola->fondo = elNodo;
		laCola->cantidadNodos++;
		return TRUE;
	}
	return 0;
}

		/*5)Obtener el nodo de la frente de la cola.
// Precondicion: la cola recibida debe ser valida.
// Entrada: una cola.
// Salida: un nodo que es la copia del nodo que se encuentra en la frente de la cola o un nodo vacio si la cola esta vacia.
// Postcondicion: se obtiene una copia del nodo que se encuentra en la frente de la cola*/

Nodo obtenerNodoCima(Cola *laCola){
	Nodo primerNodo;
	if (esColaVacia(*laCola)){
		return primerNodo;
	} else {
		primerNodo.elDato.dia = laCola->frente->elDato.dia;
		primerNodo.elDato.mes = laCola->frente->elDato.mes;
		primerNodo.elDato.anio = laCola->frente->elDato.anio;
		primerNodo.siguiente = laCola->frente->siguiente;
		return primerNodo;
	}
}

		/*6) Obtener el nodo de la fondo de la cola.
// Precondicion: la lista recibida debe ser valida.
// Entrada: una lista.
// Salida: un nodo que es la copia del nodo que se encuentra en la fondo de la cola o un nodo vacio si la cola esta vacia
// Postcondicion: se obtiene una copia del nodo que se encuentra en la fondo de la cola*/
Nodo obtenerNodoFinal(Cola *laCola) {
    Nodo *ultimoNodo = NULL;
    int i;
    ultimoNodo = laCola->frente;
	if (esColaVacia(*laCola)){
		return *ultimoNodo;
	} else {
		for(i = 1; i < laCola->cantidadNodos; i++){
			ultimoNodo = ultimoNodo->siguiente;				
		}
		return *ultimoNodo;
	}
	return *ultimoNodo;
}

		/*7) Eliminar el nodo de la frente de la cola.
// Precondicion: la cola recibida debe ser valida.
// Entrada: una cola.
// Salida: un entero que determina si se pudo eliminar el nodo recibido en la frente de la cola (TRUE) o no (FALSE)
// Postcondicion: se elimina un nodo en la frente de la cola*/

int desencolar(Cola *laCola){
	Nodo *elNodo;
	if (!esColaVacia(*laCola)){
		if(laCola->cantidadNodos == 1){
			free(laCola->frente);
			laCola->cantidadNodos--;
			laCola->frente = NULL;
		}else{
			elNodo = laCola->frente->siguiente;
			free(laCola->frente);
			laCola->frente = elNodo;
			laCola->cantidadNodos--;
		}
	}
	return TRUE;
}

		/*8) Destruir una cola.
// Precondicion: la cola debe ser valida.
// Entrada: una cola.
// Salida:
// Postcondicion: se elimina la cola*/
void destruirCola(Cola *laCola){
	while(!esColaVacia(*laCola)){
		desencolar(laCola);
	}
}
