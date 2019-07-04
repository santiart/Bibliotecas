#include "sectores.h"

int obtenerSector(eSector sectores[], int tam, int idSector, char desc[])
{
    int todoOk;
    int i;

    for(i=0; i<tam; i++)
    {
        if(idSector==sectores[i].id)
        {
            strcpy(desc, sectores[i].desc);
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

void mostrarSectoresConEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    system("cls");
    int i;
    int j;

    for(i=0; i<tamSec; i++)
    {
        printf("Sector:  %s \n\n",sectores[i].desc);
        for(j=0; j<tam; j++)
        {
            if((empleados[j].idSector==sectores[i].id)&&(empleados[j].estado==1))
            {
                mostrarEmpleado(sectores,tamSec,empleados[j]);
            }
        }
        printf("\n\n");

    }
}

void mostrarCantEmpleadosXSector(eEmpleado empleados[], int tam, eSector sectores[], int tamSec)
{
    int i;
    int j;
    int contador;
    system("cls");

    for(i=0 ; i<tamSec ; i++)
    {
        contador=0;
        printf("Sector: %s \n\n",sectores[i].desc);

        for(j=0 ; j<tam ; j++)
        {
            if((sectores[i].id == empleados[j].idSector)&&(empleados[j].estado == 1))
            {
                mostrarEmpleado(sectores,tamSec,empleados[j]);
                contador++;
            }
        }
        printf("Cantidad de empleados: %d\n\n",contador);
    }
}

