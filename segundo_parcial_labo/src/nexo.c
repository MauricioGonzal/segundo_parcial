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

	printf("%d, %s, %s, %.2f, ", id, titulo, autor, precio);
	for(int i=0; i<ll_len(editoriales); i++){
		editorial= ll_get(editoriales, i);
		Editorial_getId(editorial, &idEditAux);
		if( idEditorial== idEditAux){
			printf("%s\n", editorial->editorial);
			break;
		}
	}



}


 int cargarListaFiltrada(FILE* pFile, LinkedList* listaFiltrada, LinkedList* listaEditoriales){

	int retorno;
	retorno=-1;
	Libro* pLibro;
	Editorial* pEditorial;

	fprintf(pFile, "ID, TITULO, AUTOR, PRECIO, EDITORIAL\n");

	for(int i=0; i<ll_len(listaFiltrada); i++){
		pLibro= (Libro*)ll_get(listaFiltrada, i);
		for(int j=0; j<ll_len(listaEditoriales); j++){
			pEditorial= (Editorial*)ll_get(listaEditoriales, j);
			if(pEditorial->id== pLibro->idEditorial){
				break;
			}
		}
		if(pLibro!=NULL){
		fprintf(pFile, "%d, %s, %s, %f, %s\n", pLibro->id, pLibro->titulo, pLibro->autor, pLibro->precio, pEditorial->editorial);
		retorno=0;
		}
	}


	return retorno;
}
