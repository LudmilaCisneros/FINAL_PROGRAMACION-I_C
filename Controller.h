#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListS_logEntry);

int controller_ListarLinkedlist(LinkedList* pArrayListS_logEntry);
int controller_evaluarGravedad(LinkedList* pArrayListS_logEntry);
int controller_evaluarGravedadloadWarnings(LinkedList* pArrayListS_logEntry, char* path);
int controller_mostrarEstadisticas(LinkedList* pArrayListS_logEntry);

int controller_saveAsText(char* path , LinkedList* listaFiltradaGravedad);

#endif // CONTROLLER_H_INCLUDED
