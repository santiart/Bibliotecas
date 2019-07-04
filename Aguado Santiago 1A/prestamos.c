#include "prestamos.h"


void inicializarPrestamos(ePrestamos vec[], int tam)
{
    int  i;
    for(i = 0; i < tam; i++)
    {
        vec[i].estado = 0;
    }
}

void mostrarPrestamo(ePrestamos prestamos)
{
    printf(" %10d    -%10d %5s  - %10d  %5s-        %d/%d/%d \n",
           prestamos.id, prestamos.codSoc,prestamos.nombreSocio,
           prestamos.codLib,prestamos.nombreLibro, prestamos.dia,prestamos.mes,prestamos.anio);
}

void mostrarPrestamos(ePrestamos prestamos[], int tam)
{
    int i;
    int contador = 0;
    printf("\n  Codigo Prestamo - Codigo Socio, Nombre Socio - Codigo Libro, Nombre Libro - Fecha de Prestamo \n\n");
    for(i = 0; i < tam; i++)
    {
        if(prestamos[i].estado == 1)
        {
            mostrarPrestamo(prestamos[i]);
            contador++;
        }
    }
    if(contador == 0)
    {
        printf("\n no hay prestamos para mostrar \n");
    }
}

int buscarLugarLibre(ePrestamos vec[],int tam)
{
    int i;
    int indice = -1;

    for (i = 0; i < tam; i++)
    {
        if(vec[i].estado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
int buscarPrestamo(ePrestamos vec[],int tam,int id)
{
    int indice = -1;
    int i;
    for(i = 0; i < tam ; i++)
    {
        if((vec[i].estado == 1)&&(vec[i].id == id))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarsocio(ePrestamos vec [], int tam, int id)
{
    int i;
    int indice = -1;

    for(i = 0; i < tam; i++)
    {
        if((vec[i].socios.estado == 1)&&(vec[i].socios.id == id))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarlibro(ePrestamos vec[], int tam, int id)
{
    int i;
    int indice = -1;
    for(i = 0; i < tam; i++)
    {
        if((vec[i].libros.estado == 1) &&(vec[i].libros.id == id))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscaFecha(ePrestamos prestamos[], int tamPrestamos, int dia, int mes, int anio)
{
    int i, indice = -1;

    for(i = 0; i < tamPrestamos; i++)
    {
        if((prestamos[i].dia == dia) && (prestamos[i].mes == mes) && (prestamos[i].anio == anio))
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaPrestamos(ePrestamos vec[], int tam)
{
    int codigo,indice,estaSocio,estaLibro,esta,idLibro,idSocio;
    char auxL[50];
    char auxS[50];
    char auxDia[50];
    char auxMes[50];
    char auxAnio[50];

    indice = buscarLugarLibre(vec,tam);
    if(indice == -1)
    {
        printf("no hay lugar disponible en el sistema...\n");
    }
    else
    {
        codigo = autoIncId();
        vec[indice].id = codigo;
        esta = buscarPrestamo(vec, tam, codigo);
        if(esta == -1)
        {
            while(!getStringNumeros("ingrese el codigo de Libro: \n",auxL))
            {
                printf("intente de nuevo...\n");
            }
            fflush(stdin);
            idLibro = atoi(auxL);
            estaLibro = buscarlibro(vec,tam,idLibro);
            if(estaLibro == -1)
            {
                printf("no existe el libro que ha ingresado...\n ");
            }
            else
            {
                vec[indice].libros = vec[estaLibro].libros;
                mostrarlibro(vec[indice].libros);
                vec[indice].codLib = vec[indice].libros.id;
                strcpy(vec[indice].nombreLibro,vec[indice].libros.nombre);
                while(!getStringNumeros("ingrese el codigo de socio: \n",auxS))
                {
                    printf("intente de nuevo...\n");
                }
                fflush(stdin);
                idSocio = atoi(auxS);
                estaSocio = buscarsocio(vec,tam,idSocio);
                if(estaSocio == -1)
                {
                    printf("no existe el socio que ha ingresado...\n");
                }
                else
                {
                    vec[indice].socios = vec[estaSocio].socios;
                    mostrarSocio(vec[indice].socios);
                    vec[indice].codSoc = vec[indice].socios.id;
                    strcpy(vec[indice].nombreSocio,vec[indice].socios.nombre);
                    while(!getStringNumeros("ingrese el dia de la fecha del prestamo: \n",auxDia))
                    {
                        printf("intente de nuevo...\n");
                    }
                    vec[indice].dia = atoi(auxDia);
                    while(!getStringNumeros("ingrese el mes de la fecha del prestamo: \n",auxMes))
                    {
                        printf("intente de nuevo...\n");
                    }
                    vec[indice].mes = atoi(auxMes);
                    while(!getStringNumeros("ingrese el anio de la fecha del prestamo: \n",auxAnio))
                    {
                        printf("intente de nuevo...\n");
                    }
                    vec[indice].anio = atoi(auxAnio);
                    vec[indice].estado = 1;

                    printf("Alta de prestamo exitosa!!!\n\n");
                }
            }
        }
    }
}

int autoIncId()
{
    static int id = -1;
    id++;
    return id;
}

void mostrarSociosMasSolicitadores(ePrestamos prestamos[], int tamPrestamos)
{
    int i, socioMas,solicitudPrestamo = 0,contPres;

    for(i = 0; i < tamPrestamos; i++)
    {
        contPres = 0;
        if(prestamos[i].codSoc == prestamos[i].socios.id)
        {
            contPres++;
        }
    }
    if(i == 0)
    {
        socioMas = i;
        solicitudPrestamo = contPres;
    }
    else if(contPres > solicitudPrestamo)
    {
        socioMas = i;
        solicitudPrestamo = contPres;
    }
    printf("el socio al que mas se le presto es: \n");
    mostrarSocio(prestamos[socioMas].socios);
}

void librosMenosSolicitados(ePrestamos prestamos[], int tam)
{
    int i, libroMenos, solicitudPrestamo = 0, contPres;

    for(i = 0; i < tam; i++)
    {
        contPres = 0;
        if(prestamos[i].codLib == prestamos[i].libros.id)
        {
            contPres++;
        }
    }
    if(i == 0)
    {
        libroMenos = i;
        solicitudPrestamo = contPres;
    }
    else if(contPres < solicitudPrestamo)
    {
        libroMenos = i;
        solicitudPrestamo = contPres;
    }
    printf("el libro menos solicitado es: \n");
    mostrarlibro(prestamos[libroMenos].libros);
}

void librosPrestadosASocioDeterminado(ePrestamos prestamos[], int tamPrestamos)
{
    int i,estaSoc,id;
    int encontro = 0;
    char codSoc[20];

    while(!getStringNumeros("ingrese el numero de socio: \n",codSoc))
    {
        printf("intente de nuevo...\n");
    }
    fflush(stdin);
    id = atoi(codSoc);
    estaSoc = buscarsocio(prestamos, tamPrestamos,id);

    if(estaSoc== -1)
    {
        printf("no existe el socio que ingreso...\n");
    }
    else
    {
        for(i = 0; i < tamPrestamos; i++)
        {
            if((prestamos[i].codSoc == atoi(codSoc)) &&(prestamos[i].estado == 1))
            {
                printf("titulo: %s\n - id: %d\n",prestamos[i].nombreLibro,prestamos[i].codLib);
                encontro++;
            }
        }
        if(encontro == 0)
        {
            printf("no se han realizado prestamos al socio:  %s \n",prestamos[estaSoc].socios.nombre);
        }
    }
}

void libroDeterminadoPorSocios(ePrestamos prestamos[], int tamPrestamos)
{
    int i, estaLib,id;
    int encontro = 0;
    char codLib[20];

    while(!getStringNumeros("ingres el codigo del libro: \n",codLib))
    {
        printf("intente de nuevo...\n");
    }
    fflush(stdin);
    id = atoi(codLib);
    estaLib = buscarlibro(prestamos,tamPrestamos,id);

    if(estaLib == -1)
    {
        printf("no existe el libro que ingreso...\n");
    }
    else
    {
        for(i = 0; i < tamPrestamos; i++)
        {
            if(prestamos[i].codLib == atoi(codLib))
            {
                printf("Socio: %s id:  %d\n",prestamos[i].nombreSocio,prestamos[i].codSoc);
                encontro++;
            }
        }
        if(encontro == 0)
        {
            printf("ningun socio ha solicitado el libro: %s\n",prestamos[estaLib].libros.nombre);
        }
    }
}

void libroEnFechaDeterminada(ePrestamos prestamos[], int tamPrestamos)
{
    int i,estaFecha,encontro = 0;
    char auxDia[20],auxMes[20],auxAnio[20];

    while(!getStringNumeros("ingrese el dia del prestamo: \n", auxDia))
    {
        printf("intente de nuevo...\n");
    }
    while(!getStringNumeros("ingrese el mes del prestamo: \n", auxMes))
    {
        printf("intente de nuevo...\n");
    }
    while(!getStringNumeros("ingrese el anio del prestamo: \n", auxAnio))
    {
        printf("intente de nuevo...\n");
    }
    estaFecha = buscaFecha(prestamos, tamPrestamos,atoi(auxDia), atoi(auxMes), atoi(auxAnio));

    if(estaFecha == -1)
    {
        printf("la fecha que ingreso no es valida...\n");
    }
    else
    {
        for(i = 0; i < tamPrestamos; i++)
        {
            if((prestamos[i].dia == atoi(auxDia) && (prestamos[i].mes == atoi(auxMes)) && (prestamos[i].anio)))
            {
                mostrarPrestamo(prestamos[i]);
                encontro++;
            }
        }
        if(encontro == 0)
        {
            printf("ningun prestamo se realizo en esa fecha...\n");
        }
    }
}
