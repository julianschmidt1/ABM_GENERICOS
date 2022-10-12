/*
 * Inputs.h
 *
 *  Created on: 12 Oct 2022
 *      Author: Julian
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);
int getString(char *cadena, int longitud);
int esNombre(char *cadena, int longitud);
int utn_getString(char *mensaje, char *mensajeError, int reintentos,
		int longitud, char *pResultado);
int utn_getNumeroDecimal(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

#endif /* INPUTS_H_ */
