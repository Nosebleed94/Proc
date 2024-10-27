#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "general_enum.h"
#include "processor.h"
#include "debug.h"
#include "stack.h"

void Letsgo (int* command_array, size_t size)
{// FIXME assert
    spu_t spu ={};

    CtorSPU (&spu);

    size_t position_ax = 0;
    size_t position_bx = 1;// исправлю
    size_t position_cx = 2;
    size_t position_dx = 3;
   
    StackCtor (&spu, size);

    while (command_array[spu.ip] != my_hlt)
    {
        switch ( command_array[spu.ip]){
        case 1:   StackPush  (&spu,  command_array[spu.ip + 1]);
                  spu.ip += 2;
                  break;
        case 2:   StackAdd       (&spu);
                  spu.ip+= 1;
                  break;
        case 3:   StackSub       (&spu);
                  spu.ip += 1;
                  break;
        case 4:   StackMul       (&spu);
                  spu.ip += 1;
                  break;
        case 5:   StackDiv       (&spu);
                  spu.ip += 1;
                  break;
        case 6:   StackOut       (&spu);
                  spu.ip+= 1;
                  break;
        case 7:   StackJa        (&spu,  command_array[spu.ip + 1]);
                  break;
        case 8:   StackJae       (&spu,  command_array[spu.ip + 1]);
                  break;
        case 9:   StackJb        (&spu,  command_array[spu.ip + 1]);
                  break;
        case 10:  StackJbe       (&spu,  command_array[spu.ip + 1]);
                  break;
        case 11:  StackJe        (&spu,  command_array[spu.ip + 1]);
                  break;
        case 12:  StackJne       (&spu,  command_array[spu.ip + 1]);
                  break;
        case 13:  StackJmp       (&spu,  command_array[spu.ip + 1]);
                  break;
        case 14:  StackPushR     (&spu, position_ax);
                  spu.ip += 1;
                  break;
        case 15:  StackPushR     (&spu, position_ax);
                  spu.ip += 1;
                  break;
        case 16:  StackPushR     (&spu, position_ax);
                  spu.ip += 1;
                  break;
        case 17:  StackPushR     (&spu, position_ax);
                  spu.ip += 1;
                  break;
        case 18:  RegistrPop     (&spu, position_ax); 
                  spu.ip += 1;         
                  break;
        case 19:  RegistrPop     (&spu, position_bx); 
                  spu.ip += 1;         
                  break;
        case 20:  RegistrPop     (&spu, position_cx); 
                  spu.ip += 1;         
                  break;
        case 21:  RegistrPop     (&spu, position_dx); 
                  spu.ip += 1;         
                  break;
        case 22:  Dump           (&spu,  command_array);
                  spu.ip += 1;
        case 100: StackHlt       ();
                  break;
        defult:   printf         ("ERROR");
                  break;
        }
    } 

    DedCtor (&spu);
}

void StackAdd (spu_t* spu)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int a = StackPop (spu);
    int b = StackPop (spu);
    if (spu->stk.storage[spu->stk.curreny_position] != my_poison && spu->stk.curreny_position == 0){spu->stk.curreny_position++;}
    StackPush (spu, a + b);
} 

void StackSub (spu_t* spu)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (spu->stk.storage[spu->stk.curreny_position] != my_poison && spu->stk.curreny_position == 0){spu->stk.curreny_position++;}
    StackPush (spu, a - b);
} 

void StackMul (spu_t* spu)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int a = StackPop (spu);
    int b = StackPop (spu);
    if (spu->stk.storage[spu->stk.curreny_position] != my_poison && spu->stk.curreny_position == 0){spu->stk.curreny_position++;}
    StackPush (spu, a * b);
} 

void StackDiv (spu_t* spu)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (spu->stk.storage[spu->stk.curreny_position] != my_poison && spu->stk.curreny_position == 0){spu->stk.curreny_position++;}
    StackPush (spu, a / b);
} 

void StackOut (spu_t* spu)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    printf("\n [Meaning id %d]\n", spu->stk.storage[spu->stk.curreny_position]);
    spu->stk.storage[spu->stk.curreny_position] = my_poison;
}

int StackHlt ()
{
    return my_hlt;
}

void CleanMemory (spu_t* spu)
{
    assert (spu != NULL);
    free(spu->stk.storage);
}

void RegistrPop (spu_t* spu, size_t position)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    spu->regist[position] = StackPop (spu);
    DEBUG_PRINT ("Number regist is {%d}\n", spu->regist[position]);
};

void StackPushR (spu_t* spu, size_t position)
{
    assert (spu != NULL);
    spu->stk.storage[spu->stk.curreny_position] = spu->regist[position];
    spu->stk.curreny_position++;
}

void StackJa (spu_t* spu, size_t position_label)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (a > b)
    {
       spu->ip = position_label;;// 
    }

    else
    {
        spu->ip++;
    }
}

void StackJae (spu_t* spu, size_t position_label)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);

    if (a >= b)
    {
       spu->ip = position_label;
    }

    else
    {
        spu->ip++;
    }
}

void StackJb (spu_t* spu, size_t position_label)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);

    if (a < b)
    {
       spu->ip = position_label;
    }

    else
    {
        spu->ip++;
    }
}

void StackJbe (spu_t* spu, size_t position_label)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);

    if (a <= b)
    {
       spu->ip = position_label; 
    }

    else
    {
        spu->ip++;
    }
}

void StackJe (spu_t* spu, size_t position_label)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);

    if (a == b)
    {
       spu->ip = position_label;// 
    }

    else
    {
        spu->ip++;
    }
}

void StackJne (spu_t* spu, size_t position_label)
{
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);

    if (a != b)
    {
       spu->ip = position_label;// 
    }

    else
    {
        spu->ip++;
    }
}

void StackJmp (spu_t* spu, size_t position_label)
{
    assert (spu != NULL);
    spu->ip = 4;//
}


void Dump (spu_t* spu, int*  command_array)
{
    assert (spu != NULL);
    assert ( command_array != NULL);

    fprintf (stderr,"---------------------------------------------------------------------------------------------------------------------------\n");
    for (int q = 0; q < 20; q++)
    {
        fprintf (stderr,"[%x]  ", q); 
    }

    fprintf (stderr, "\n\n");

    for (int q = 0; q < 20; q++)
    {
        fprintf (stderr,"[%x]  ",  command_array[q]); 
    }

    fprintf (stderr, "\n");
    fprintf (stderr,"\nNumber AX is {%d}\n", spu->regist[0]);
    fprintf (stderr,"\nNumber AX is {%d}\n", spu->regist[1]);
    fprintf (stderr,"\nNumber AX is {%d}\n", spu->regist[2]);
    fprintf (stderr,"\nNumber AX is {%d}\n\n", spu->regist[3]);

    fprintf (stderr,"STACK:    \n");

    for (int q = 0; q < 20; q++)
    {
        fprintf (stderr,"[%d]  ", spu->stk.storage[q]); 
    }

    fprintf (stderr,"\n");
    fprintf (stderr,"---------------------------------------------------------------------------------------------------------------------------\n");
}

void CtorSPU (spu_t* spu)
{
    spu->ip = 0;
    spu->regist[quentity_regist] = {0};
}