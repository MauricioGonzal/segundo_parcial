/*
 * editorial.c
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */

#include "Editorial.h"

Editorial* Editorial_new(){
	Editorial* pEditorial;
	pEditorial= (Editorial*)malloc(sizeof(Editorial));
	if(pEditorial!=NULL){
		strcpy(pEditorial->editorial,"");
		pEditorial->id=0;
	}


	return pEditorial;
}

Editorial* Editorial_newParametros(char id[], char editorial[]){
	Editorial* pEditorial;
	pEditorial= Editorial_new();
	if(pEditorial!=NULL){
		pEditorial->id= atoi(id);
		strcpy(pEditorial->editorial, editorial);
	}

	return pEditorial;
}

int Editorial_getId(Editorial* this, int* id){
	int retorno;
	retorno=-1;
	if(this!=NULL && id!=NULL){
	*id= this->id;
	retorno=0;
	}

	return retorno;
}

int Editorial_setId(Editorial* this, int* id){
	int retorno;
	retorno=-1;
	if(this!=NULL && id!=NULL){
	this->id=*id;
	retorno=0;
	}

	return retorno;
}

int Editorial_getEditorial(Editorial* this, char* editorialNombre){
	int retorno;
		retorno=-1;
		if(this!=NULL && editorialNombre!=NULL){
		strcpy(editorialNombre, this->editorial);
		retorno=0;
		}

		return retorno;
}


int Editorial_setEditorial(Editorial* this, char* editorialNombre){
	int retorno;
	retorno=-1;
	if(this!=NULL && editorialNombre!=NULL){
	strcpy(this->editorial, editorialNombre);
	retorno=0;
	}

	return retorno;
}

int cargarArchivoEditorial(char* archivoCreado){
	int retorno;
	char path[51];
	retorno=-1;
	if(getString(path, "Ingrese el archivo de editoriales que desea cargar", "error", sizeof(path))==0){
		retorno=1;
		if(strcmp(path, archivoCreado)==0){
			retorno=0;
		}
	}

	return retorno;
}
