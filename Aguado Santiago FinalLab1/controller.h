#include <stdlib.h>
#include <stdio.h>
#include "Libros.h"
#include "parser.h"
#include "input.h"

int controller_loadFromText(char* path, LinkedList* arrayList);
int controller_ListLibros(LinkedList* arrayList);
int controller_SortId(LinkedList* arrayList);
