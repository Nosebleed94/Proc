#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "general_enum.h"
#include "assembler.h"
#include "debug.h"

const char push[] =                "push";
const char adition[] =             "adition";
const char subtraction[] =         "subtraction";
const char multiplication[] =      "multiplication";
const char division[] =            "division";
const char out[] =                 "out";
const char hlt[] =                 "hlt";
const char ja[] =                  "ja";
const char jae[] =                 "jae";
const char jb[] =                  "jb";
const char jbe[] =                 "jbe";
const char je[] =                  "je";
const char jne[] =                 "jne";
const char jmp[] =                 "jmp";
const char rgstprush_ax[] =        "rgstprush_ax";
const char rgstprush_bx[] =        "rgstprush_bx";
const char rgstprush_cx[] =        "rgstprush_cx";
const char rgstprush_dx[] =        "rgstprush_dx";
const char pop_ax[] =              "pop_ax";
const char pop_bx[] =              "pop_bx";
const char pop_cx[] =              "pop_cx";
const char pop_dx[] =              "pop_dx";
const char dumb[] =                "dumb";
const char next[] =                "NEXT:";

size_t translation (int* command_array, char* text_commad_in_array, size_t quentity_cells, label_t* label)
{
    assert (command_array != NULL);
    assert (text_commad_in_array != NULL);

    size_t label_numder = 0;
    size_t i = 0;
    size_t k = 0;
    size_t len = 0;
    char* istr = {};
    
    fprintf (stderr, "\n Translation started with quentity_cells = %lu\n", quentity_cells);

    while (k != quentity_cells)
    {
        size_t p = 0;
        char ch = ':';
        char* subbufer= {};
        char* found = strchr_custom (text_commad_in_array, ch);

        if (found != NULL)
        {
            len = found - text_commad_in_array + 1;
            label[label_numder].label = strndup (text_commad_in_array, len);
            label[label_numder].ip_label = i;
            text_commad_in_array += len + 1;
            k++;
            label_numder++;
        } 

        fprintf(stderr," i = [%ld]\n", i);

        if (strncmp (text_commad_in_array, push, strlen(push)) == 0)
        {
            fprintf (stderr,"text_commad_in_array = %s\n", text_commad_in_array);
            command_array[i] = my_push;
            text_commad_in_array += strlen(push) + 1; 
            i++;
            k++;
            ArgumentCheck (&text_commad_in_array,  command_array, &i, &k);
        }

        else if (strncmp (text_commad_in_array, adition, strlen(adition)) == 0)
        {
            command_array[i] = my_adition;
            text_commad_in_array += strlen(adition) + 1;
            i++;
            k++;
        } 

        else if (strncmp (text_commad_in_array, subtraction, strlen(subtraction)) == 0)
        {
            command_array[i] = my_subtraction;
            text_commad_in_array += strlen(subtraction) + 1;
            i++;
            k++;
        } 

        else if (strncmp (text_commad_in_array, multiplication, strlen(multiplication)) == 0)
        {
            command_array[i] = my_multiplication;
            text_commad_in_array += strlen(multiplication) + 1;
            i++;
            k++;
        } 

        else if (strncmp (text_commad_in_array, division, strlen(division)) == 0)
        {
            command_array[i] = my_division;
            text_commad_in_array += strlen(division) + 1;
            i++;
            k++;
        } 

        else if (strncmp (text_commad_in_array, out, strlen(out)) == 0)
        {
            command_array[i] = my_out;
            text_commad_in_array += strlen(out) + 1;
            i++;
            k++;
        } 

        else if (strncmp (text_commad_in_array, hlt, strlen(hlt)) == 0)
        {
            command_array[i] = my_hlt;
            text_commad_in_array += strlen(hlt) + 1;
            i++;
            k++;
        }

        else if (strncmp (text_commad_in_array, ja, strlen(ja)) == 0)
        {
            command_array[i] = my_ja;
            text_commad_in_array += strlen(ja) + 1;
            i++;
            k++;
            mark (&text_commad_in_array,  command_array, label, &i, &k, label_numder);
        }
        
        else if (strncmp (text_commad_in_array, jae, strlen(jae)) == 0)
        {
            command_array[i] = my_jae;
            text_commad_in_array += strlen(jae) + 1;
            i++;
            k++;
            mark (&text_commad_in_array,  command_array, label, &i, &k, label_numder);
        }

        else if (strncmp (text_commad_in_array, jb, strlen(jb)) == 0)
        {
            command_array[i] = my_jb;
            text_commad_in_array += strlen(jb) + 1;
            i++;
            k++;
            mark (&text_commad_in_array,  command_array, label, &i, &k, label_numder);
        }

        else if (strncmp (text_commad_in_array, jbe, strlen(jbe)) == 0)
        {
            command_array[i] = my_jbe;
            text_commad_in_array += strlen(jbe) + 1;
            i++;
            k++;
            mark (&text_commad_in_array,  command_array, label, &i, &k, label_numder);
        }

        else if (strncmp (text_commad_in_array, je, strlen(je)) == 0)
        {
            command_array[i] = my_je;
            text_commad_in_array += strlen(je) + 1;
            i++;
            k++;
            mark (&text_commad_in_array,  command_array, label, &i, &k, label_numder);
        }

        else if (strncmp (text_commad_in_array, jne, strlen(jne)) == 0)
        {
            command_array[i] = my_jne;
            text_commad_in_array += strlen(jne) + 1;
            i++;
            k++;
            mark (&text_commad_in_array,  command_array, label, &i, &k, label_numder);
        }

        else if (strncmp (text_commad_in_array, jmp, strlen(jmp)) == 0)
        {
            command_array[i] = my_jmp;
            text_commad_in_array += strlen(jmp) + 1;
            i++;
            k++;
            mark (&text_commad_in_array,  command_array, label, &i, &k, label_numder);
        }

        else if (strncmp (text_commad_in_array, rgstprush_ax, strlen(rgstprush_ax)) == 0)
        { 
            command_array[i] = my_rgstprush_ax;
            text_commad_in_array += strlen(rgstprush_ax) + 1;
            i++;
            k++;
        }

        else if (strncmp (text_commad_in_array, rgstprush_bx, strlen(rgstprush_bx)) == 0)
        {
            command_array[i] = my_rgstprush_bx;
            text_commad_in_array += strlen(rgstprush_bx) + 1;
            i++;
            k++;
        }

        else if (strncmp (text_commad_in_array, rgstprush_cx, strlen(rgstprush_cx)) == 0)
        {
            command_array[i] = my_rgstprush_cx;
            text_commad_in_array += strlen(rgstprush_cx) + 1;
            i++;
            k++;
        }

        else if (strncmp (text_commad_in_array, rgstprush_dx, 9) == 0)
        { //что за  алееееееее
            command_array[i] = my_rgstprush_dx;
            text_commad_in_array += 10;
            i++;
            k++;
        }

        else if (strncmp (text_commad_in_array, pop_ax, strlen(pop_ax)) == 0)
        {
            command_array[i] = my_pop_ax;
            text_commad_in_array += strlen(pop_ax) + 1;
            i++;
            k++;
            fprintf(stderr,"i = [%ld]", i);
        }

        else if (strncmp (text_commad_in_array, pop_bx, strlen(pop_bx)) == 0)
        {
            command_array[i] = my_pop_bx;
            text_commad_in_array += strlen(pop_bx) + 1;
            i++;
            k++;
        }

        else if (strncmp (text_commad_in_array, pop_cx, strlen(pop_cx)) == 0)
        {
            command_array[i] = my_pop_cx;
            text_commad_in_array += strlen(pop_cx) + 1;
            i++;
            k++;
        }

        else if (strncmp (text_commad_in_array, pop_dx, strlen(pop_dx)) == 0)
        {
            command_array[i] = my_pop_dx;
            text_commad_in_array += strlen(pop_dx) + 1;
            i++;
            k++;
        }

        else if (strncmp (text_commad_in_array, dumb, strlen(dumb)) == 0)
        {
            command_array[i] = my_dumb;
            text_commad_in_array += strlen(dumb) + 1;
            i++; // FIXME вынести i++ k++
            k++;
        }

        // FIXME написать функцию проверки на пустую строку
        else if (text_commad_in_array[0] == 10 )
        {
            text_commad_in_array++;
        }

        else
        {
            fprintf (stderr,"DUMAY, DUMAY!!!");
            exit(1); 
        }
    }
    
    return 0; // FIXME он всегда возвращает 0
}

