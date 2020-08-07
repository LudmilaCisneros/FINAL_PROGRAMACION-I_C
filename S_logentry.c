#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "S_logentry.h"

/*static int lastId=0;

void s_logentry_idInit(int id)
{
    lastId=id+1;
}

int s_logentry_idGenerator()
{
    return lastId++;
}

int s_logentry_setIdStr(S_logEntry* this,char* idStr)
{
    int ret=-1;
    int bufferId;
    if(this!=NULL && idStr!=NULL)
    {
        if(utn_isValidInt(idStr))
        {
            bufferId = atoi(idStr);
            if(!s_logentry_setId(this,bufferId))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int s_logentry_setId(S_logEntry* this,int id)
{
    int ret=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        ret=0;
    }
    return ret;
}

int s_logentry_getId(S_logEntry* this,int* id)
{
    int ret=-1;
    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        ret=0;
    }
    return ret;
}
*/

/*
int s_logEntry_compareId(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(((S_logEntry*)pElementA)->id > ((S_logEntry*)pElementB)->id)
    {
        ret = 1;
    }
    if(((S_logEntry*)pElementA)->id < ((S_logEntry*)pElementB)->id)
    {
        ret = -1;
    }
    return ret;
}*/

/** \brief crear un espacio en la memoria para un log
 *
 * \param void
 * \return un Log (S_logEntry* unLog) en el caso de que malloc le de memoria, o (NULL) en el caso que no encuentre memoria
 *
 */
S_logEntry* s_logEntry_new()//crear un espacio en la memoria para un log
{
    S_logEntry* unLog = (S_logEntry*)malloc(sizeof(S_logEntry));

    return unLog;
}

/** \brief Elimina un log
 * \param recibe un log (S_logEntry* this)
 * \return Si lo eliminó retorna (0), si no lo eliminó retorna (-1)
 *
 */
int s_logEntry_delete(S_logEntry* this)
{
    int ret = -1;

    if(this != NULL)
    {
        free(this);
        ret = 0;
    }

    return ret;
}

//////////////////DATE//////////////////


/** \brief Agrega una fecha a un log
 *
 * \param un Log (S_logEntry* this)
 * \param la fecha a agregar char* date
 * \return (-1) si esta mal. (0) todo ok
 *
 */
int s_logEntry_setDate(S_logEntry* this, char* date)
{
    int ret = -1;

    if(this != NULL && utn_isValidName(date) == 0)
    {

        strncpy(this->date,date,sizeof(this->date));
        ret=0;
    }
    return ret;
}

/** \brief Obtengo la fecha de un log y la guardo en la variable pasada por parametro
 *
 * \param S_logEntry* this (un log)
 * \param char* date
 * \return (-1) si esta mal. (0) todo ok.
 */
int s_logEntry_getDate(S_logEntry* this,char* date)
{
    int ret = -1;

    if(this != NULL && date != NULL)
    {
        strncpy(this->date,date,sizeof(this->date));
        ret = 0;
    }

    return ret;
}

/** \brief Funcion criterio para comparar dos fechas//casteas a tipo log
 * \param void* pElementB
 * \return si devuelve (0) son iguales, si pElementB es menor que pElementA devuelve (1),
 *         si pElementA es menor que pElementB devuelve (-1)
 *
 */
/*int s_logEntry_compareDate(void* pElementA,void* pElementB)
{
    int ret = 0;
    char buffetDateA[128]= ((S_logEntry*)pElementA)->date;
    char buffetDateB[128]= ((S_logEntry*)pElementB)->date;

    char diaA[128]= strtok(buffetDateA,"/");
    char mesA[128]= strtok(buffetDateA,"/");
    char anioA[128]= strtok(buffetDateA,"\0");

    char diaB[128]= strtok(buffetDateB,"/");
    char mesB[128]= strtok(buffetDateB,"/");
    char anioB[128]= strtok(buffetDateB,"\0");

    if(strcmp(anioA, anioB) == 0)//si son iguales
    {
        if(strcmp(mesA, mesB)== 0)
        {
            if((strcmp(diaA, diaB) == 0))
            {
                ret = 0;
            }
        }

    }
    else if()

    if(strcmp(anioA, anioB) <0)//pElementB es mayor que pElementA
    {
        ret = 1;
    }

    if(strcmp(anioA, anioB) >0)//pElementA es mayor que pElementB
    {
        ret = 1;
    }

    return ret;
}*/

//////////////////TIME//////////////////
/** \brief Agrega una hora a un log
 *
 * \param un Log (S_logEntry* this)
 * \param char* time
 * \return (-1) si esta mal. (0) todo ok
 *
 */
int s_logEntry_setTime(S_logEntry* this,char* time)
{
    int ret=-1;
    if(this != NULL && utn_isValidName(time) == 0)
    {
        strncpy(this->time,time,sizeof(this->time));
        ret = 0;
    }
    return ret;
}

/** \brief Obtengo la hora de un log y la guardo en la variable pasada por parametro
 *
 * \param S_logEntry* this (un log)
 * \param char* date
 * \return (-1) si esta mal. (0) todo ok.
 */
