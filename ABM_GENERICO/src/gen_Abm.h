#ifndef GEN_ABM_H_
#define GEN_ABM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "menu.h"

#define MAX_CHARS_NAME 51
#define MAX_CHARS_CODE 10
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1

typedef struct {
	char name[MAX_CHARS_NAME];
	char lastName[MAX_CHARS_NAME];
	int age;

	int id;
	int isEmpty;
} eGenerico;

// ALTA -----------------------------------------
/// \brief Funcion que permite la adicion de una entidad de tipo eGenerico a un array
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \param id identificar univoco que sera asignado al eGenerico dado de alta
/// \param generico eGenerico previamente cargado
/// \return retorna 1 en caso de exito y 0 en caso de error
int abm_altaGenerico(eGenerico *lista, int tam, int id, eGenerico generico);

/// \brief Recorre un array de eGenerico, inicializando su propiedad isEmpty
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \return retorna 1 en caso de exito y cero en caso de error
int abm_inicializarGenerico(eGenerico *lista, int tam);

/// \briefFuncion que retorna un identificar univoco autoincremental
///
/// \return Valor utilizado como identificador
int abm_obtenerIdGenerico(void);
/// \brief Funcion que itera un array de eGenerico y busca un indice considero libre
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \return
int abm_obtenerIndiceLibreGenerico(eGenerico *lista, int tam);
// ENCONTRAR INDICE -----------------------------------------
/// \brief Funcion que itera un array de eGenerico, y busca el indice especificado
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \param id valor univoco que representa cada eGenerico y permite la busqueda
/// \return Retorna el indice encontrado en caso de exito, o -1 en caso de error
int abm_encontrarGenericoPorId(eGenerico *lista, int tam, int id);
// MODIFICACION -----------------------------------------
/// \brief Funcion utilizada como para mostrar el menu y realizar modificaciones
///
/// \param Generico estructura sobre la cual aplicar modificaciones
/// \return Retorna estructura con modificaciones aplicadas
eGenerico abm_modificacionGenerico(eGenerico Generico);
/// \brief Funcion que lista los usuarios y permite la seleccion de un indice para su modificacion
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \return Retorna 1 en caso de que las modificaciones sean aceptadas y 0 en caso de que se rechace o error
int abm_listadoModificacionGenerico(eGenerico lista[], int tam);
// BAJA -----------------------------------------
/// \brief Funcion que lista los usuarios y permite la seleccion de un indice para su baja
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \return Retorna 1 en caso de que las bajas sean aceptadas y 0 en caso de que se rechace o error
int abm_listadoBajaGenerico(eGenerico *lista, int tam);
/// \brief Funcion utilizada para aplicar una baja
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \param id de el eGenerico a dar de baja
/// \return Retorna 1 en caso de que la baja sea exitosa y 0 en caso de error
int abm_bajaGenerico(eGenerico *lista, int tam, int id);
// INFORMES -----------------------------------------
/// \brief Funcion que muestra los campos de un eGenerico
///
/// \param Generico estructura a mostrar
void abm_mostrarUnGenerico(eGenerico Generico);
/// \brief Funcion que muestra un listado de eGenerico
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \return Retorna 1 en caso de exito y 0 en caso de error
int abm_mostrarTodosGenerico(eGenerico *lista, int tam);
// VALIDACION -----------------------------------------
/// \brief Funcion que compara un contador de altas y bajas para comprobar si existen usuarios cargados hasta el momento
///
/// \param contadorAltas variable contador numerica
/// \param contadorBajas variable contador numerica
/// \return Retorna 1 si difiere la cantidad de altas con bajas y 0 si son iguales
int validarIngresoOpciones(int contadorAltas, int contadorBajas);
// ORDENAMIENTO
/// \brief Funcion que ordena eGenerico por ID
///
/// \param lista array de eGenerico
/// \param tam tamaño del array de eGenerico
/// \return retorna 1 en caso de exito y 0 en caso de error
int ordenarJugadoresId(eGenerico *lista, int tam);

#endif /* GEN_ABM_H_ */
