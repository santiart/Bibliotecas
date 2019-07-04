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
    fflush(stdin);
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

int esAlfaNumerico(char mensaje[], char str[])
{
    int i=0;
    getString(mensaje, str);
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

int esEmail(char mensaje[], char str[])
{
    int i=0;
    int contadorArrobas=0;
    int retorno;
    getString(mensaje,str);
    while(str[i] != '\0')
    {
        if(
            (str[i] != ' ') &&
            (
                ((str[i] < 'a') || (str[i] > 'z')) &&
                ((str[i] < 'A') || (str[i] > 'Z')) &&
                ((str[i] < '0' || str[i] > '9'))&&
                (str[i]=='@') && (str[i] == '.')
             )
        )
        retorno = 0;
        if(str[i] == '@')
        {

            contadorArrobas++;
        }
        i++;
    }
    return retorno;
}
int esTelefono(char mensaje[], char str[])
{
    int i=0;
    char aux[256];
    getString(mensaje, aux);
    while(aux[i] != '\0')
    {
        if((aux[i] != ' ') && (aux[i] < '0' || aux[i] > '9'))
            return 0;
            break;
    }

    return 1;
}
