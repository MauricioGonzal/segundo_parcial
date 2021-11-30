/*
 * input.c
 *
 *  Created on: 6 nov. 2021
 *      Author: Mauri
 */

#include "input.h"

/*
 * input.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Mauri
 */

#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getString(char* cadena, char* mensaje, char* mensajeError, int longitud){
	int retorno=-1;
	char bufferString[4096];
	printf("%s", mensaje);
	if(cadena!= NULL && longitud>0){
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin)!= NULL){
			if(bufferString[strlen(bufferString)-1]== '\n'){
				bufferString[strlen(bufferString)-1]='\0';
			}
			if(strlen(bufferString)<= longitud){
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
			else{

				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

float LoadFloat(char message[]){
    float option;
    printf("%s", message);
    scanf("%f", &option);
    while(option <0)
    {
    printf("\nERROR.%s", message);
    scanf("%f", &option);
    }
    return option;
}

int LoadInt(char message[]){
    int option;
    printf("%s\n", message);
    scanf("%d", &option);

    return option;
}

int LoadIntRange(char message[], int* opcion, int num){
	int retorno;
	int option;
    if(message!=NULL && opcion!= NULL){
	printf("%s", message);
    scanf("%d", &option);
    *opcion= option;
    while(option <0 || option > num){
        printf("\nERROR.%s", message);
        scanf("%d", &option);
        }
    retorno=0;
    }
    return retorno;
}

void LoadString(char message[], char loadedString[]){


	printf("%s\n", message);
    fflush(stdin);
    scanf("%[^\n]", loadedString);

}

int LoadStringValidado(char message[], char loadedString[]){
    char buffer[51];
    int retorno;
    retorno=0;
	printf("%s\n", message);
    fflush(stdin);
    scanf("%[^\n]", buffer);

    for(int i=0;i<strlen(buffer); i++){
    	if(isdigit(buffer[i])!=0){
    		retorno=-1;
    		break;
    	}
    }
    if(retorno==0){
    strcpy(loadedString, buffer);
    }

    return retorno;
}

int SalirDelPrograma(){
	int opcion;
	printf("seguro desea salir del programa?\n1.SI\n2.NO");
	scanf("%d", &opcion);

	return opcion;
}

void VerificacionRetorno(int retorno, char mensajeCorrecto[], char mensajeError[]){

	if(retorno==0){
		printf("%s", mensajeCorrecto);
	}
	else{
		if(retorno==-1){
		printf("%s", mensajeError);
	}
	}
}

void VerificarTresRetornos(int retorno, char mensajeCorrecto[], char mensajeNoExiste[], char mensajeError[]){

	if(retorno==0){
			printf("%s", mensajeCorrecto);
		}
		else{
			if(retorno==1){
				printf("%s", mensajeNoExiste);
			}
			else{
			printf("%s", mensajeError);
		}
		}
}



void Menu(){
	printf("MENU\n1. Ingrese el archivo de libros que desea cargar\n2. Ingrese el archivo de editoriales que desea cargar\n3.Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de "
			"ordenamiento “Autor” de manera ascendente.\n4.Imprimir por pantalla todos los datos de los libros.\n5.Realizar un listado de los libros de la editorial MINOTAURO\n6.SALIR");
}

int ValidarNumero(char numeros[]){
	int retorno=0;
	for(int i=0;i<strlen(numeros);i++){
		if(isdigit(numeros[i])==0){
			printf("\nEl dato ingresado no es numerico");
			retorno=-1;
			break;
		}
	}
	return retorno;

}

int validarRango(int numero, int minimo, int maximo){
	int retorno;
	retorno=0;

	if(numero>maximo || numero<minimo){
		printf("el numero esta fuera de rango");
		retorno=-1;
	}

	return retorno;
}

int PedirYValidarNumero(char mensaje[], int* numeroConvertido, int reintentos){
	int retorno;
	char buffer[11];
	retorno=-1;
	do{
		reintentos--;
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		if(ValidarNumero(buffer)==0)
		{
			retorno=1;

			*numeroConvertido= atoi(buffer);
			retorno=0;

		}
	}while(retorno!=0 && reintentos>0);

	return retorno;

}

int PedirYValidarNumeroFlotante(char mensaje[], float* numeroConvertido, int reintentos){
	int retorno;
	char buffer[11];
	retorno=-1;
	do{
		reintentos--;
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		if(ValidarNumeroFlotante(buffer)==0)
		{
			retorno=1;

			*numeroConvertido= atoi(buffer);
			retorno=0;

		}
	}while(retorno!=0 && reintentos>0);

	return retorno;

}

int ValidarNumeroFlotante(char numeros[]){
	int retorno=0;
	int banderaComa;
	banderaComa=0;
	for(int i=0;i<strlen(numeros);i++){
		if(banderaComa==0 && numeros[i]=='.'){
			banderaComa=1;
		}
		if(!isdigit(numeros[i])||(numeros[i]=='.' && banderaComa==1)){
			printf("\nEl dato ingresado no es valido.\n");
			retorno=-1;
			break;
		}
	}
	return retorno;

}

int PedirYValidarNumeroMejorado(char mensaje[], int* numeroConvertido, int min, int max, int reintentos){
	int retorno;
	char buffer[11];
	retorno=-1;
	do{
		reintentos--;
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%[^\n]", buffer);

		if(ValidarNumero(buffer)==0)
		{
			retorno=1;

			*numeroConvertido= atoi(buffer);
			if(validarRango(*numeroConvertido, min, max)==0){
				retorno=0;
			}

		}
	}while(retorno!=0 && reintentos>0);

	return retorno;

}

