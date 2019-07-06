#include "dominio.h"
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include <string.h>

int dominio_New()
{
    Dominio* patente = (Dominio*)malloc(sizeof(Dominio));
    if(patente != NULL)
    {
        patente->anio = 0;
        strcpy(patente->dominio, " ");
        patente->id = 0;
    }
    return patente;
}

int dominio_setAnio(Dominio* this, int anio)
{
    int retorno = 0;
    if(this != NULL && anio > 1950 || anio < 2500)
    {
        this->anio = anio;
        retorno = 1;
    }
    return retorno;
}

int dominio_getAnio(Dominio* this, int* anio)
{
    int retorno = 0;
    if(this != NULL && anio != NULL)
    {
        *anio = this->anio;
        retorno = 1;
    }
    return retorno;
}

int dominio_setId(Dominio* this, int id)
{
    int retorno = 0;
    if(this != NULL && id>=0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

int dominio_getId(Dominio* this, int* id)
{
    int retorno = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}
int dominio_setDominio(Dominio* this, char* dominio)
{
    int retorno = 0;
    if(this != NULL && strlen(dominio)>= 6)
    {
        strcpy(this->dominio,dominio);
        retorno = 1;
    }
    return retorno;
}

int dominio_getDominio(Dominio* this,char* dominio)
{
    int retorno = 0;
    if(this != NULL && dominio != NULL)
    {
        strcpy(dominio,this->dominio);
        retorno = 1;
    }
    return retorno;
}

int dominio_setTipo(Dominio* this, char tipo)
{
    int retorno = 0;
    if(this != NULL && tipo == 'A' || tipo == 'a' || tipo =='M' || tipo =='m')
    {
        this->tipo = tipo;
        retorno = 1;
    }
    return retorno;
}

int dominio_getTipo(Dominio* this,char* tipo)
{
    int retorno = 0;
    if(this != NULL && tipo != NULL)
    {
        tipo = this->tipo;
        retorno = 1;
    }
    return retorno;
}

int dominio_NewParametros(char* idStr, char* anioStr,char* dominioStr)
{
    Dominio* patente = dominio_New();
    int retorno = 1;
    if(patente != NULL)
    {
        if((dominio_setAnio(patente,atoi(anioStr)))==1)
        {
            if((dominio_setId(patente,atoi(idStr)))==1)
            {
                if((dominio_setDominio(patente,dominioStr))==1)
                {
                    retorno = 0;
                }
            }
        }
        if(retorno == 1)
        {
            free(patente);
            patente = NULL;
        }
    }
    return patente;
}
