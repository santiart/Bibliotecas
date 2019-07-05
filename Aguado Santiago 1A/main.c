#include "socios.h"
#include "libros.h"
#include "autores.h"
#include "prestamos.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define TAM 5

int main()
{
    int opcion,opcionLista;
    char auxOpcion[20],auxOpcionLista[20];
    char seguir='s';
    char confirmar;
    int flag = 0;
    int flagP = 0;
    int i;

    ePrestamos listaP[TAM];
    inicializarPrestamos(listaP,TAM);

    eAutor listaA[TAM];
    harcodearAutores(listaA,TAM);

    eLibros listaL[TAM];
    harcodearLibros(listaL,TAM);

    eSocios lista[TAM];
    inicializarSocios(lista,TAM);

    do
    {
        system("cls");
        printf(" ::M E N U  D E  S O C I O S::   \n");
        printf(" 1_Alta de socio      2_Modificacion de socio  \n");
        printf(" 3_Baja de socio      4_Lista de socios        \n");
        printf(" 5_Lista de libros    6_Lista de Autores       \n");
        printf(" 7_Alta de Prestamo   8_Mostrar Prestamos      \n");
        printf(" 9_Listados           10_Salir...              \n");
        while(!getStringNumeros("ingrese una opcion: \n", auxOpcion))
        {
            printf("intente de nuevo...\n");
        }
        opcion = atoi(auxOpcion);

        switch(opcion)
        {
        case 1:
            altaSocio(lista,TAM);
            system("pause");
            flag = 1;

            break;
        case 2:
            if(flag == 1)
            {
                modificarSocio(lista,TAM);
                system("pause");
                break;
            }
            else
            {
                printf("debe hacer dar de alta al menos un empleado...\n ");
                break;
            }
        case 3:
            if(flag == 1)
            {
                bajaSocio(lista,TAM);
                system("pause");
                break;
            }
            else
            {
                printf("debe hacer dar de alta al menos un empleado...\n ");
                break;
            }
        case 4:
            if(flag == 1)
            {
                mostrarSocios(lista,TAM);
                system("pause");
                break;
            }
            else
            {
                printf("debe hacer dar de alta al menos un empleado...\n ");
                system("pause");
                break;
            }
        case 5:
            mostrarlibros(listaL,TAM);
            system("pause");
            break;
        case 6:
            mostrarAutores(listaA,TAM);
            system("pause");
            break;
        case 7:
            if(flag == 1)
            {
                for(i = 0; i < TAM; i++)
                {
                    listaP[i].libros = listaL[i];
                    listaP[i].socios = lista[i];
                }

                altaPrestamos(listaP,TAM);
                system("pause");
                flagP = 1;
                break;
            }
            else
            {
                printf("debe hacer al menos un alta de empleado...\n");
                system("pause");
                break;
            }
        case 8:
            if(flagP == 1)
            {
                mostrarPrestamos(listaP, TAM);
                system("pause");
                break;
            }
            else
            {
                printf("debe hacer al menos un prestamo...\n");
                system("pause");
                break;
            }
        case 9:
            if(flag == 1 && flagP == 1)
            {
                do
                {
                    system("cls");
                    printf("                 :: L I S T A D O S::                     \n");
                    printf("1_Listar libros prestados a socios determinado            \n");
                    printf("2_Listar socios que pidieron un libro determinado         \n");
                    printf("3_Mostrar socios mas solicitadores                        \n");
                    printf("4_Mostrar los libros menos solicitados                    \n");
                    printf("5_Listar prestamos en fecha determinada                   \n");
                    printf("6_Listar la cantidad total y el promedio diario(por mes)  \n");
                    printf("7_Ordenar socios por apellido(ascendente)                 \n");
                    printf("8_Ordenar libros por titulo(descendente)                  \n");
                    printf("9_Salir...                                                \n");
                    while(!getStringNumeros("ingrese una opcion: \n",auxOpcionLista))
                    {
                        printf("intente de nuevo...\n");
                    }
                    opcionLista = atoi(auxOpcionLista);
                    switch(opcionLista)
                    {
                        case 1:
                            librosPrestadosASocioDeterminado(listaP,TAM);
                            system("pause");
                            break;
                        case 2:
                            libroDeterminadoPorSocios(listaP,TAM);
                            system("pause");
                            break;
                        case 3:
                            mostrarSociosMasSolicitadores(listaP,TAM);
                            system("pause");
                            break;
                        case 4:
                            librosMenosSolicitados(listaP, TAM);
                            system("pause");
                            break;
                        case 5:
                            libroEnFechaDeterminada(listaP,TAM);
                            system("pause");
                            break;
                        case 6:
                            totalGeneralYPromedioDiario(listaP, TAM);
                            system("pause");
                            break;
                        case 7:
                            ordenarSocios(lista, TAM);
                            system("pause");
                            break;
                        case 8:
                            ordenarLibrosPorTitulo(listaL,TAM);
                            system("pause");
                            break;
                        case 9:
                            printf("hasta luego...\n");
                            system("pause");
                            break;
                        default:
                            printf("opcion invalida, inbtente de nuevo...\n");
                            printf("ingrese a continuacion 'n'\n");
                            system("pause");
                            break;
                    }
                }
                while(opcionLista != 9);
                break;
            }
            else
            {
                printf("debe hacer un alta y un prestamo...\n");
                system("pause");
                break;
            }
        case 10:
            printf("\n confirmar salida s/n?...\n");
            fflush(stdin);
            confirmar = getche();

            if( tolower(confirmar)== 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("opcion invalida...\n");
            system("pause");
            break;
        }
    system("cls");
    }
    while(seguir == 's');


    return 0;
}
