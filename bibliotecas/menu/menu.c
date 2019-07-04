#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int Opcion(float numero1, float numero2)
{
    int opcion;

    printf("Elija una opcion...\n");
    printf("\n 1_Ingresar primer numero...%.2f \n 2_Ingresar segundo numero...%.2f \n 3_Realizar los calculos...\n 4_Mostrar los resultados...\n 5_Salir...\n",numero1,numero2);
    scanf("%d",&opcion);

    return opcion;
}
