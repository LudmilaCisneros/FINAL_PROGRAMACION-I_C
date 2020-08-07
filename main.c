#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "LinkedList.h"
#include "Controller.h"

int main()
{
    int opcion;
    int flagA = 0;
    int flagB = 0;
    LinkedList* pArrayListS_logEntry = ll_newLinkedList();

    do{
        printf("\n1.Leer Log.");
        printf("\n2.Procesar informacion.");
        printf("\n3.Mostrar estadisticas.");
        printf("\n4.Salir.");

        utn_getInt(&opcion,"\n\nIngrese la opcion: ","\nError, reingrese: ",1,4);

        switch(opcion)
        {
            case 1:
                if(flagA == 0)
                {
                  if(controller_loadFromText("./LOG.txt", pArrayListS_logEntry) == 0)
                  {
                      printf("\nSe leyo el archivo correctamente\n");
                      flagA = 1;
                  }

                }
                break;

            case 2:
                if(flagA == 1)
                {
                    controller_evaluarGravedad(pArrayListS_logEntry);
                    flagB = 1;
                }
                else{
                    printf("\nNo se leyo el archivo.\n");
                }
                break;

             case 3:
                if(flagA == 1 && flagB == 1)
                {
                    controller_mostrarEstadisticas(pArrayListS_logEntry);
                }
                else{
                    printf("\nNo se leyo el archivo o no se evaluo gravedad.\n");
                }

                break;

        }
    }while(opcion != 4);
    return 0;
}
