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

/*1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro. ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial. ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros. ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
Detalle de la función “ll_filter()”
Prototipo de la función:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
agregará a la misma los ítems correspondientes y la devolverá.

Datos:
eLibro:
• id
• titulo
• autor
• precio
• idEditorial
eEditorial:
• idEditorial
• nombre
Las editoriales con las que trabajaremos son las siguientes. Deberán generar un archivo csv con
estos datos.
1 - PLANETA
2 - SIGLO XXI EDITORES
3 - PEARSON
4 - MINOTAURO
5 - SALAMANDRA
6 - PENGUIN BOOKS
Los datos de los libros los generarán ustedes. deberán ser los suficientes como para probar las
distintas opciones del menú.
NOTAS:
Nota 0: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las
reglas de estilo de la cátedra.
Nota 1: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Nota 2: Se deberán utilizar las bibliotecas LinkedList, Libro y Editorial (desarrollando las funciones setter y getter
necesarias).
Nota 3: Los datos (editoriales y libros) deberán estar en listas separadas, realizando las relaciones
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