int s_logentry_getTime(S_logEntry* this,char* time)
{
    int ret = -1;

    if(this != NULL && time != NULL)
    {
        strncpy(this->time,time,sizeof(this->time));
        ret = 0;
    }
    return ret;
}

/** \brief Funcion criterio para comparar dos horas
 * \param void* pElementA
 * \param void* pElementB
 * \return si devuelve (0) son iguales, si pElementB es menor que pElementA devuelve (1),
 *         si pElementA es menor que pElementB devuelve (-1)
 *
 */
int s_logEntry_compareTime(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(strcmp(((S_logEntry*)pElementA)->time,((S_logEntry*)pElementB)->time)>0)
    {
        ret = 1;
    }
    if(strcmp(((S_logEntry*)pElementA)->time,((S_logEntry*)pElementB)->time)<0)
    {
        ret = -1;
    }
    return ret;
}

//////////////////SERVICE NAME//////////////////
/** \brief Agrega una fecha a un log
 *
 * \param un Log (S_logEntry* this)
 * \param char* date
 * \return (-1) si esta mal. (0) todo ok
 *
 */
int s_logEntry_setServiceName(S_logEntry* this,char* serviceName)
{
    int ret=-1;
    if(this != NULL && utn_isValidName(serviceName)==0)
    {
        strncpy(this->serviceName,serviceName,sizeof(this->serviceName));
        ret=0;
    }
    return ret;
}

/** \brief Obtengo la fecha de un log y la guardo en la variable pasada por parametro
 *
 * \param S_logEntry* this (un log)
 * \param char* date
 * \return (-1) si esta mal. (0) todo ok.
 */
int s_logEntry_getServiceName(S_logEntry* this,char* serviceName)
{
    int ret=-1;

    if(this != NULL && serviceName != NULL)
    {
        strncpy(this->serviceName,serviceName,sizeof(this->serviceName));
        ret = 0;
    }
    return ret;
}

/** \brief Funcion criterio para ordenar alfabeticamente los elementos recibidos por parametro
 * \param void* pElementA
 * \param void* pElementB
 * \return si devuelve (0) son iguales, si pElementB es menor que pElementA devuelve (1),
 *         si pElementA es menor que pElementB devuelve (-1)
 *
 */
/*int s_logEntry_compareServiceName(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(strcmp(((S_logEntry*)pElementA)->serviceName,((S_logEntry*)pElementB)->serviceName)>0)//orden alfabetico si A>B
    {
        ret = 1;
    }
    if(strcmp(((S_logEntry*)pElementA)->serviceName,((S_logEntry*)pElementB)->serviceName)<0)//A<B
    {
        ret = -1;
    }
    return ret;
}*/

//////////////////GRAVEDAD//////////////////
/** \brief Agrega gravedad a un log
 *
 * \param un Log (S_logEntry* this)
 * \param char* date
 * \return (-1) si esta mal. (0) todo ok
 *
 */
int s_logEntry_setGravedadStr(S_logEntry* this,char* gravedadStr)
{
    int ret=-1;
    int bufferGravedad;

    if(this != NULL)
        {
            if(utn_isValidInt(gravedadStr) == 0)
            {
                bufferGravedad = atoi(gravedadStr);
                if(s_logEntry_setGravedad(this,bufferGravedad) == 0)
                {
                    ret = 0;
                }
            }
        }
    return ret;
}

int s_logEntry_setGravedad(S_logEntry* this, int gravedad)
{
    int ret=-1;
    if(this!=NULL && gravedad>=0)
    {
        this->gravedad=gravedad;
        ret=0;
    }
    return ret;
}

/** \brief Obtengo la fecha de un log y la guardo en la variable pasada por parametro
 *
 * \param S_logEntry* this (un log)
 * \param char* date
 * \return (-1) si esta mal. (0) todo ok.
 */
int s_logEntry_getGravedad(S_logEntry* this, int* gravedad)
{
    int ret=-1;
    if(this!=NULL && gravedad != NULL)
    {
        *gravedad=this->gravedad;
        ret = 0;
    }
    return ret;
}

int s_logEntry_compareGravedad(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(((S_logEntry*)pElementA)->gravedad > ((S_logEntry*)pElementB)->gravedad)
    {
        ret = 1;
    }
    if(((S_logEntry*)pElementA)->gravedad < ((S_logEntry*)pElementB)->gravedad)
    {
        ret = -1;
    }
    return ret;
}

//////////////////MENSAJE (MSG)//////////////////
/** \brief Agrega una fecha a un log
 *
 * \param un Log (S_logEntry* this)
 * \param char* date
 * \return (-1) si esta mal. (0) todo ok
 *
 */
int s_logEntry_setMsg(S_logEntry* this,char* msg)
{
    int ret=-1;
    if(this != NULL && utn_isValidName(msg))
    {
        strncpy(this->msg,msg,sizeof(this->msg));
        ret=0;
    }
    return ret;
}

/** \brief Obtengo la fecha de un log y la guardo en la variable pasada por parametro
 *
 * \param S_logEntry* this (un log)
 * \param char* date
 * \return (-1) si esta mal. (0) todo ok.
 */
