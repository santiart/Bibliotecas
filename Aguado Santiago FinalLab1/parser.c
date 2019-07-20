#include  "parser.h"

int parser_LibrosFromText(FILE* f, LinkedList* arrayList)
{
    Libros* libros;
    int cont = 0;
    char auxId[20];
    char auxTitulo[50];
    char auxAutor[50];
    char auxPrecio[20];
    char auxEditId[20];
    if(f != NULL)
    {
        fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxTitulo,auxAutor, auxPrecio, auxEditId);
        while(!feof(f))
        {


            fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId,auxTitulo,auxAutor, auxPrecio, auxEditId);
            libros = (Libros*)Libros_newParametros(auxId,auxTitulo,auxAutor,auxPrecio,auxEditId);
            //printf("%d\n",libros);
            if(libros != NULL)
            {
                ll_add(arrayList,(Libros*)libros);
                cont++;
            }
        }
    }
    return cont;
}
