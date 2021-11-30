/*
 * editorial.h
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

typedef struct{
	int id;
	char editorial[51];
}Editorial;

Editorial* Editorial_new();

Editorial* Editorial_newParametros(char id[], char editorial[]);

int Editorial_getId(Editorial* this, int* id);

int Editorial_setId(Editorial* this, int* id);

int Editorial_getEditorial(Editorial* this, char* editorialNombre);

int Editorial_setEditorial(Editorial* this, char* editorialNombre);

int cargarArchivoEditorial(char* archivoCreado);

#endif /* EDITORIAL_H_ */
