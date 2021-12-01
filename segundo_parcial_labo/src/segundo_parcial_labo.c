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
#include "nexo.h"
#define ARCHIVOSINCARGAR "Para realizar esta opcion debe cargar el archivo de libros y el archivo editoriales en el sistema\n"

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
Nota 4: Utilizar MVC (modelo vista controlador)

parte 2:

Desarrollar la funci�n ll_map en la biblioteca linkedList, la cual recibir� la lista y una funci�n.
La funci�n ll_map ejecutar� la funci�n recibida como par�metro por cada �tem de la lista, de
este modo se realizar�n descuentos a los precios seg�n se detalla:
* PLANETA: 20% (si el monto es mayor o igual a $300)
* SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
Agregar la siguiente opcion al men� de usuarios:
6. Generar el archivo de salida �mapeado.csv� luego de aplicar la funci�n map.*/

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int opcionSalida;
	int banderaLibros;
	int banderaEditoriales;
	int banderaCargaMap;
	banderaEditoriales=1;
	banderaLibros=1;
	banderaCargaMap=1;

	opcionSalida=0;

	LinkedList* listaLibros= ll_newLinkedList();
	LinkedList* listaEditoriales= ll_newLinkedList();
	LinkedList* listaFiltrada= ll_newLinkedList();
	LinkedList* listaMapeada;

	if(listaLibros!=NULL && listaEditoriales!=NULL){
	do{
		Menu();
		if(PedirYValidarNumeroMejorado("\nIngrese una opcion", &opcion, 1, 7, 5)!=0){
			opcionSalida=1;
		}
		switch(opcion){
		case 1:
			if(banderaLibros==1){

			if(controller_LoadLibros(listaLibros, "libros.csv")==0){
				printf("\nEl archivo se ha cargado correctamente\n");
				banderaLibros=0;
			}
			else{
				if(banderaLibros==0){
				printf("el archivo ya se encuentra cargado\n");
				}
			}
			}
			break;
		case 2:
			if(banderaEditoriales==1){
			if(controller_LoadEditoriales(listaEditoriales, "editoriales.csv")==0){
				printf("\nEl archivo se ha cargado correctamente\n");
				banderaEditoriales=0;
			}
			}
			else{
				if(banderaEditoriales==0){
				printf("el archivo ya se encuentra cargado\n");
				}
			}
			break;

		case 3:
			if(banderaLibros==0 && banderaEditoriales==0){
			if(controller_sortLibros(listaLibros)==0){
				printf("\nLa lista ha sido ordenada exitosamente\n");
			}
			}
			else{
				printf(ARCHIVOSINCARGAR);
			}


			break;
		case 4:
			if(banderaLibros==0 && banderaEditoriales==0){
			printf("ID, TITULO, AUTOR, PRECIO, EDITORIAL");
			if(controller_ListLibros(listaLibros, listaEditoriales)==0){
				printf("Operacion realizada exitosamente");
			}
			}
			else{
				printf(ARCHIVOSINCARGAR);
			}
			break;
		case 5:
			if(banderaLibros==0 && banderaEditoriales==0){
			if(controller_FiltrarLista(listaLibros, listaFiltrada)!=NULL){
				printf("Operacion realizada exitosamente\n");
				listaFiltrada= controller_FiltrarLista(listaLibros, listaFiltrada);
				ListLibros(listaFiltrada, listaEditoriales);
				printf("Guardando lista en archivo...\n");
				VerificarTresRetornos(controller_CargarListaFiltradaEnCsv(listaFiltrada, listaEditoriales), "GUARDADO\n", "Error en la carga del archivo", "ERROR");


			}
			}
			else{
				printf(ARCHIVOSINCARGAR);
			}


			break;
		case 6:
			if(banderaEditoriales==0 && banderaLibros==0 && banderaCargaMap==1){
			if(controller_Map(listaMapeada, listaLibros)!=NULL){
				listaMapeada= controller_Map(listaMapeada, listaLibros);
				if(controller_CargarListaMapeadaEnCsv(listaMapeada, listaEditoriales)==0){
				banderaCargaMap=0;
				printf("\nArchivo mapeado.csv guardado exitosamente\n");
				}
			}
			}
			else{
				printf("ERROR. Verifique los datos ingresados");
			}
			break;
		case 7:
			opcionSalida= SalirDelPrograma();
			break;
		}

	}while(opcionSalida!=1);

	}

	return EXIT_SUCCESS;
}



