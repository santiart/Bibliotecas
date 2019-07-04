#include "empleado.h"
#include "input.h"


void inicializarEmpleados(eEmpleado vec[],int tam)
{
    int i;
    for( i = 0; i < tam; i++)
    {
        vec[i].estado=0;
    }

}

void mostrarEmpleado(eSector sectores[], int tam, eEmpleado emp)
{
    char nombreSector[20];
    char consigioNombre;

    consigioNombre=obtenerSector(sectores,tam, emp.idSector, nombreSector);
    if(!consigioNombre)
    {
        strcpy(nombreSector,"Sin Definir");
    }
    printf("\n%d    %10s      %10s    %10s    %10.2f   %10s\n ",emp.legajo, emp.nombre, emp.apellido, emp.sexo, emp.sueldo,nombreSector);
}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int i;
    int contador = 0;
    printf("\nLegajo        Nombre         Apellido          Sexo   Sueldo       Sector  \n\n");
    for(i = 0; i < tam; i++)
    {
        if(vec[i].estado == 1)
        {
            mostrarEmpleado(sectores, tamSector, vec[i]);
            contador++;
        }
    }
    if(contador == 0)
    {
        printf("\n no hay empleados para mostrar \n");
    }
}

int buscarLibre(eEmpleado vec[], int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if(vec[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec [], int tam, int legajo)
{
    int i;
    int indice = -1;

    for(i = 0; i < tam; i++)
    {
        if((vec[i].estado == 1)&&(vec[i].legajo == legajo))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int legajo;
    int esta;
    char auxLegajo[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxSector[50];
    char auxSueldo[50];
    char auxSexo[50];

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        while(!getStringNumeros("ingrese el legajo: \n", auxLegajo))
        {
            printf("intente de nuevo...\n");

        }
            legajo = atoi(auxLegajo);


            esta = buscarEmpleado(vec, tam, legajo);

            if(esta != -1)
            {
                printf("\n ya existe un empleado con ese legajo en el sistema");
                mostrarEmpleado(sectores,tamSector,vec[esta]);
            }
            else
            {
                vec[indice].legajo = legajo;

                while(!getStringLetras("ingrese el nombre: \n", auxNombre))
                {
                    printf("intente de nuevo...\n");
                }

                strcpy(vec[indice].nombre, auxNombre);

                while(!getStringLetras("ingrese el apellido: \n", auxApellido))
                {
                    printf("intente de nuevo...\n");
                }
                    strcpy(vec[indice].apellido, auxApellido);

                while(!getStringLetras("ingrese el sexo: \n", auxSexo))
                {
                    printf("intente de nuevo...\n");
                }

                strcpy(vec[indice].sexo, auxSexo);

                while(!getStringNumeros("ingrese el sueldo: \n", auxSueldo))
                {
                    printf("intente de nuevo...\n");
                }

                vec[indice].sueldo = atoi(auxSueldo);
                while(!getStringNumeros("ingrese el sector: \n( 1,sistemas \n 2,RRHH \n 3,compras \n 4,ventas \n 5,legales) \n", auxSector))
                {
                    printf("intente de nuevo...\n ");
                }

                vec[indice].idSector = atoi(auxSector);

                vec[indice].estado = 1;

                printf("Alta empleado exitosa!!!\n\n");
            }


    }
}


void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[],int tamSector)
{
    int esta;
    int legajo;
    int opcion;
    char seguir = 's';
    char confirmar;
    char auxLegajo[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxSector[50];
    char auxSueldo[50];
    char auxSexo[50];

    while(!getStringNumeros("ingrese el legajo del empleado a modificar: \n", auxLegajo))
    {
        printf("intente de nuevo...\n");
    }
    legajo = atoi(auxLegajo);
    esta = buscarEmpleado(vec, tam, legajo);

    if(esta != -1)
    {


        do
        {
            system("cls");
            printf("            ::M O D I F I C A C I O N::          \n");
            printf("  1_ Modificar Legajo      2_Modificar Sueldo    \n");
            printf("  3_ Modificar  Nombre     4_ Modificar Apellido \n");
            printf("  5_ Modificar sector      6_ Modificar Sexo     \n");
            printf("  7_ Salir...                                    \n");

            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("\n usted ha seleccionado al empleado : \n");
                mostrarEmpleado(sectores,tamSector,vec[esta]);

                vec[esta].legajo = legajo;
                while(!getStringNumeros("ingrese el nuevo legajo: \n", auxLegajo))
                {
                        printf("intente de nuevo...\n");
                }
                legajo = atoi(auxLegajo);

                vec[esta].legajo = legajo;

                printf("Modifiacion de empleado exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 2:
                printf("\n usted ha seleccionado al empleado : \n");
                mostrarEmpleado(sectores,tamSector,vec[esta]);

                vec[esta].legajo = legajo;

                while(!getStringNumeros("ingrese el sueldo: \n", auxSueldo))
                {
                    printf("intente de nuevo...\n");
                }
                vec[esta].sueldo = atoi(auxSueldo);

                printf("Modifiacion de empleado exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 3:
                printf("\n usted ha seleccionado al empleado : \n");
                mostrarEmpleado(sectores,tamSector,vec[esta]);

                vec[esta].legajo = legajo;

                while(!getStringLetras("ingrese el nombre: \n", auxNombre))
                {
                    printf("intente de nuevo...\n");
                }

                strcpy(vec[esta].nombre, auxNombre);

                printf("Modifiacion de empleado exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 4:
                printf("\n usted ha seleccionado al empleado : \n");
                mostrarEmpleado(sectores,tamSector,vec[esta]);

                vec[esta].legajo = legajo;

                while(!getStringLetras("ingrese el apellido: \n", auxApellido))
                {
                    printf("intente de nuevo...\n");
                }
                strcpy(vec[esta].apellido, auxApellido);

                printf("Modifiacion de empleado exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 5:
                printf("\n usted ha seleccionado al empleado : \n");
                mostrarEmpleado(sectores,tamSector,vec[esta]);

                vec[esta].legajo = legajo;

                while(!getStringNumeros("ingrese el sector: \n( 1,sistemas \n 2,RRHH \n 3,compras \n 4,ventas \n 5,legales) \n", auxSector))
                {
                    printf("intente de nuevo...\n ");
                }

                vec[esta].idSector = atoi(auxSector);

                printf("Modifiacion de empleado exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 6:
                printf("\n usted ha seleccionado al empleado : \n");
                mostrarEmpleado(sectores,tamSector,vec[esta]);

                vec[esta].legajo = legajo;

                while(!getStringLetras("ingrese el sexo: \n", auxSexo))
                {
                    printf("intente de nuevo...\n");
                }
                strcpy(vec[esta].sexo, auxSexo);

                printf("Modifiacion de empleado exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 7:
                printf("\n confirmar salida s/n?...\n");
                fflush(stdin);
                confirmar = getche();

                if( tolower(confirmar)== 's')
                {
                    seguir = 'n';
                }
                break;

            default:
                printf("\n Opcion invalida, intente de nuevo...");
                system("pause");
                system("break");

            }
        }
        while(seguir == 's');

    }
}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int esta;
    int legajo;
    char confirmar;
    char auxLegajo[50];

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        while(!getStringNumeros("ingrese el legajo del empleado a dar de baja: \n", auxLegajo))
        {
            printf("intente de nuevo...\n");

        }
        legajo = atoi(auxLegajo);
        esta=buscarEmpleado(vec, tam, legajo);

        if(esta != -1)
        {
            printf("\n usted ha seleccionado al empleado : \n");
            mostrarEmpleado(sectores,tamSector,vec[esta]);

            printf("\n confirmar la baja? (s/n)...");
            fflush(stdin);
            confirmar = getche();

            if( tolower(confirmar == 's'))
            {
                vec[esta].legajo = legajo;

                vec[esta].estado = 0;
                printf("\n Baja de empleado exitosa!!!\n\n");
            }
            else
            {
                printf("\n Baja de empleado cancelada \n\n");
            }
        }
    }
}

/** \brief
 *
 * \param vec[] eEmpleado
 * \param tam int
 * \param sectores[] eSector
 * \param tamSector int
 * \param sentido int indica el orden sentidio del orden, siendo 0 ascendente y 1 descendente
 * \return void
 *
 */
void ordenarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSector, int sentido)
{
    int i;
    int j;
    eEmpleado auxInt;
    for(i = 0 ; i < tam - 1  ; i++)
    {
        for(j = i + 1 ; j < tam  ; j++)
        {
            if(( sentido && vec[i].legajo < vec[j].legajo )
                    || (!sentido && vec[i].legajo > vec[j].legajo))
            {
                auxInt = vec[i];
                vec[i] = vec[j];
                vec[j] = auxInt;
            }
        }
    }
    printf("\n Orden de empleados exitosa!!!, presione la opcion 5 para ver la lista en orden \n\n");
}
