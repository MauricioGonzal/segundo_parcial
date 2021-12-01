/*
 * libro.c
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */


#include "Libro.h"


Libro* Libro_New(){


	Libro* libro= NULL;
	libro= (Libro*)malloc(sizeof(Libro));
	if(libro!=NULL){
		Libro_setId(libro, 0);
		Libro_setTitulo(libro, "");
		Libro_setAutor(libro, "");
		Libro_setPrecio(libro, 0);
		Libro_setIdEditorial(libro, 0);

	}
	return libro;
}

Libro* Libro_NewParametros(char id[], char titulo[], char autor[], char precio[], char idEditorial[]){
	Libro* pLibro= Libro_New();
	if(titulo!=NULL && autor!=NULL && pLibro!=NULL){
		pLibro->id= atoi(id);
		strcpy(pLibro->titulo, titulo);
		strcpy(pLibro->autor, autor);
		pLibro->precio= atof(precio);
		pLibro->idEditorial= atoi(idEditorial);
	}

	return pLibro;
}

int Libro_getId(Libro* this, int* id){
	int retorno;
	retorno=-1;
	if(this!=NULL && id!=NULL){
	*id= this->id;
	retorno=0;
	}

	return retorno;
}

int Libro_setId(Libro* this, int id){
	int retorno;
	retorno=-1;
	if(this!=NULL){
	this->id= id;
	retorno=0;
	}

	return retorno;
}

int Libro_getTitulo(Libro* this, char* titulo){
	int retorno;
		retorno=-1;
		if(this!=NULL && titulo!=NULL){
		strcpy(titulo, this->titulo);
		retorno=0;
		}

		return retorno;
}


int Libro_setTitulo(Libro* this, char* titulo){
	int retorno;
		retorno=-1;
		if(this!=NULL){
		strcpy(this->titulo, titulo);
		retorno=0;
		}

		return retorno;
}

int Libro_getAutor(Libro* this, char* autor){
	int retorno;
		retorno=-1;
		if(this!=NULL && autor!=NULL){
		strcpy(autor, this->autor);
		retorno=0;
		}

		return retorno;
}

int Libro_setAutor(Libro* this, char* autor){
	int retorno;
		retorno=-1;
		if(this!=NULL && autor!=NULL){
		strcpy(this->autor, autor);
		retorno=0;
		}

		return retorno;
}

int Libro_getPrecio(Libro* this, float* precio){
	int retorno;
	retorno=-1;
	if(this!=NULL && precio!=NULL){
	*precio= this->precio;
	retorno=0;
	}

	return retorno;
}

int Libro_setPrecio(Libro* this, float* precio){
	int retorno;
	retorno=-1;
	if(this!=NULL && precio!=NULL){
	this->precio=*precio;
	retorno=0;
	}

	return retorno;
}

int Libro_getIdEditorial(Libro* this, int* idEditorial){
	int retorno;
	retorno=-1;
	if(this!=NULL && idEditorial!=NULL){
	*idEditorial= this->idEditorial;
	retorno=0;
	}

	return retorno;
}


int Libro_setIdEditorial(Libro* this, int* idEditorial){
	int retorno;
	retorno=-1;
	if(this!=NULL && idEditorial!=NULL){
	this->idEditorial=*idEditorial;
	retorno=0;
	}

	return retorno;
}

int cargarArchivoLibros(char* archivoCreado){
	int retorno;
	char path[51];
	retorno=-1;
	if(getString(path, "Ingrese el archivo de libros que desea cargar", "error", sizeof(path))==0){
		retorno=1;
		if(strcmp(path, archivoCreado)==0){
			retorno=0;
		}
	}

	return retorno;
}

int libro_CompareByAutor(void* e1, void* e2){
	int retorno;
	Libro* unLibro;
	Libro* otroLibro;
	retorno=0;
	unLibro= (Libro*)e1;
	otroLibro= (Libro*)e2;
	if(e1!=NULL && e2!=NULL){
		if(strcmp(unLibro->autor, otroLibro->autor)>0){
			retorno=1;
		}
		else{
			if(strcmp(unLibro->autor, otroLibro->autor)<0){
				retorno=-1;
			}
		}
	}
	return retorno;

}


int buscarMinotauro(void* element){
	int retorno;
	Libro* elLibro;
	int idEditorial;
	elLibro= (Libro*) element;
	retorno=0;
	Libro_getIdEditorial(elLibro, &idEditorial);

	if(idEditorial==4){
		retorno=1;
	}

	return retorno;
}


int asignarDescuento(void* element){
	int retorno;

	Libro* pLibro;
	pLibro= (Libro*) element;
	retorno=-1;

	if(element!=NULL){
		retorno=0;
	if(pLibro->idEditorial==1 && pLibro->precio>=5000){

		pLibro->precio= (pLibro->precio) - ((20*pLibro->precio)/100);


	}
	else{
		if(pLibro->idEditorial==2 && pLibro->precio<=4000){
			pLibro= (Libro*) element;
			pLibro->precio= (pLibro->precio) - ((10*pLibro->precio)/100);
		}
	}
	}


	return retorno;
}
