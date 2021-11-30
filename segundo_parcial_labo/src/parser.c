/*
 * parser.c
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */

#include "parser.h"

int parser_LibroFromText(FILE* pFile, LinkedList* listaLibros){
	int retorno;
	Libro* pLibro;
	char id[10];
	char titulo[51];
	char autor[51];
	char precio[10];
	char idEditorial[10];
	retorno=-1;

	if(pFile!=NULL && listaLibros!=NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
		retorno=1;

	while(!feof(pFile)){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
		pLibro= Libro_NewParametros(id, titulo, autor, precio, idEditorial);

		if(pLibro!=NULL){
			retorno=0;
			ll_add(listaLibros, pLibro);
		}
	}
	}

	return retorno;
}

int parser_EditorialFromText(FILE* pFile, LinkedList* listaEditoriales){
	int retorno;
	Editorial* pEditorial;
	retorno=-1;
	char id[10];
	char editorial[51];

	if(pFile!=NULL && listaEditoriales!=NULL){
		fscanf(pFile, "%[^,],%[^\n]\n", id, editorial);
		retorno=1;

		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^\n]\n", id, editorial);
			pEditorial= Editorial_newParametros(id, editorial);

			if(pEditorial!=NULL){
				retorno=0;


				ll_add(listaEditoriales, pEditorial);
			}
		}

	}

	return retorno;
}
