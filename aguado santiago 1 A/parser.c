#include  "parser.h"

int parser_PeliculasFromText(FILE* f, LinkedList* arrayList)
{
    ePelicula* pelicula;
    int cont = 0;
    char auxNombre[50];
    char auxGenero[50];
    char auxId[20];
    char auxAnio[20];
    if(f != NULL)
    {
        fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxAnio, auxGenero);
        while(!feof(f))
        {
            pelicula = (ePelicula*)pelicula_new();
            if(pelicula != NULL)
            {
                fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxNombre,auxAnio, auxGenero);
                pelicula = (ePelicula*)peliculas_newParametros(auxId,auxNombre,auxAnio,auxGenero);
            }
            if(pelicula != NULL)
            {
                ll_add(arrayList,(ePelicula*)pelicula);
                cont++;
            }
        }
    }
    return cont;
}
