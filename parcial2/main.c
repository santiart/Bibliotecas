#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "input.h"

int main()
{
    int flag = 0;
    LinkedList* listaPatentes = ll_newLinkedList();
    int option;
    char* auxOption = (char*)malloc(sizeof(char));
    do
    {

        printf("1_Cargar de texto  2_Guardar texto            \n");
        printf("3_Listar patentes  4_Seear tipo de patente    \n");
        printf("5_Salir...                                    \n");
        while(!getStringNumeros("ingrese una opcion: \n",auxOption))
        {
            printf("intente de nuevo...\n");
        }
        option = atoi(auxOption);
        switch(option)
        {
        case 1:
            controller_LoadfromText("datos.csv",listaPatentes);
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                controller_SaveAsText("datos.csv",listaPatentes);
                break;
            }
            else
            {
                printf("debe cargar los datos primero...\n");
                break;
            }
        case 3:
            if(flag == 1)
            {
            controller_ListPatente(listaPatentes);
            break;
            }
            else
            {
                printf("debe hacer primero una carga\n");
                break;
            }
        case 4:
            ll_map(listaPatentes,controller_Mapear);
            break;
        case 5:
            printf("hasta luego...\n");
            break;
        default:
            printf("opcion invalida...\n");
            break;
        }
        system("pause");
        system("cls");
    }while(option != 5);

    return 0;
}
