#ifndef Libros_H_INCLUDED
#define Libros_H_INCLUDED
#include "autores.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[50];
    int id;
    int estado;
}eLibros;

void inicializarLibros(eLibros lib[], int tam);
void mostrarlibro(eLibros lib);
void mostrarlibros(eLibros vec[], int tam);
void harcodearLibros(eLibros lista[], int tam);
void ordenarLibrosPorTitulo(eLibros libros[], int tam);

#endif // Libros_H_INCLUDED



