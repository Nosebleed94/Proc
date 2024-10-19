#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "assembler.h"
#include "processor.h"
#include "debug.h"

const char file_name[] = {"text_comand.txt"};
int main (void){
    FILE* file_text = fopen(file_name,"r");
    assert(file_text && "file open err");

    size_t num_s = sum_symbols (file_text);
    char* buffer = (char*)calloc(num_s + 1, sizeof(char));
    assert (buffer != NULL);
   
    size_t quentity_cells = 0;
    quentity_cells = QuannityCells (buffer, file_text, num_s);
    int* arr = (int*)calloc(quentity_cells, sizeof(int));
    assert (quentity_cells != NULL);

    DEBUG_PRINT("\n quentity cells is {%ld}\n", quentity_cells); 

    translation (arr, buffer, quentity_cells);

    Letsgo (arr, quentity_cells);

    return 0;
}