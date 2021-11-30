/*
 * controller.h
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Libro.h"
#include "parser.h"
#include "Editorial.h"
#include "nexo.h"

int controller_LoadLibros(LinkedList* listaLibros, char* path);

int controller_LoadEditoriales(LinkedList* listaEditoriales, char* path);

int controller_sortLibros(LinkedList* listaLibros);

int controller_ListLibros(LinkedList* listaLibros, LinkedList* listaEditoriales);

LinkedList* controller_FiltrarLista(LinkedList* listaLibros, LinkedList* listaFiltrada);

int controller_CargarListaFiltradaEnCsv(LinkedList* listaFiltrada, LinkedList* listaEditoriales);

#endif /* CONTROLLER_H_ */
