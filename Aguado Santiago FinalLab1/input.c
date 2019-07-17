#include "input.h"

int esNum(char let[])
{
   int i=0;
   while(let[i] != '\0')
   {
       if(let[i] < '0' || let[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int esSoloLetras(char let[])
{
   int i=0;
   while(let[i] != '\0')
   {
       if((let[i] != ' ') && (let[i] < 'a' || let[i] > 'z') && (let[i] < 'A' || let[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    int retorno;
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        retorno = 1;
    }
    else
    {
        printf("debe usar letras...\n");
        retorno = 0;
    }
    return retorno;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    int retorno;
    if(esNum(aux))
    {
        strcpy(input,aux);
        retorno = 1;
    }
    else
    {
        printf("debe usar numeros...\n");
        retorno = 0;
    }

    return retorno;
}
