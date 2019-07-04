#include "fecha.h"

void inicializarFecha(eFecha fecha[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        fecha[i].estado = 0;
        fecha[i].anio = 0;
        fecha[i].mes = 0;
        fecha[i].dia = 0;
    }
}
