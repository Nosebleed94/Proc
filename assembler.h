#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

size_t translation (int* arr, char* buffer, size_t quentity_cells);
size_t sum_symbols   (FILE* file_read);
size_t QuannityCells (char* buffer, FILE* file_text, size_t num_s);

#endif //ASSEMBLER_H
