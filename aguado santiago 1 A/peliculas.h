#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[50];
    int anio;
    char genero[50];

} ePelicula;

#endif // PELICULAS_H_INCLUDED

int pelicula_new();
int peliculas_newParametros(char* idStr, char* nombreStr, char* anioStr, char*generoStr);
int peliculas_setId(ePelicula* this, int id);
int peliculas_getId(ePelicula* this, int *id);
int peliculas_setAnio(ePelicula* this, int anio);
int peliculas_getAnio(ePelicula* this, int *anio);
int peliculas_setNombre(ePelicula* this, char* nombre);
int peliculas_getNombre(ePelicula* this, char* nombre);
int peliculas_setGenero(ePelicula* this, char* genero);
int peliculas_getGenero(ePelicula* this, char* genero);
int peliculas_sortId(void* pVoid1,void* pVoid2);
int depurarPeliculas(LinkedList* this);
int filtrarPorGenero(void* void1);
