#include "controller.h"

int controller_loadFromText(char* path, LinkedList* arrayList)
{
    FILE* f;
    int retorno = 0;
    f = fopen(path, "r");
    if(f != NULL)
    {
        parser_PeliculasFromText(f, arrayList);
        retorno = 1;
    }
    fclose(f);
    return retorno;
}

int controller_ListPeliculas(LinkedList* arrayList)
{
    int retorno = 0;
    int i;
    ePelicula* pelicula;
    if(arrayList != NULL)
    {
        printf("id  -  titulo   -  anio   - genero \n");
        for(i = 0; i < ll_len(arrayList); i++)
        {
            pelicula = (ePelicula*)ll_get(arrayList,i);
            printf("%10d - %10s  -  %10d  -  %10s \n", pelicula->id,pelicula->nombre,pelicula->anio,pelicula->genero);
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
        ll_sort(arrayList,peliculas_sortId,1);
        retorno = 1;
    }
    return retorno;
}
