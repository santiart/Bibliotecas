#include "libros.h"

void inicializarLibros(eLibros lib[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lib[i].estado = 0;
    }
}

void harcodearLibros(eLibros lista[], int tam)
{
    char titulos[][80] = {"Muerte en el nilo","Sherlock Holmes", "Tom Sawyer", "Christine","El Gigante Egoista"};
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].id = i+1;
        strcpy(lista[i].nombre, titulos[i]);
        lista[i].estado = 1;
    }
}

void mostrarlibro(eLibros lib)
{
    printf("\n%s\t   %d\t\n ",lib.nombre, lib.id);
}

void mostrarlibros(eLibros vec[], int tam)
{
    int i;
    int contador = 0;
    printf("\n     Nombre    \n\n");
    for(i = 0; i < tam; i++)
    {
        if(vec[i].estado == 1)
        {
            mostrarlibro(vec[i]);
            contador++;
        }
    }
    if(contador == 0)
    {
        printf("\n no hay libros para mostrar \n");
    }
}

void ordenarLibrosPorTitulo(eLibros libros[], int tam)
{
    int i,j;
    eLibros aux;
    for(i = 0; i < tam -1; i++)
    {
        for(j = i+1; j < tam; j++)
        {
            if(((stricmp(libros[i].nombre,libros[j].nombre)<0)) && (libros[i].estado == 1) && (libros[j].estado == 1))
            {
                aux = libros[i];
                libros[i] = libros[j];
                libros[j] = aux;
            }
        }
    }
    printf("orden de libros exitosa, ingrese la opcion 5 del menu principal para ver la lista\n");
}
