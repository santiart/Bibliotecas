#include "autores.h"
#include <string.h>
void inicializarAutores(eAutor vec[],int tam)
{
    int i;
    for(i=0; i< tam; i++)
    {
        vec[i].id = 0;
        vec[i].esta = 0;
    }
}

void harcodearAutores(eAutor lista[], int tam)
{
    char nombres[][50] = {"Agatha","Arthur", "Mark","Stephen","Oscar"};
    char apellidos[][50] = {"Christie","Conan Doyle","Twain","King","Wilde"};
    char sexos[] = {'f','m','m','m','m'};
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].id = i+1;
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido, apellidos[i]);
        lista[i].sexo = sexos[i];
        lista[i].esta = 1;
    }
}

void mostrarAutor(eAutor autores)
{
    printf("%s\t    %s\t     %c\t    %d\t\n", autores.nombre, autores.apellido, autores.sexo, autores.id);
}

void mostrarAutores(eAutor vec[], int tam)
{
    int i;
    int contador = 0;
    printf("\nNombre      apellido       sexo    id \n\n");
    for(i = 0; i < tam; i++)
    {
        if(vec[i].esta == 1)
        {
            mostrarAutor(vec[i]);
            contador++;
        }
    }

    if(contador == 0)
    {
        printf("\n no hay autores para mostrar \n");
    }
}


void bajaAutor(eAutor vec[], int tam)
{
    int ocupado;
    int id;
    char confirmar;
    char auxid[50];

    while(!getStringNumeros("ingrese el id del socio a dar de baja: \n", auxid))
    {
        printf("intente de nuevo...\n");

    }
    id = atoi(auxid);
    ocupado = buscarAutor(vec, tam, id);

    if(ocupado != -1)
    {
        printf("\n usted ha seleccionado al socio : \n");
        mostrarAutor(vec[ocupado]);

        printf("\n confirmar la baja? (s/n)...");
        fflush(stdin);
        confirmar = getche();

        if( tolower(confirmar == 's'))
        {
            vec[ocupado].id = id;

            vec[ocupado].esta = 0;
            printf("\n Baja de socio exitosa!!!\n\n");
        }
        else
        {
            printf("\n Baja de socio cancelada \n\n");
        }
    }
}


int buscarAutor(eAutor vec [], int tam, int id)
{
    int i;
    int indice = -1;

    for(i = 0; i < tam; i++)
    {
        if((vec[i].esta == 1)&&(vec[i].id == id))
        {
            indice = i;
            break;
        }
    }
    return indice;
}
