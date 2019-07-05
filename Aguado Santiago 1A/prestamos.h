#ifndef Prestamos_H_INCLUDED
#define Prestamos_H_INCLUDED
#include "socios.h"
#include "autores.h"
#include "libros.h"
#include "input.h"

typedef struct
{
    int id;
    eSocios socios;
    eLibros libros;
    int dia,mes,anio;
    int estado;
    int codSoc,codLib;
    char nombreLibro[20],nombreSocio[20];
}ePrestamos;

void inicializarPrestamos(ePrestamos vec[], int tam);
void mostrarPrestamo(ePrestamos prestamos);
void mostrarPrestamos(ePrestamos prestamos[], int tam);
int buscarLugarLibre(ePrestamos vec[],int tam);
int buscarPrestamo(ePrestamos vec [], int tam, int id);
void altaPrestamos(ePrestamos vec[], int tam);
int autoIncId();
void totalGeneralYPromedioDiario(ePrestamos prestamos[], int tam);
int buscarsocio(ePrestamos vec [], int tam, int id);
int buscarlibro(ePrestamos vec[], int tam, int id);
int buscaFecha(ePrestamos prestamos[], int tamPrestamos, int dia, int mes, int anio);
void mostrarSociosMasSolicitadores(ePrestamos prestamos[], int tamPrestamos);
void librosPrestadosASocioDeterminado(ePrestamos prestamos[], int tamPrestamos);
void libroDeterminadoPorSocios(ePrestamos prestamos[], int tamPrestamos);
void librosMenosSolicitados(ePrestamos prestamos[], int tam);
void libroEnFechaDeterminada(ePrestamos prestamos[], int tamPrestamos);
#endif // Prestamos_H_INCLUDED
