/*
 ============================================================================
 Name        : segundo_parcial_labo.c
 Author      : mauricio gonzalez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "controller.h"
#include "input.h"

/*1. Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades eLibro. ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de comandos.
2. Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades eEditorial. ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de comandos.
3. Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de ordenamiento �Autor� de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros. ACLARACI�N: Se deber� imprimir la descripci�n de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber� utilizar la funci�n ll_filter* del LinkedList. Guardar el listado en un archivo csv.
Detalle de la funci�n �ll_filter()�
Prototipo de la funci�n:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La funci�n �ll_filter� recibir� una lista y una funci�n criterio �fn�. Se deber� iterar todos los elementos
de la lista y pasarlos a la funci�n �fn�. La funci�n �fn� devolver� 1 si ese �tem se debe agregar a la
lista resultado o 0 si no debe agregarse. La funci�n �ll_filter� generar� la nueva lista resultado,
agregar� a la misma los �tems correspondientes y la devolver�.

Datos:
eLibro:
� id
� titulo
� autor
� precio
� idEditorial
eEditorial:
� idEditorial
� nombre
Las editoriales con las que trabajaremos son las siguientes. Deber�n generar un archivo csv con
estos datos.
1 - PLANETA
2 - SIGLO XXI EDITORES
3 - PEARSON
4 - MINOTAURO
5 - SALAMANDRA
6 - PENGUIN BOOKS
Los datos de los libros los generar�n ustedes. deber�n ser los suficientes como para probar las
distintas opciones del men�.
NOTAS:
Nota 0: El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar las
reglas de estilo de la c�tedra.
Nota 1: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Nota 2: Se deber�n utilizar las bibliotecas LinkedList, Libro y Editorial (desarrollando las funciones setter y getter
necesarias).
Nota 3: Los datos (editoriales y libros) deber�n estar en listas separadas, realizando las relaciones
correspondientes entre las entidades.
Nota 4: Utilizar MVC (modelo vista controlador)*/

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcionSalida;
	opcionSalida=0;

	LinkedList* listaLibros= ll_newLinkedList();
	LinkedList* listaEditoriales= ll_newLinkedList();

	if(listaLibros!=NULL && listaEditoriales!=NULL){
	do{
		Menu();
		if(PedirYValidarNumeroMejorado("\nIngrese una opcion", &opcion, 1, 6, 5)!=0){
			opcionSalida=1;
		}
		switch(opcion){
		case 1:
			if(controller_LoadLibros(listaLibros, "libros.csv")==0){
				printf("\nel archivo se ha cargado correctamente\n");
			}
			break;
		case 2:
			if(controller_LoadEditoriales(listaEditoriales, "editoriales.csv")==0){
				printf("\nEl archivo se ha cargado correctamente\n");
			}
			break;
		case 3:
			if(controller_sortLibros(listaLibros)==0){
				printf("\nLa lista ha sido ordenada exitosamente\n");
			}
			printf("ID, TITULO, AUTOR, PRECIO, EDITORIAL");

			break;
		case 4:
			if(controller_ListLibros(listaLibros, listaEditoriales)==0){
				printf("Operacion realizada exitosamente");
			}
			break;
		case 5:
			controller_FiltrarLista(listaLibros);
			break;
		case 6:
			opcionSalida= SalirDelPrograma();
			break;
		}

	}while(opcionSalida!=1);


	}
	return EXIT_SUCCESS;
}



