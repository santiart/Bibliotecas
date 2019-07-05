#ifndef Socios_H_INCLUDED
#define Socios_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "fecha.h"

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char sexo[10];
    char email[20];
    eFecha fecha;
    int telefono;
    int estado;
} eSocios;

#include "input.h"

int GenerarId();
void inicializarSocios(eSocios vec[],int tam);
void mostrarSocio(eSocios emp);
void mostrarSocios(eSocios vec[], int tam);
int buscarLibre(eSocios vec[],int tam);
int buscarSocio(eSocios vec [], int tam, int id);
void altaSocio(eSocios vec[], int tam);
void modificarSocio(eSocios vec[], int tam);
void bajaSocio(eSocios vec[], int tam);
void ordenarSocios(eSocios socios[], int tam);
#endif // Socios_h_INCLUDED