size_t sum_symbols (FILE* file_read)
{
    assert (file_read != NULL && "file open err");

    fseek (file_read, 0, SEEK_END);
    size_t symbols = (size_t)ftell(file_read);
    fseek (file_read, 0, SEEK_SET);
    DEBUG_PRINT ("\n Number of symbols in file is %ld\n", symbols);

    return symbols;
}

// FIXME какие клетки нахуй, че с неймингом
size_t QuannityCells (char* text_commad_in_array, FILE* file_text, size_t num_s)
{
    assert (text_commad_in_array != NULL); 
    assert (file_text != NULL && "file open err");

    fread (text_commad_in_array, sizeof(char), num_s, file_text);
    size_t helper = 0;
    
    for (size_t i = 0; i < num_s; i++)
    {
        if (isspace (text_commad_in_array[i]))
        {
            helper++;
        }
    }

    DEBUG_PRINT ("\n QuannityCells ended with helper = %ld\n", helper);
    return helper;
}

// FIXME параметры i k это что нахуй за имя
void ArgumentCheck (char** text_commad_in_array, int* command_array, size_t* i, size_t* k)
{
    assert (command_array != NULL);
    assert (text_commad_in_array != NULL);

    int flag = 1;
    int result = 0;
    size_t sum = 0;        
    if (**text_commad_in_array == '-')
    {
        flag = -1;
        text_commad_in_array++; 
    }

    char* endptr = NULL;
    result = strtol (*text_commad_in_array, &endptr, 10);
    *text_commad_in_array = endptr;            
    result *= flag;
    command_array[*i] = result;
    (*i)++; // FIXME нахуй тогда передавать указатель?
    (*k)++; 
    *text_commad_in_array++; 
}
    
char* strchr_custom (char* text_commad_in_array, char ch)
{
    assert (text_commad_in_array != NULL);

    while (*text_commad_in_array != '\0' && *text_commad_in_array != ' ' && *text_commad_in_array != '\n')
    {
        if (*text_commad_in_array == ch)
        {
            return (char*)text_commad_in_array; 
        }
        text_commad_in_array++;
    }

    return NULL; 
}

void mark (char** text_commad_in_array, int* command_array, label_t* label, size_t* i, size_t* k, size_t label_numder)
{
    assert ( command_array != NULL);
    assert (text_commad_in_array != NULL);

    for (int couter = 0; couter < label_numder; couter++)
    {
        if (strncmp (*text_commad_in_array, label[couter].label, strlen(label[couter].label)) == 0)
        {
            command_array[*i] = label[couter].ip_label;
            (*i)++;
            (*k)++;
            *text_commad_in_array += strlen(label[couter].label) + 1;
        }

        else
        {
            command_array[*i] = 0;
            (*i)++;
            (*k)++;
            while (**text_commad_in_array != ' '){
                *text_commad_in_array += 1;
            }
            *text_commad_in_array += 1;
        }
    }
}
