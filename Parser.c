#include <stdio.h>
#include <stdlib.h>
#include "S_logentry.h"
#include "LinkedList.h"

/**brief Parsea los datos los datos del tipo S_logentry desde el archivo recibido como parametro (modo texto).
 *
 * \param path char*
 * \param pArrayListS_logEntry LinkedList*
 * \return int
 *
 */
int parser_S_logEntryFromText(FILE* pFile , LinkedList* pArrayListS_logEntry)
{
    int ret = -1;

    char bufferFecha[4096];
    char bufferHora[4096];
    char bufferServiceName[4096];
    char bufferGravedad[4096];
    char bufferMsg[4096];
    S_logEntry* pS_logEntry;

    if(pFile != NULL && pArrayListS_logEntry != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",  bufferFecha,
                                                              bufferHora,
                                                              bufferServiceName,
                                                              bufferGravedad,
                                                              bufferMsg);

            pS_logEntry = s_logEntry_newParametros(bufferFecha,bufferHora,bufferServiceName,bufferGravedad,bufferMsg);

            if(pS_logEntry != NULL)
            {
                if(ll_add(pArrayListS_logEntry,pS_logEntry) == 0) //agrego un nodo (log)
                {
                   ret = 0;
                }

            }
        }
    }
    return ret;
}

