#ifndef Empleado_H_INCLUDED
#define Empleado_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo[11];
    float sueldo;
    int estado;
    int idSector;
} eEmpleado;

#include "sectores.h"
#endif // Empleado_h_INCLUDED
#include "input.h"

void inicializarEmpleados(eEmpleado vec[],int tam);
void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
int buscarLibre(eEmpleado vec[],int tam);
int buscarEmpleado(eEmpleado vec [], int tam, int legajo);
void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector);
void ordenarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector, int sentido);

