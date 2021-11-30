/*
 * input.h
 *
 *  Created on: 28 nov. 2021
 *      Author: Mauri
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getString(char* cadena, char* mensaje, char* mensajeError, int longitud);
float LoadFloat(char message[]);
int LoadInt(char message[]);
int LoadIntRange(char message[], int* opcion, int num);
void LoadString(char message[], char loadedString[]);
int SalirDelPrograma();
void VerificacionRetorno(int retorno, char mensajeCorrecto[], char mensajeError[]);
void VerificarTresRetornos(int retorno, char mensajeCorrecto[], char mensajeNoExiste[], char mensajeError[]);
void Menu ();
int ordenarArrayInt(int* pArray, int limite);
int ValidarNumero(char numeros[]);
int LoadStringValidado(char message[], char loadedString[]);
int PedirYValidarNumero(char mensaje[], int* numeroConvertido, int reintentos);
int ValidarNumeroFlotante(char numeros[]);
int PedirYValidarNumeroFlotante(char mensaje[], float* numeroConvertido, int reintentos);
int PedirYValidarNumeroMejorado(char mensaje[], int* numeroConvertido, int min, int max, int reintentos);
int validarRango(int numero, int minimo, int maximo);

#endif /* INPUT_H_ */


