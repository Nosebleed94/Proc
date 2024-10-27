#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

const int quentity_regist = 4;
const int quentity_label  = 5;

typedef int Stack_Element;

struct stack_t
{
    Stack_Element* storage;
    size_t curreny_position;
};

struct spu_t
{
    struct stack_t stk;
    int regist[quentity_regist] = {0}; 
    int* command_array;
    size_t ip;
};

void Letsgo          (int*  command_array, size_t size);
void CtorSPU         (spu_t* spu);
void StackAdd        (spu_t* spu);
void StackSub        (spu_t* spu);
void StackMul        (spu_t* spu);
void StackDiv        (spu_t* spu);
void StackOut        (spu_t* spu);
void StackJa         (spu_t* spu, size_t position_label);
void StackJae        (spu_t* spu, size_t position_label);
void StackJb         (spu_t* spu, size_t position_label);
void StackJbe        (spu_t* spu, size_t position_label);
void StackJe         (spu_t* spu, size_t position_label);
void StackJne        (spu_t* spu, size_t position_label);
void StackJmp        (spu_t* spu, size_t position_label);
void StackPushR      (spu_t* spu, size_t position);
void RegistrPop      (spu_t* spu, size_t position);
int StackHlt         ();
void CleanMemory     (spu_t* spu);
size_t sum_symbols   (FILE* file_read);
size_t QuannityCells (char* text_commad_in_array, FILE* file_text, size_t num_s);
void CheckForNumber  (char* text_commad_in_array);
void Dump            (spu_t* spu, int*  command_array);

#endif //PROCESSOR_H