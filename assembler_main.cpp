#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "assembler.h"
#include "debug.h"

const size_t label_size = 10;
const char file_name[] = {"text_comand.txt"};
const char translate[] = {"translation.txt"};

int main()
{
    size_t label_number = 0;
    struct label_t label[label_size] = {};
    FILE* file_text = fopen (file_name,"r");

    assert(file_text && "file open err");

    size_t num_s = sum_symbols (file_text);
    char* text_commad_in_array = (char*)calloc(num_s + 1, sizeof(char));

    assert (text_commad_in_array != NULL);
   
    size_t quentity_cells = 0;
    quentity_cells = QuannityCells (text_commad_in_array, file_text, num_s);
    printf ("quentity_cells = [%ld]", quentity_cells);
    quentity_cells = quentity_cells;
    int* command_array = (int*)calloc(quentity_cells, sizeof(int));

    assert (quentity_cells != NULL);

    DEBUG_PRINT ("\n quentity cells is {%ld}\n", quentity_cells); 

    for (int p = 0; p < quentity_cells; p++)
    {
        fprintf(stderr," command_array[%d] = [%d]\n", p, command_array[p]);
    }

    translation (command_array, text_commad_in_array, quentity_cells, label);

    for (int p = 0; p < quentity_cells; p++)
    {
        fprintf (stderr," command_array[%d] = [%d]\n", p, command_array[p]);
    }

    for (int k = 0; k < 10; k++)
    {
        fprintf (stderr,"label after translation is [%s]\n\n", label[k].label);
    }

    translation (command_array, text_commad_in_array, quentity_cells, label);

    for (int k = 0; k < 10; k++)
    {
        fprintf (stderr,"label after translation is [%s]\n\n", label[k].label);
    }

    for (int p = 0; p < quentity_cells; p++)
    {
        fprintf (stderr," command_array[%d] = [%d]\n", p, command_array[p]);
    }

    FILE* assembler = fopen (translate, "wb");
    fwrite (command_array, sizeof (command_array[0]), quentity_cells, assembler);

    free (command_array);
    free (text_commad_in_array);
}