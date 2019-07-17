#include "Libros.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Libros* Libros_new()
{
    Libros* libros = (Libros*) malloc(sizeof(Libros));
    if(libros != NULL)
    {
        libros->id = 0;
        strcpy(libros->titulo, " ");
        strcpy(libros->autor, " ");
        libros->precio = 0;
        libros->editId = 0;
    }
    return libros;
}

int Libros_SetId(Libros* this, int id)
{
    int retorno = 0;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}

int Libros_GetId(Libros* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int libros_SetTitulo(Libros* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && strlen(titulo)>2)
    {
        strcpy(this->titulo,titulo);
        retorno = 1;
    }
    return retorno;
}

int libros_GetTitulo(Libros* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo,this->titulo);
        retorno = 1;
    }
    return retorno;
}

int libros_SetAutor(Libros* this, char* autor)
{
    int retorno = -1;
    if(this != NULL && strlen(autor)>2)
    {
        strcpy(this->autor,autor);
        retorno = 1;
    }
    return retorno;
}

int libros_GetAutor(Libros* this, char* autor)
{
    int retorno = -1;
    if(this != NULL && autor != NULL)
    {
        strcpy(autor,this->autor);
        retorno = 1;
    }
    return retorno;
}

int Libros_SetPrecio(Libros* this, int precio)
{
    int retorno = -1;
    if(this != NULL && precio > 0 && precio < 1000000)
    {
        this->precio = precio;
        retorno = 1;
    }
    return retorno;
}

int Libros_GetPrecio(Libros* this, int* precio)
{
    int retorno = -1;
    if(this != NULL && precio!= NULL)
    {
        *precio = this->precio;
        retorno = 1;
    }
    return retorno;
}

int Libros_SetEditId(Libros* this, int editId)
{
    int retorno = -1;
    if(this != NULL && editId>=0)
    {
        this->editId = editId;
        retorno = 1;
    }
    return retorno;
}

int Libros_GetEditId(Libros* this, int* editId)
{
    int retorno = -1;
    if(this != NULL && editId != NULL)
    {
        *editId = this->editId;
        retorno = 1;
    }
    return retorno;
}

int Libros_newParametros(char* idStr, char* titulo, char* autor, char* precioStr, char* idEditStr)
{
    Libros* nuevoLibro = Libros_new();
    int retorno = 0;
    if(nuevoLibro != NULL)
    {
        if(Libros_SetId(nuevoLibro,atoi(idStr))== 1)
        {
            if(libros_SetTitulo(nuevoLibro,titulo)== 1)
            {
                if(libros_SetAutor(nuevoLibro,autor)== 1)
                {
                    if(Libros_SetPrecio(nuevoLibro,atoi(precioStr))== 1)
                    {
                        if(Libros_SetEditId(nuevoLibro,atoi(idEditStr))== 1)
                        {
                            retorno = 1;
                        }
                    }
                }
            }
        }
    }
    if(retorno == 0)
    {
        free(nuevoLibro);
        nuevoLibro = NULL;
    }
    return retorno;
}


int Libros_sortId(void* pVoid1,void* pVoid2)
{
    int Id1,Id2,todoOk;
    Libros_GetEditId(pVoid1,&Id1);
    Libros_GetEditId(pVoid2,&Id2);
    if(Id2>Id1)
    {
        todoOk = 1;
    }
    return todoOk;
}
