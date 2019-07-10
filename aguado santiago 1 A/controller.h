#include <stdlib.h>
#include <stdio.h>
#include "peliculas.h"
#include "parser.h"
#include "input.h"

int controller_loadFromText(char* path, LinkedList* arrayList);
int controller_ListPeliculas(LinkedList* arrayList);
int controller_SortId(LinkedList* arrayList);
