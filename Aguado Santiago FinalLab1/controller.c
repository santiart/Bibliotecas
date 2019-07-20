#include "controller.h"

int controller_loadFromText(char* path, LinkedList* arrayList)
{
    FILE* f;
    int retorno = 0;
    f = fopen(path, "r");
    if(f != NULL)
    {
        parser_LibrosFromText(f, arrayList);
        retorno = 1;
        printf("carga de empleados exitosa...\n");
    }
    fclose(f);
    return retorno;
}

int controller_ListLibros(LinkedList* arrayList)
{
    int retorno = 0;
    int i;
    Libros* libro;

    if(arrayList != NULL)
    {
        printf("id  -  titulo   -  autores   - precio  - editorialId \n");
        for(i = 0; i < ll_len(arrayList); i++)
        {
            libro = (Libros*)ll_get(arrayList,i);

            printf("obtiene libro\n");
            printf("%d - %10s  - %10s  - %10d   -  %10d \n",libro->id, libro->titulo, libro->autor,libro->precio,libro->editId);
        }
        retorno = 1;
    }
    return retorno;
}

int controller_SortId(LinkedList* arrayList)
{
    int retorno = 0;
    if(arrayList != NULL)
    {
        ll_sort(arrayList,Libros_sortId,1);
        retorno = 1;
    }
    return retorno;
}

