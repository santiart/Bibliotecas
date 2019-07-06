#include "LinkedList.h"
#include "dominio.h"
#include "parser.h"
int controller_LoadfromText(char* path,LinkedList* pArrayPatente);
int controller_SaveAsText(char* path, LinkedList* pArrayPatente);
int controller_ListPatente(LinkedList* pArrayPatente);
int controller_Mapear(void* patente);
