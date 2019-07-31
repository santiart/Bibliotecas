#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "input.h"

int pedirArchivo(char archivo[]);
int main()
{
    int opcion;
    char auxOPcion[20];
    int flag = 0;
    char nombreArchivo[20];
    int archivo;
    LinkedList* nuevaLista = ll_newLinkedList();
    do
    {
        printf(" ::PELICULAS::        \n\n");
        printf("1_ cargar en texto\n");
        printf("2_ listar peliculas\n");
        printf("3_Ordenar por id (descendente)\n");
        printf("4_Depurar peliculas\n");
        printf("5_Filtrar pelicula por genero\n");
        printf("6_filtrar peliculas depuradas\n");
        printf("7_Salir...      \n");
        while(!getStringNumeros("ingrese una opcion: \n", auxOPcion))
        {
            printf("intente de nuevo...\n");
        }
        opcion = atoi(auxOPcion);
        switch(opcion)
        {
        case 1:
            if(flag == 1)
            {
                printf("ya se ha hecho la carga...\n");
                break;
            }
            else
            {

                printf("ingrese el archivo: \n");
                scanf("%s",nombreArchivo);
                archivo = pedirArchivo(nombreArchivo);
                if(archivo == 1)
                {
                    controller_loadFromText(nombreArchivo,nuevaLista);
                    flag = 1;
                    break;
                }
                else
                {
                    printf("archivo inexistente...\n");
                    break;
                }
            }
        case 2:
            if(flag == 1)
            {
                controller_ListPeliculas(nuevaLista);
                break;
            }
            else
            {
                printf("cargue primero\n");
                break;
            }
        case 3:
            if(flag == 1)
            {
                controller_SortId(nuevaLista);
                break;
            }
            else
            {
                printf("debe cargar primero...\n");
                break;
            }
        case 4:
            if(flag == 1)
            {
                depurarPeliculas(nuevaLista);
                break;
            }
            else
            {
                printf("debe cargar primero...\n");
                break;
            }
        case 5:
            if(flag == 1)
            {
                ll_filter(nuevaLista, filtrarPorGenero);
                break;
            }
            else
            {
                printf("debe cargar primero...\n");
                break;
            }
        /*
        case 6:
        break;
        */
        case 7:
            printf("hasta luego\n");
            break;

        }
        system("pause");
        system("cls");
    }
    while(opcion != 7);
    return 0;
}

int pedirArchivo(char archivo[])
{
    int retorno = 0;
    if(strcmp(archivo,"datosMF1.csv")== 0)
    {
        retorno = 1;
    }
    return retorno;
}
