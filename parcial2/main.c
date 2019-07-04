#include <stdio.h>
#include <stdlib.h>

int main()
{
    int flag = 0;
    LinkedList* listaPatentes = ll_newLinkedList();
    int option;
    char* auxOption = (char*)malloc(sizeof(char));

    printf("1_Cargar de texto\n 2_Guardar texto");
    while(!getStringNumeros("ingrese una opcion: \n",auxOption))
    {
        printf("intente de nuevo...\n");
    }
    option = atoi(auxOption);
    switch(option)
    {
     case 1:
        dominio_LoadfromText("datos.csv",listaPatentes);
        flag == 1;
        break;
     case 2:
        if(flag == 1)
        {
            dominio_SaveAsText("datos.csv",listaPatentes);
            break;
        }
    }

    return 0;
}
