#include "socios.h"
#include "input.h"


void inicializarSocios(eSocios vec[],int tam)
{
    int i;
    for( i = 0; i < tam; i++)
    {
        vec[i].estado=0;
    }

}

void mostrarSocio(eSocios soc)
{
    printf("\n%d   %10s    %10s  %10s     %10s    %d/%d/%d     %3d  \n ",
           soc.id, soc.nombre, soc.apellido,soc.sexo, soc.email,soc.fecha.dia, soc.fecha.mes,soc.fecha.anio,soc.telefono);
}

void mostrarSocios(eSocios vec[], int tam)
{
    int i;
    int contadorS = 0;
    printf("\nId    Nombre       Apellido     sexo      email    fecha de Asociado     telefono \n\n");
    for(i = 0; i < tam; i++)
    {

        if(vec[i].estado == 1)
        {
            mostrarSocio(vec[i]);
            contadorS++;
        }
        if(contadorS == 0)
        {
            printf("\n no hay socios para mostrar \n");
        }
    }
}

int buscarLibre(eSocios vec[],int tam)
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

int buscarSocio(eSocios vec [], int tam, int id)
{
    int i;
    int indice = -1;

    for(i = 0; i < tam; i++)
    {
        if((vec[i].estado == 1)&&(vec[i].id == id))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaSocio(eSocios vec[], int tam)
{
    int indice;
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxEmail[50];
    char auxSexo[10];
    char auxDia[50];
    char auxMes[50];
    char auxAnio[50];
    char auxTelefono[50];

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
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

        while(!getStringLetras("ingrese el sexo: \n",auxSexo))
        {
            printf("intente de nuevo...\n");
        }

        strcpy(vec[indice].sexo,auxSexo);

        while(!esEmail("ingrese el email: \n",auxEmail))
        {
            printf("intente de nuevo...\n");
        }

        strcpy(vec[indice].email, auxEmail);

        while(!getStringNumeros("ingrese el dia de ingreso: \n",auxDia))
        {
            printf("intente de nuevo...\n");
        }

        vec[indice].fecha.dia = atoi(auxDia);

        while(!getStringNumeros("ingrese el mes de ingresado: \n", auxMes))
        {
            printf("intente de nuevo \n");
        }

        vec[indice].fecha.mes = atoi(auxMes);

        while(!getStringNumeros("ingrese el anio de ingreso: \n", auxAnio))
        {
            printf("intente de nuevo \n");
        }

        vec[indice].fecha.anio = atoi(auxAnio);

        while(!getStringNumeros("ingrese el telefono: \n", auxTelefono))
        {
            printf("intente de nuevo...\n");
        }
        vec[indice].telefono = atoi(auxTelefono);

        vec[indice].id =  id = GenerarId();
        vec[indice].estado = 1;

        printf("Alta socio exitosa!!!\n\n");

    }
}

void modificarSocio(eSocios vec[], int tam)
{
    int esta;
    int id;
    int opcion;
    char seguir = 's';
    char confirmar;
    char auxId[50];
    char auxNombre[50];
    char auxApellido[50];
    char auxDia[50];
    char auxMes[50];
    char auxAnio[50];
    char auxEmail[50];
    char auxSexo[50];
    char auxTelefono[50];

    while(!getStringNumeros("ingrese el id del socio a modificar: \n", auxId))
    {
        printf("intente de nuevo...\n");
    }

    id = atoi(auxId);
    esta = buscarSocio(vec, tam, id);

    if(esta != -1)
    {
        do
        {
            system("cls");
            printf("            ::M O D I F I C A C I O N::          \n");
            printf("  1_ Modificar Nombre     2_ Modificar Apellido  \n");
            printf("  3_Modificar Sexo        4_Modificar email      \n");
            printf("  5_Modificar Telefono     6_Modificar fecha     \n");
            printf("  7_Salir...                                     \n");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("\n usted ha seleccionado al socio : \n");
                mostrarSocio(vec[esta]);

                vec[esta].id = id;

                while(!getStringLetras("ingrese el nombre: \n", auxNombre))
                {
                    printf("intente de nuevo...\n");
                }

                strcpy(vec[esta].nombre, auxNombre);

                printf("Modifiacion de socio exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 2:
                printf("\n usted ha seleccionado al socio : \n");
                mostrarSocio(vec[esta]);

                vec[esta].id = id;

                while(!getStringLetras("ingrese el apellido: \n", auxApellido))
                {
                    printf("intente de nuevo...\n");
                }
                strcpy(vec[esta].apellido, auxApellido);

                printf("Modifiacion de socio exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 3:
                printf("\n usted ha seleccionado al socio : \n");
                mostrarSocio(vec[esta]);

                vec[esta].id = id;

                while(!getStringLetras("ingrese el sexo: \n", auxSexo))
                {
                    printf("intente de nuevo...\n");
                }
                strcpy(vec[esta].sexo,auxSexo);

                printf("Modifiacion de socio exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 4:
                printf("\n usted ha seleccionado al socio : \n");
                mostrarSocio(vec[esta]);

                vec[esta].id = id;

                while(!esEmail("ingrese el email: \n", auxEmail))
                {
                    printf("intente de nuevo...\n");
                }
                strcpy(vec[esta].email, auxEmail);
                printf("Modifiacion de socio exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;
            case 5:
                printf("\n usted ha seleccionado al socio : \n");
                mostrarSocio(vec[esta]);

                vec[esta].id = id;

                while(!esTelefono("ingrese el telefono: \n", auxTelefono))
                {
                    printf("intente de nuevo...\n");
                }
                vec[esta].telefono = atoi(auxTelefono);

                printf("Modifiacion de socio exitosa!!!\n\n");

                vec[esta].estado = 1;
                system("pause");
                break;

            case 6:
                printf("\n usted ha seleccionado al socio : \n");
                mostrarSocio(vec[esta]);

                vec[esta].id = id;

                while(!getStringNumeros("ingrese el dia: \n",auxDia))
                {
                    printf("itente de nuevo...\n");
                }

                vec[esta].fecha.dia = atoi(auxDia);

                while(!getStringNumeros("ingrese el mes: \n",auxMes))
                {
                    printf("intente de nuevo...\n");
                }

                vec[esta].fecha.mes = atoi(auxMes);
                while(!getStringNumeros("ingrese el anio: \n",auxAnio))
                {
                    printf("intente de nuevo..\n");
                }
                vec[esta].fecha.anio = atoi(auxAnio);
                printf("Modifiacion de socio exitosa!!!\n\n");

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
    else
    {
        printf("no existe un empleado con ese id...\n");
    }
}

void bajaSocio(eSocios vec[], int tam)
{
    int indice;
    int esta;
    int id;
    char confirmar;
    char auxid[50];

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("\n no hay lugar disponible en el sistema\n");
    }
    else
    {
        while(!getStringNumeros("ingrese el id del socio a dar de baja: \n", auxid))
        {
            printf("intente de nuevo...\n");

        }
        id = atoi(auxid);
        esta=buscarSocio(vec, tam, id);

        if(esta != -1)
        {
            printf("\n usted ha seleccionado al socio : \n");
            mostrarSocio(vec[esta]);

            printf("\n confirmar la baja? (s/n)...");
            fflush(stdin);
            confirmar = getche();

            if( tolower(confirmar == 's'))
            {
                vec[esta].id = id;

                vec[esta].estado = 0;
                printf("\n Baja de socio exitosa!!!\n\n");
            }
            else
            {
                printf("\n Baja de socio cancelada \n\n");
            }
        }
    }
}

void ordenarSocios(eSocios vec[], int tam)
{
    int i;
    int j;
    eSocios aux;
    for(i = 0 ; i < tam - 1  ; i++)
    {
        for(j = i + 1 ; j < tam  ; j++)
        {

            if(strcmp(vec[i].apellido, vec[j].apellido)==1)
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }

        }
    }
    printf("\n Orden de socios exitosa!!!, presione la opcion 4 para ver la lista en orden \n\n");
}

int GenerarId()
{
    static int id = -1;
    id++;
    return id;
}
