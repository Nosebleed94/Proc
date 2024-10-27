#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

struct label_t
{
    size_t ip_label;
    char* label;
};

// FIXME должна быть структура ассемблера которая хранит всё что нужно (СДЕЛАЮЮЮ, Спешу)
// FIXME фунция-конструктор для ассемблера, в ней всё открывает и выделяется
// FIXME функция-деструктор для ассемюлера, в ней всё закрывает(что должно закрыться) и очищается 

size_t translation     (int*  command_array, char* text_commad_in_array, size_t quentity_cells, label_t* label);
size_t sum_symbols     (FILE* file_read);
size_t QuannityCells   (char* text_commad_in_array, FILE* file_text, size_t num_s);
void ArgumentCheck     (char** text_commad_in_array, int*  command_array, size_t* i, size_t* k);
char* strchr_custom    (char* text_commad_in_array, char ch);
void mark              (char** text_commad_in_array, int*  command_array, label_t* label, size_t* i, size_t* k, size_t label_numder);

#endif //ASSEMBLER_H
