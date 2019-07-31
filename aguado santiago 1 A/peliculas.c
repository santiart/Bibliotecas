#include "peliculas.h"
#include "input.h"
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
        this->id = id;
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
    if(Id1<Id2)
    {
        todoOk = 1;
    }
    return todoOk;
}

int depurarPeliculas(LinkedList* this)
{
    ePelicula* Pelicula1;
    ePelicula* Pelicula2;
    ePelicula* Pelicula3;
    char* genero1 = (char*)malloc(sizeof(char));
    char* genero2 = (char*)malloc(sizeof(char));
    int i, j,x,retorno = 0;
    for(i = 0; i < ll_len(this)-1; i++)
    {
        for(j = i+1; j < ll_len(this); j++)
        {
            for(x = j+1; x < ll_len(this); x++)
            {
                Pelicula1 = (ePelicula*)ll_get(this,i);
                Pelicula2 = (ePelicula*)ll_get(this,j);
                Pelicula3 = (ePelicula*)ll_get(this,j);

                if(strcmp(Pelicula2->nombre,Pelicula1->nombre)==0
                   && strcmp(Pelicula3->nombre,Pelicula1->nombre)==0)
                {
                    strcpy(genero1,Pelicula2->genero);
                    strcpy(genero2,Pelicula3->genero);
                    strcat(Pelicula1->genero,genero1);
                    strcat(genero1,genero2);
                    ll_remove(this,j);
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}


int filtrarPorGenero(void* void1)
{
    int retorno = 0,opcion;
    char auxopcion[50];
    char* genero = (char*)malloc(sizeof(char)*20);
    printf("1_accion  2_aventura  3_animacion   4_ciencia ficcion\n");
    printf("5_comedia 6_familiar  7_fantasia  8_drama  9_infantil\n");
    while(!getStringNumeros("ingrese el genero que quiere filtrar: \n", auxopcion))
    {
        printf("intente de nuevo...\n");
    }
    opcion = atoi(auxopcion);
    switch(opcion)
    {
        case 1:
            printf("aca no creo\n");
            genero = "accion";
            if(peliculas_getGenero(void1,genero)==1)
            {
                printf("aca pueded ser\n");
                retorno = 1;
                break;
            }
            else
            {
                printf("no se encuentra el genero...\n");
                break;
            }
        case 2:
            peliculas_getGenero(void1,"aventura");
            retorno = 1;
            break;
        case 3:
            peliculas_getGenero(void1,"animacion");
            retorno = 1;
            break;
        case 4:
            peliculas_getGenero(void1,"ciencia ficcion");
            retorno = 1;
        break;
        case 5:
            peliculas_getGenero(void1,"comedia");
            retorno = 1;
            break;
        case 6:
            peliculas_getGenero(void1,"familiar");
            retorno = 1;
            break;
        case 7:
            peliculas_getGenero(void1,"fantasia");
            retorno = 1;
            break;
        case 8:
            peliculas_getGenero(void1,"drama");
            retorno = 1;
            break;
        case 9:
            peliculas_getGenero(void1,"infantil");
            retorno = 1;
            break;
        default:
            printf("no existe el genero que ingreso...\n");
            system("pause");
            break;
    }
    return retorno;
}
