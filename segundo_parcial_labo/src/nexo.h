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

#endif /* NEXO_H_ */
