#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "processor.h"
#include "debug.h"

const char translate[] = "translation.txt";

int main()
{
    FILE* assembler = fopen(translate, "r");

    assert (assembler && "file open err");

    size_t quentity_cells = 0;
    fseek(assembler, 0, SEEK_END);
    quentity_cells = ftell(assembler) / sizeof(int);
    fseek(assembler, 0, SEEK_SET);

    int* command_array = (int*)calloc(quentity_cells, sizeof(int));

    assert (command_array != NULL);

    fread(command_array, sizeof(int), quentity_cells, assembler);

    Letsgo (command_array, quentity_cells);

    fclose(assembler);
}