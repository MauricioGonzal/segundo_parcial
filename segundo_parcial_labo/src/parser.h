/*
 * parser.h
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"

int parser_LibroFromText(FILE* pFile, LinkedList* listaLibros);

int parser_EditorialFromText(FILE* pFile, LinkedList* listaEditoriales);

#endif /* PARSER_H_ */
