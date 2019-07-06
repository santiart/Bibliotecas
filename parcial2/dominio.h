#ifndef DOMINIO_H_INCLUDED
#define DOMINIO_H_INCLUDED
#include "LinkedList.h"
#include <stdlib.h>

typedef struct
{
    int id,anio;
    char dominio[10];
    char tipo;
}Dominio;

int dominio_New();
int dominio_NewParametros(char* idStr, char* anioStr,char* dominioStr);
int dominio_setId(Dominio* this, int id);
int dominio_getId(Dominio* this, int* id);
int dominio_setAnio(Dominio* this, int anio);
int dominio_getAnio(Dominio* this, int* anio);
int dominio_setDominio(Dominio* this, char* dominio);
int dominio_getDominio(Dominio* this, char* dominio);
int dominio_setTipo(Dominio* this, char tipo);
int dominio_getTipo(Dominio* this, char* tipo);
#endif // DOMINIO_H_INCLUDED
