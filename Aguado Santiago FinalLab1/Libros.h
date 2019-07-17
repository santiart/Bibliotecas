#ifndef _LIBROS
#define _LIBROS

typedef struct
{
    int id;
    char nombre[];
}Editorial;

typedef struct
{
    int id;
    char titulo[50];
    char autor[50];
    int precio;
    int editId;
}Libros;

Libros* Libros_new();
int Libros_newParametros(char* idstr, char* titulo, char* autor, char* precioStr, char* idEditStr);
int Libros_SetId(Libros* this, int id);
int Libros_GetId(Libros* this, int* id);
int libros_SetTitulo(Libros* this, char* titulo);
int libros_GetTitulo(Libros* this, char* titulo);
int libros_SetAutor(Libros* this, char* autor);
int libros_GetAutor(Libros* this, char* autor);
int Libros_SetPrecio(Libros* this, int precio);
int Libros_GetPrecio(Libros* this, int* precio);
int Libros_SetEditId(Libros* this, int editId);
int Libros_GetEditId(Libros* this, int* editId);
int Libros_sortId(void* pVoid1,void* pVoid2);
#endif // _LIBROS
