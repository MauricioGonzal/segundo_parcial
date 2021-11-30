/*
 * controller.c
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */

#include "controller.h"


int controller_LoadLibros(LinkedList* listaLibros, char* path){
	int retorno;
	FILE* pFile;
	retorno=-1;
	if(listaLibros!=NULL && path!=NULL){
		retorno=1;
		if(cargarArchivoLibros(path)==0){
			pFile= fopen(path, "r");
			if(pFile!=NULL && parser_LibroFromText(pFile, listaLibros)==0){
				retorno=0;
			}
			fclose(pFile);
		}
		else{
			printf("No existe el archivo ingresado. Verifique los datos");
		}
	}

	return retorno;
}

int controller_LoadEditoriales(LinkedList* listaEditoriales, char* path){
	int retorno;
	retorno=-1;
	FILE* pFile;
	if(listaEditoriales!=NULL && path!=NULL){
		retorno=1;
		if(cargarArchivoEditorial(path)==0){
			pFile= fopen(path, "r");
			if(pFile!=NULL && parser_EditorialFromText(pFile, listaEditoriales)==0){
				retorno=0;

			}
			fclose(pFile);
		}
		else{
			printf("No existe el archivo ingresado. Verifique los datos\n");
		}

	}

	return retorno;
}

int controller_sortLibros(LinkedList* listaLibros){
	int retorno;
	retorno=-1;

	if(listaLibros!=NULL){
		retorno=1;
		if(ll_sort(listaLibros, libro_CompareByAutor, 1)==0){
			retorno=0;
		}
	}

	return retorno;
}

int controller_ListLibros(LinkedList* listaLibros, LinkedList* listaEditoriales){
	int retorno;
	retorno=-1;

	if(ListLibros(listaLibros, listaEditoriales)==0){

	}

	return retorno;
}

int controller_FiltrarLista(LinkedList* listaLibros){
	int retorno;
	retorno=-1;

	if(ll_filter(listaLibros, buscarMinotauro)==0){
		retorno=0;
	}

	return retorno;
}
