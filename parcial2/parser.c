#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "dominio.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayPatente LinkedList*
 * \return int
 *
 */
int parser_DominioFromText(FILE* pFile, LinkedList* pArrayPatente)
{
    Dominio* patente;
    int cont = 0;
    char auxId[100];
    char auxDominio[120];
    char auxAnio[120];

    if(pFile == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",auxId,auxDominio,auxAnio);
        while(!feof(pFile))
        {
            patente =(Dominio*) dominio_New();
            if(patente !=NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^\n]\n",auxId,auxDominio,auxAnio);
                patente =(Dominio*) dominio_NewParametros(auxId,auxAnio,auxDominio);
            }
            if(patente != NULL)
            {
                ll_add(pArrayPatente,(Dominio*)patente);
                cont++;
            }
        }
        printf("carga de empleados exitosa!!!\n");
    }
    return cont;
}
