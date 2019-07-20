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
        printf("1_ cargar en texto\n");
        printf("2_Ordenar por id de la editorial(ascendente)\n");
        printf("3_ listar Libros\n");
        // printf("4_\n");
        printf("5_Salir...      \n");
        while(!getStringNumeros("ingrese una opcion: \n", auxOPcion))
        {
            printf("intente de nuevo...\n");
        }
        opcion = atoi(auxOPcion);
        switch(opcion)
        {
        case 1:
            if(flag == 0)
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
            else
            {
                printf("ya ha realizado una carga...\n");
                break;
            }
        case 2:
            if(flag == 1)
            {
                controller_SortId(nuevaLista);
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
                controller_ListLibros(nuevaLista);
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
                //ll_map(nuevaLista,);
                break;
            }
            else
            {
                printf("debe cargar primero...\n");
                break;
            }
        case 5:
            printf("hasta luego");
            break;

        }
        system("pause");
        system("cls");
    }
    while(opcion != 5);
    return 0;
}

int pedirArchivo(char archivo[])
{
    int retorno = 0;
    if(strcmp(archivo,"datosMF2.csv")== 0)
    {
        retorno = 1;
    }
    return retorno;
}
