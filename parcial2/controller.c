#include "controller.h"
#include <stdio.h>
#include <stdlib.h>

int controller_LoadfromText(char* path,LinkedList* pArrayPatente)
{
    FILE* f;
    int retorno = 0;
    f = fopen(path,"r");
    if(f == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        parser_DominioFromText(f,pArrayPatente);
        retorno = 1;
        fclose(f);
    }
    return retorno;
}
int controller_SaveAsText(char* path, LinkedList* pArrayPatente)
{
    FILE * f;
    Dominio* patente;
    int i,retorno;
    f = fopen(path,"w");
    if(f == NULL)
    {
        printf("no se pudo abrir el archivo...\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        retorno = 1;
        for(i = 0; i<ll_len(pArrayPatente);i++)
        {
            patente = (Dominio*)dominio_New();
            patente =ll_get(pArrayPatente,i);
            fprintf(f,"%d, %d, %s, %c\n",patente->id,patente->anio,patente->dominio,patente->tipo);
        }
        fclose(f);
    }
    return retorno;
}

int controller_ListPatente(LinkedList* pArrayPatente)
{
    int retorno= -1, tam,i;
    tam = ll_len(pArrayPatente);

    if(pArrayPatente != NULL)
    {
        printf("Id    -   Anio   - Dominio  -    tipo \n");
        for(i = 0; i < tam; i++)
        {
            Dominio* patente = (Dominio*)ll_get(pArrayPatente,i);
            printf("%d\t  %d\t   %s \t %c\n", patente->id,patente->anio,patente->dominio, patente->tipo);
        }
        retorno = 0;
    }
    return retorno;
}

int controller_Mapear(void* vehiculo)
{
    char dominio[20];
    int i;
    dominio_getDominio(vehiculo,dominio);



   // dominio_setTipo( patente,'g');

    for(i = 0; i <= 3; i++)
    {
        if((dominio[i] < 'a' || dominio[i] > 'z') && (dominio[i] < 'A' ))
        {
            dominio_setTipo(vehiculo,'A');
        }
    }
    for(i = 3; i < 6; i++)
    {
        if((dominio[i] < 'a' || dominio[i] > 'z') && (dominio[i] < 'A' || dominio[i] > 'Z'))
        {
            dominio_setTipo(vehiculo,'M');
        }
    }

    return 1;
}
