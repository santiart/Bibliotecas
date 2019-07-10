#include "peliculas.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int pelicula_new()
{
    ePelicula* peliculas = (ePelicula*)malloc(sizeof(ePelicula));
    if(peliculas != NULL)
    {
        peliculas->id = 0;
        peliculas->anio = 0;
        strcpy(peliculas->nombre, " ");
        strcpy(peliculas->genero, " ");
    }
    return peliculas;
}

int peliculas_newParametros(char* idStr, char* nombreStr, char* anioStr, char*generoStr)
{
    ePelicula* nuevaPelicula = pelicula_new();
    int retorno = 0;
    if(nuevaPelicula != NULL)
    {
        if(peliculas_setId(nuevaPelicula, atoi(idStr)) == 1)
        {
            if(peliculas_setAnio(nuevaPelicula,atoi(anioStr))== 1)
            {
                if(peliculas_setNombre(nuevaPelicula,nombreStr) == 1)
                {
                    if(peliculas_setGenero(nuevaPelicula, generoStr) == 1)
                    {
                        retorno = 1;
                    }
                }
            }
        }
        if(retorno == 0)
        {
            free(nuevaPelicula);
            nuevaPelicula = NULL;
        }
    }
    return nuevaPelicula;
}

int peliculas_setId(ePelicula* this, int id)
{
    int retorno = 0;
    if(this != NULL)
    {
        this->id = (id + 1);
        retorno = 1;
    }
    return retorno;
}
int peliculas_getId(ePelicula* this, int *id)
{
    int retorno = 0;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}
int peliculas_setAnio(ePelicula* this, int anio)
{
    int retorno = 0;
    if(this != NULL && anio > 2000 && anio < 2100)
    {
        this-> anio = anio;
        retorno = 1;
    }
    return retorno;
}

int peliculas_getAnio(ePelicula* this, int* anio)
{
    int retorno = 0;
    if(this != NULL && anio != NULL)
    {
        *anio = this->anio;
        retorno = 1;
    }
    return retorno;
}
int peliculas_setNombre(ePelicula* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL && strlen(nombre) > 3)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int peliculas_getNombre(ePelicula* this, char* nombre)
{
    int retorno = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
    return retorno;
}

int peliculas_setGenero(ePelicula* this, char* genero)
{
    int retorno = 0;
    if(this != NULL && strlen(genero)>3)
    {
        strcpy(this->genero,genero);
        retorno = 1;
    }
    return retorno;
}

int peliculas_getGenero(ePelicula* this, char* genero)
{
    int retorno = 0;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero,this->genero);
        retorno = 1;
    }
    return retorno;
}

int peliculas_sortId(void* pVoid1,void* pVoid2)
{
    int Id1,Id2,todoOk;
    peliculas_getId(pVoid1,&Id1);
    peliculas_getId(pVoid2,&Id2);
    if(Id1>Id2)
    {
        todoOk = 1;
    }
    return todoOk;
}

int depurarPeliculas(LinkedList* this)
{
    ePelicula* Pelicula1;
    char* generos = (char*)malloc(sizeof(char));
    ePelicula* Pelicula2;
    int i, j,retorno = 0;
    for(i = 0; i < ll_len(this)-1; i++)
    {
        for(j = i+1; j < ll_len(this); j++)
        {
            Pelicula1 = (ePelicula*)ll_get(this,i);
            Pelicula2 = (ePelicula*)ll_get(this,j);

            if(strcmp(Pelicula1->nombre,Pelicula2->nombre)==0)
            {
                strcpy(Pelicula1->genero,generos);
                strcat(generos,Pelicula2->genero);
                ll_remove(this,i);
                retorno=1;
            }
        }
    }
    return retorno;
}