int s_logEntry_getMsg(S_logEntry* this,char* msg)
{
    int ret = -1;

    if(this != NULL && msg != NULL)
    {
        strncpy(this->msg,msg,sizeof(this->msg));
        ret=0;
    }
    return ret;
}

/** \brief Funcion criterio para comparar dos fechas
 * \param void* pElementA
 * \param void* pElementB
 * \return si devuelve (0) son iguales, si pElementB es menor que pElementA devuelve (1),
 *         si pElementA es menor que pElementB devuelve (-1)
 *
 */
int s_logEntry_compareMsg(void* pElementA,void* pElementB)
{
    int ret = 0;
    if(strcmp(((S_logEntry*)pElementA)->msg,((S_logEntry*)pElementB)->msg)>0)
    {
        ret = 1;
    }
    if(strcmp(((S_logEntry*)pElementA)->msg,((S_logEntry*)pElementB)->msg)<0)
    {
        ret = -1;
    }
    return ret;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recibe todos los datos para settearlos
 *
 * \param char* fechaStr
 * \param char* timeStr
 * \param char* serviceNameStr
 * \param char* serviceNameStr
 * \param char* gravedadStr
 * \param char* msgStr
 * \return retorna un puntero a un Log(S_logEntry*) si esta ok, (NULL) en el caso de error
 *
 */
S_logEntry* s_logEntry_newParametros(char* fechaStr,char* timeStr ,char* serviceNameStr,char* gravedadStr,char* msgStr)
{
    S_logEntry* auxLog;
    auxLog = s_logEntry_new();//pido memoria para un log

    if(auxLog != NULL)
    {
        if(s_logEntry_setDate(auxLog,fechaStr) != 0 || s_logEntry_setTime(auxLog,timeStr) != 0 ||
           s_logEntry_setServiceName(auxLog,serviceNameStr) != 0 || s_logEntry_setGravedadStr(auxLog,gravedadStr) != 0 || s_logEntry_setMsg(auxLog,msgStr) != 0)
        {
            s_logEntry_delete(auxLog);
            auxLog = NULL;
        }
    }
    return auxLog;
}
//////

/** \brief Si la gravedad es menor a 3 , se descartara el error
 * \param
 * \param
 * \return int (-1) si el puntero es NULL, (1) si la gravedad es menor a 3.
 *         (0) si la gravedad no es menor a 3
 *
 */
int s_logEntry_filtrarGMenor3(void* pElement)
{
	int ret = -1;

	if(pElement != NULL)
	{
		if(((S_logEntry*)pElement)->gravedad > 3)
		{

			ret = 0;//si la gravedad es menor a 3
		}
		else
		{
			ret = 1;
        }
	}

	return ret;
}

/** \brief Si la gravedad es menor a 3 , se descartara el error
 * \param
 * \param
 * \return int (-1) si el puntero es NULL, (1) si la gravedad es menor a 3.
 *         (0) si la gravedad no es menor a 3
 *
 */
int s_logEntry_filtrarGEsMenor3(void* pElement)
{
	int ret = -1;

	if(pElement != NULL)
	{
		if(((S_logEntry*)pElement)->gravedad < 3)
		{

			ret = 0;//si la gravedad es menor a 3
		}
		else
		{
			ret = 1;
        }
	}

	return ret;
}

/** \brief Comprueba si la gravedad es igual a 3
 * \param void* pElement
 * \return int (-1) si el puntero es NULL, (1) si la gravedad es igual a 3.
 *         (0) si la gravedad no es menor a 3
 */
int s_logEntry_filtrarGIgualA3(void* pElement)
{
	int ret = -1;

	if(pElement != NULL)
	{
		if(((S_logEntry*)pElement)->gravedad == 3)
		{

			ret = 0;
		}
		else
		{
			ret = 1;
		}
	}

	return ret;
}

/** \brief Comprueba si la gravedad es entre 4 y 7(inclusive)
 * \param void* pElement
 * \return int (-1) si el puntero es NULL, (1) si la gravedad es igual a 3.
 *         (0) si la gravedad no es menor a 3
 */
int s_logEntry_filtrarGentre4y7(void* pElement)
{
	int ret = -1;

	if(pElement != NULL)
	{
		if(((S_logEntry*)pElement)->gravedad > 4 && ((S_logEntry*)pElement)->gravedad <= 7)
		{

			ret = 0;
		}
		else
		{
			ret = 1;
		}
	}

	return ret;
}

/** \brief Comprueba si la gravedad es mayor a 7.
 * \param void* pElement
 * \return int (-1) si el puntero es NULL, (1) si la gravedad es igual a 3.
 *         (0) si la gravedad no es menor a 3
 */
int s_logEntry_filtrarGMayorA7(void* pElement)
{
	int ret = -1;

	if(pElement != NULL)
	{
		if(((S_logEntry*)pElement)->gravedad > 7)
		{

			ret = 0;
		}
		else
		{
			ret = 1;
		}
	}

	return ret;
}



