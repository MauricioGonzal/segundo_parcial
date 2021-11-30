/*
 * libro.h
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */

#ifndef LIBRO_H_
#define LIBRO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "Editorial.h"
#include "LinkedList.h"

typedef struct{
	int id;
	char titulo[51];
	char autor[51];
	float precio;
	int idEditorial;
}Libro;

Libro* Libro_New();

Libro* Libro_NewParametros(char id[], char titulo[], char autor[], char precio[], char idEditorial[]);

int Libro_getId(Libro* this, int* id);

int Libro_setId(Libro* this, int id);

int Libro_getTitulo(Libro* this, char* titulo);

int Libro_setTitulo(Libro* this, char* titulo);

int Libro_getAutor(Libro* this, char* autor);

int Libro_setAutor(Libro* this, char* autor);

int Libro_getPrecio(Libro* this, float* precio);

int Libro_setPrecio(Libro* this, float* precio);

int Libro_getIdEditorial(Libro* this, int* idEditorial);

int Libro_setIdEditorial(Libro* this, int* idEditorial);

int cargarArchivoLibros(char* archivoCreado);

int libro_CompareByAutor(void* e1, void* e2);

int buscarMinotauro(void* element);

int altaLibro(LinkedList* listaLibros, int maxId);


int asignarDescuento(void* element);
#endif /* LIBRO_H_ */
