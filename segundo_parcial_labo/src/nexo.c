/*
 * nexo.c
 *
 *  Created on: 29 nov. 2021
 *      Author: Mauri
 */
#include "nexo.h"

int ListLibros(LinkedList* listaLibros, LinkedList* editoriales){
	int retorno;
	Libro* pLibro;
	retorno=-1;
	for(int i=0; i<ll_len(listaLibros); i++){
		pLibro= ll_get(listaLibros, i);
		listOneLibro(pLibro, editoriales);


	}

	return retorno;
}

void listOneLibro(Libro* this, LinkedList* editoriales){

	int id;
	char titulo[51];
	char autor[51];
	float precio;
	int idEditorial;
	int idEditAux;
	Editorial* editorial;

	Libro_getId(this, &id);
	Libro_getTitulo(this, titulo);
	Libro_getAutor(this, autor);
	Libro_getPrecio(this, &precio);
	Libro_getIdEditorial(this, &idEditorial);

	printf("%d, %s, %s, %.2f", id, titulo, autor, precio);
	for(int i=0; i<ll_len(editoriales); i++){
		editorial= ll_get(editoriales, i);
		Editorial_getId(editorial, &idEditAux);
		if( idEditorial== idEditAux){
			printf("%s\n", editorial->editorial);
			break;
		}
	}



}
