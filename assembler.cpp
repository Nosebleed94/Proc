#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

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


enum stack_operation {
    my_push               =   1,
    my_adition            =   2,
    my_subtraction        =   3,
    my_multiplication     =   4,
    my_division           =   5,
    my_out                =   6,
    my_ja                 =   7,
    my_jae                =   8,
    my_jb                 =   9,
    my_jbe                =   10,
    my_je                 =   11,
    my_jne                =   12,
    my_jmp                =   13,
    my_rgstprush_ax       =   14,
    my_rgstprush_bx       =   15,
    my_rgstprush_cx       =   16,
    my_rgstprush_dx       =   17,
    my_pop_ax             =   18,
    my_pop_bx             =   19,
    my_pop_cx             =   20,
    my_pop_dx             =   21,
    my_dumb               =   22,
    my_hlt                =   100,
    my_poison             =   30924,
};

size_t translation (int* arr, char* buffer, size_t quentity_cells){
    size_t i = 0;
    size_t j = 0;
    fprintf (stderr, "\n Translation started with quentity_cells = %lu\n", quentity_cells);
    while ( i != quentity_cells){
        if (strncmp (buffer, push, strlen(push)) == 0){
            arr[i] = my_push;
            buffer += strlen(push) + 1; 
            i++;
        }

        if (strncmp (buffer, adition, strlen(adition)) == 0){
            arr[i] = my_adition;
            buffer += strlen(adition) + 1;
            i++;
        } 

        if (strncmp (buffer, subtraction, strlen(subtraction)) == 0){
            arr[i] = my_subtraction;
            buffer += strlen(subtraction) + 1;
            i++;
        } 

        if (strncmp (buffer, multiplication, strlen(multiplication)) == 0){
            arr[i] = my_multiplication;
            buffer += strlen(multiplication) + 1;
            i++;
        } 

        if (strncmp (buffer, division, strlen(division)) == 0){
            arr[i] = my_division;
            buffer += strlen(division) + 1;
            i++;
        } 

        if (strncmp (buffer, out, strlen(out)) == 0){
            arr[i] = my_out;
            buffer += strlen(out) + 1;
            i++;
        } 

        if (strncmp (buffer, hlt, strlen(hlt)) == 0){
            arr[i] = my_hlt;
            buffer += strlen(hlt) + 1;
            i++;
        }

        if (strncmp (buffer, ja, strlen(ja)) == 0){
            arr[i] = my_ja;
            buffer += strlen(ja) + 1;
            i++;
        }
        
        if (strncmp (buffer, jae, strlen(jae)) == 0){
            arr[i] = my_jae;
            buffer += strlen(jae) + 1;
            i++;
        }

        if (strncmp (buffer, jb, strlen(jb)) == 0){
            arr[i] = my_jb;
            buffer += strlen(jb) + 1;
            i++;
        }

        if (strncmp (buffer, jbe, strlen(jbe)) == 0){
            arr[i] = my_jbe;
            buffer += strlen(jbe) + 1;
            i++;
        }

        if (strncmp (buffer, je, strlen(je)) == 0){
            arr[i] = my_je;
            buffer += strlen(je) + 1;
            i++;
        }

        if (strncmp (buffer, jne, strlen(jne)) == 0){
            arr[i] = my_jne;
            buffer += strlen(jne) + 1;
            i++;
        }

        if (strncmp (buffer, jmp, strlen(jmp)) == 0){
            arr[i] = my_jmp;
            buffer += strlen(jmp) + 1;
            i++;
        }

        if (strncmp (buffer, rgstprush_ax, strlen(rgstprush_ax)) == 0){ 
            arr[i] = my_rgstprush_ax;
            buffer += strlen(rgstprush_ax) + 1;
            i++;
        }

         if (strncmp (buffer, rgstprush_bx, strlen(rgstprush_bx)) == 0){
            arr[i] = my_rgstprush_bx;
            buffer += strlen(rgstprush_bx) + 1;
            i++;
        }

         if (strncmp (buffer, rgstprush_cx, strlen(rgstprush_cx)) == 0){
            arr[i] = my_rgstprush_cx;
            buffer += strlen(rgstprush_cx) + 1;
            i++;
        }

        if (strncmp (buffer, rgstprush_dx, 9) == 0){ //что за  алееееееее
            arr[i] = my_rgstprush_dx;
            buffer += 10;
            i++;
        }

        if (strncmp (buffer, pop_ax, strlen(pop_ax)) == 0){
            arr[i] = my_pop_ax;
            buffer += strlen(pop_ax) + 1;
            i++;
        }

        if (strncmp (buffer, pop_bx, strlen(pop_bx)) == 0){
            arr[i] = my_pop_bx;
            buffer += strlen(pop_bx) + 1;
            i++;
        }

        if (strncmp (buffer, pop_cx, strlen(pop_cx)) == 0){
            arr[i] = my_pop_cx;
            buffer += strlen(pop_cx) + 1;
            i++;
        }

        if (strncmp (buffer, pop_dx, strlen(pop_dx)) == 0){
            arr[i] = my_pop_dx;
            buffer += strlen(pop_dx) + 1;
            i++;
        }

        if (strncmp (buffer, dumb, strlen(dumb)) == 0){
            arr[i] = my_dumb;
            buffer += strlen(dumb) + 1;
            i++;
        }

        if (isdigit (*buffer) || *buffer == '-'){
            int flag = 1;
            int result = 0;
            size_t sum = 0;
            
            if (*buffer == '-'){
                flag = -1;
                buffer++; 
            }

            char* endptr = NULL;
            result = strtol (buffer, &endptr, 10);
            buffer = endptr;
            result *= flag;
            arr[i] = result;
            i++;
            buffer++; 
        }
    }
    
    return 0;
}

 size_t sum_symbols (FILE* file_read){
    assert (file_read != NULL);
    fseek(file_read, 0, SEEK_END);
    size_t symbols = (size_t)ftell(file_read);
    fseek(file_read, 0, SEEK_SET);
    DEBUG_PRINT("\n Number of symbols in file is %ld\n", symbols);

    return symbols;
}

size_t QuannityCells (char* buffer, FILE* file_text, size_t num_s){
    assert (buffer != NULL);
    assert (file_text != NULL);
    fread (buffer, sizeof(char), num_s, file_text);
     size_t helper = 0;
     for (size_t i = 0; i < num_s; i++){
        if (isspace (buffer[i])){
            helper++;
        }
    }
    DEBUG_PRINT("\n QuannityCells ended with helper = %ld\n", helper);
    return helper;
}
