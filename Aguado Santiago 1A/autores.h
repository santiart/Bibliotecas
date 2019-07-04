#ifndef Autores_H_INCLUDED
#define Autores_H_INCLUDED
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    char nombre[20];
    char apellido[20];
    char sexo;
    int id;
    int esta;
}eAutor;

void inicializarAutores(eAutor vec[],int tam);
void mostrarAutor(eAutor autores);
void mostrarAutores(eAutor vec[], int tam);
void harcodearAutores(eAutor lista[], int tam);
void bajaAutor(eAutor vec[], int tam);
int buscarAutor(eAutor vec [], int tam, int id);

#endif // Autores_H_INCLUDED
