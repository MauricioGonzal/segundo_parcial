/*
 * nexo.h
 *
 *  Created on: 29 nov. 2021
 *      Author: Mauri
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "Libro.h"
#include "Editorial.h"

void listOneLibro(Libro* this, LinkedList* editoriales);

int ListLibros(LinkedList* listaLibros, LinkedList* editoriales);

int cargarListaFiltrada(FILE* pFile, LinkedList* listaFiltrada, LinkedList* listaEditoriales);

int cargarListaMapeada(FILE* pFile, LinkedList* listaMapeada, LinkedList* listaEditoriales);

#endif /* NEXO_H_ */
