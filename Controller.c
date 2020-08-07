#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Controller.h"
#include "S_logentry.h"
#include "Parser.h"

/** \brief Carga los datos de los logs desde el archivo LOG.csv (modo texto).
 * \param path char*
 * \param pArrayListS_logEntry LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListS_logEntry)
{
	int returnAux = -1;
	FILE* pFile;

	pFile = fopen(path,"r");

	if(path!=NULL && pArrayListS_logEntry != NULL)
	{
		parser_S_logEntryFromText(pFile, pArrayListS_logEntry);
		returnAux = 0;
	}
	else
	{
		printf("El archivo no fue abierto");
	}

	fclose(pFile);

	return returnAux;
}
/** \brief imprimir toda la linkedlist
 * \param
 * \param
 * \return
 *
 */
int controller_ListarLinkedlist(LinkedList* pArrayListS_logEntry)
{
    int ret = -1;
	int i;
	S_logEntry* this;

	if(pArrayListS_logEntry != NULL)
	{
		printf("\n%4s %14s %21s %20s %20s\n","FECHA","HORA","NOMBRE SERVICIO","GRAVEDAD","MENSAJE DE ERROR");

		for(i=0;i<ll_len(pArrayListS_logEntry);i++)
		{
			this = ll_get(pArrayListS_logEntry,i);//obtengo el nodo a imprimir
			printf("%4s %10s %25s %15d %20s\n",this->date,this->time,this->serviceName,this->gravedad,this->msg);
		}
		ret = 0;
	}
    return ret;
}
/** \brief Evalua la gravedad(punto 2 procesar informacion)
 *
 * \param LinkedList* pArrayListS_logEntry
 * \param
 * \return
 *
 */

int controller_evaluarGravedad(LinkedList* pArrayListS_logEntry)
{
    int ret = -1;

    LinkedList* auxListaFiltradaGravedad = ll_newLinkedList();

    if(pArrayListS_logEntry != NULL && ll_len(pArrayListS_logEntry)>= 0 && auxListaFiltradaGravedad != NULL)
    {
        auxListaFiltradaGravedad = ll_filter(pArrayListS_logEntry, s_logEntry_filtrarGMenor3);//elimino todos los errores gravedad3
        printf("\nLISTAR TODOS LOS LOGS MENOS LOS MENORES DE GRAVEDAD 3\n");
        controller_ListarLinkedlist(auxListaFiltradaGravedad);

        auxListaFiltradaGravedad = ll_filter(pArrayListS_logEntry, s_logEntry_filtrarGIgualA3);//mostrar lista en warnings.txt
        controller_saveAsText("warnings.txt",auxListaFiltradaGravedad);

        auxListaFiltradaGravedad = ll_filter(pArrayListS_logEntry, s_logEntry_filtrarGentre4y7);//imprimo esto por pantallaG4y7
        printf("\nLISTAR TODOS LOS LOGS ENTRE GRAVEDAD 4 Y 7(inclusive)\n");
        controller_ListarLinkedlist(auxListaFiltradaGravedad);

        auxListaFiltradaGravedad = ll_filter(pArrayListS_logEntry, s_logEntry_filtrarGMayorA7);//Se copiaran los msj de error a errors.txt
        controller_saveAsText("errors.txt",auxListaFiltradaGravedad);

        ret = 0;
    }



    return ret;
}

/** \brief Mostrar estadisticas
 *
 * \param
 * \param
 * \return
 *
 */
int controller_mostrarEstadisticas(LinkedList* pArrayListS_logEntry)
{
    int ret = -1;
    LinkedList* auxListaFiltradaGravedad = ll_newLinkedList();

    if(pArrayListS_logEntry != NULL && auxListaFiltradaGravedad != NULL)
    {
        printf("\nCANTIDAD DE LOGS CON GRAVEDAD MENOR A 3: %d", ll_count(pArrayListS_logEntry,s_logEntry_filtrarGEsMenor3));
        printf("\nCANTIDAD DE LOGS CON GRAVEDAD IGUAL A 3: %d", ll_count(pArrayListS_logEntry,s_logEntry_filtrarGIgualA3));
        printf("\nCANTIDAD DE LOGS CON GRAVEDAD ENTRE 4 Y 7(INCLUSIVE): %d", ll_count(pArrayListS_logEntry,s_logEntry_filtrarGentre4y7));
        printf("\nCANTIDAD DE LOGS CON GRAVEDAD MAYOR 7(INCLUSIVE): %d", ll_count(pArrayListS_logEntry,s_logEntry_filtrarGMayorA7));

        ret = 0;
    }

    return ret;
}


/** \brief Guarda los datos de los logs en el archivo que corresponda.
 *
 * \param path char*
 * \param  LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* listaFiltradaGravedad)
{
	int ret = -1;
	int i;
	S_logEntry* this;
	FILE* pFile = NULL;

	pFile = fopen(path,"w");

	if(pFile != NULL && listaFiltradaGravedad != NULL && ll_len(listaFiltradaGravedad) > 0)
	{
		fprintf(pFile,"\n%4s %14s %21s %20s %20s\n","FECHA","HORA","NOMBRE SERVICIO","GRAVEDAD","MENSAJE DE ERROR");

		for(i=0;i<ll_len(listaFiltradaGravedad);i++)
		{
			this = ll_get(listaFiltradaGravedad,i);//obtengo un log

			if(this != NULL)
			{
				fprintf(pFile,"%4s %10s %25s %15d %20s\n",this->date,this->time,this->serviceName,this->gravedad,this->msg);
			}
		}
		ret = 0;
	}

	fclose(pFile);


    return ret;
}
