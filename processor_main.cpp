#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "assembler.h"
#include "processor.h"
#include "debug.h"
#include "stack.h"

const char translate[] = "translation.txt";

int main(){

    FILE* assembler = fopen(translate, "r");
    assert(assembler && "file open err");

    size_t quentity_cells = 0;
    fseek(assembler, 0, SEEK_END);
    quentity_cells = ftell(assembler) / sizeof(int);
    fseek(assembler, 0, SEEK_SET);

    int* arr = (int*)calloc(quentity_cells, sizeof(int));
    assert(arr != NULL);

    fread(arr, sizeof(int), quentity_cells, assembler);

    Letsgo(arr, quentity_cells);

    fclose(assembler);
}