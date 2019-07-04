#include "controller.h"

int dominio_LoadfromText(char* path,LinkedList* pArrayPatente)
{
    FILE* f;
    int i;retorno =0;
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
int dominio_SaveAsText(char* path, LinkedList* pArrayPatente)
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
            patente = dominio_New();
            patente =ll_get(pArrayPatente,i);
            fprintf(f,"%d, %d, %s, %c",patente.id,patente.anio,patente.dominio,patente.tipo);
        }
        fclose(f);
    }
    return retorno;
}
int dominio_ListPatente(LinkedList* pArrayPtente)
{

}

