#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "processor.h"
#include "debug.h"
#include "stack.h"

enum stack_operation {
    my_push                  =   1,
    my_adition               =   2,
    my_subtraction           =   3,
    my_multiplication        =   4,
    my_division              =   5,
    my_out                   =   6,
    my_ja                    =   7,
    my_jae                   =   8,
    my_jb                    =   9,
    my_jbe                   =   10,
    my_je                    =   11,
    my_jne                   =   12,
    my_jmp                   =   13,
    my_rgstprush             =   14,
    my_pop                   =   15,
    my_dumb                  =   16, 
    my_hlt                   =   100,
    my_poison                =   30924,
};

void Letsgo (int* arr, size_t size){
    spu_t spu ={};
    stack_t stk = {};
    StackCtor (&spu, size);
    spu.ip = 0;
    size_t position_ax = 0;
    size_t position_bx = 1;
    size_t position_cx = 2;
    size_t position_dx = 3;

    while (arr[spu.ip] != my_hlt)
    {
        switch (arr[spu.ip]){
        case 1:   StackPush  (&spu, arr[spu.ip + 1]);
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
        case 7:   StackJa        (&spu);
                  break;
        case 8:   StackJae       (&spu);
                  break;
        case 9:   StackJb        (&spu);
                  break;
        case 10:  StackJbe       (&spu);
                  break;
        case 11:  StackJe        (&spu);
                  break;
        case 12:  StackJne       (&spu);
                  break;
        case 13:  StackJmp       (&spu);
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
        case 22:  Dump           (&spu, arr);
                  spu.ip += 1;
                  break;
        case 100: StackHlt       ();
                  break;
        defult:   printf         ("ERROR");
                  break;
        }
    } 
}

// void StackCtor (spu_t* spu, size_t size){
//     assert (spu != NULL);
//     spu->stk.storage = (Stack_Element*)calloc(size * sizeof(Stack_Element), size);
//     spu->stk.curreny_position = 0;
// }

// void StackPush (spu_t* spu, int elem){
//     assert (spu != NULL);
//     spu->stk.storage[spu->stk.curreny_position] = elem;
//     spu->stk.curreny_position++; 
// }

// int StackPop (spu_t* spu){
//     assert (spu != NULL);
//     if (spu->stk.curreny_position == 0){
//         int x = spu->stk.storage[spu->stk.curreny_position];
//         spu->stk.storage[spu->stk.curreny_position] = my_poison;
//         return x;
//     }
//     else{
//         int x = spu->stk.storage[spu->stk.curreny_position];
//         spu->stk.storage[spu->stk.curreny_position] = my_poison;
//         spu->stk.curreny_position--;
//         return x;
//     }
// }

void StackAdd (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int a = StackPop (spu);
    int b = StackPop (spu);
    if (spu->stk.storage[spu->stk.curreny_position] != my_poison && spu->stk.curreny_position == 0){spu->stk.curreny_position++;}
    StackPush(spu, a + b);
} 

void StackSub (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (spu->stk.storage[spu->stk.curreny_position] != my_poison && spu->stk.curreny_position == 0){spu->stk.curreny_position++;}
    StackPush (spu, a - b);
} 

void StackMul (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int a = StackPop (spu);
    int b = StackPop (spu);
    if (spu->stk.storage[spu->stk.curreny_position] != my_poison && spu->stk.curreny_position == 0){spu->stk.curreny_position++;}
    StackPush (spu, a * b);
} 

void StackDiv (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (spu->stk.storage[spu->stk.curreny_position] != my_poison && spu->stk.curreny_position == 0){spu->stk.curreny_position++;}
    StackPush (spu, a / b);
} 

void StackOut (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    printf("\n [Meaning id %d]\n", spu->stk.storage[spu->stk.curreny_position]);
    spu->stk.storage[spu->stk.curreny_position] = my_poison;
}

int StackHlt (){
    return my_hlt;
}

void CleanMemory (spu_t* spu){
    assert (spu != NULL);
    free(spu->stk.storage);
}

void RegistrPop (spu_t* spu, size_t position){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    spu->regist[position] = StackPop (spu);
    DEBUG_PRINT ("Number regist is {%d}\n", spu->regist[position]);
};

void StackPushR (spu_t* spu, size_t position){
    assert (spu != NULL);
    spu->stk.storage[spu->stk.curreny_position] = spu->regist[position];
    // fprintf (stderr,"!!!!!!!!!! {%d}", spu->stk.storage[spu->stk.curreny_position]);
    spu->stk.curreny_position++;
}

void StackJa (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (a > b){
       spu->ip = 4;// 
    }
    else{
        spu->ip++;
    }
}

void StackJae (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (a >= b){
       spu->ip = 4;// 
    }
    else{
        spu->ip++;
    }
}

void StackJb (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (a < b){
       spu->ip = 3;// 
    }
    else{
        spu->ip++;
    }
}

void StackJbe (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (a <= b){
       spu->ip = 4; // 
    }
    else{
        spu->ip++;
    }
}

void StackJe (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (a == b){
       spu->ip = 4;// 
    }
    else{
        spu->ip++;
    }
}

void StackJne (spu_t* spu){
    assert (spu != NULL);
    spu->stk.curreny_position--;
    int b = StackPop (spu);
    int a = StackPop (spu);
    if (a != b){
       spu->ip = 4;// 
    }
    else{
        spu->ip++;
    }
}

void StackJmp (spu_t* spu){
    assert (spu != NULL);
    spu->ip = 4;//
}

void Dump (spu_t* spu, int* arr){
    assert (spu != NULL);
    assert (arr != NULL);
    fprintf (stderr,"---------------------------------------------------------------------------------------------------------------------------\n");
    for (int q = 0; q < 20; q++){
        fprintf (stderr,"[%x]  ", q); 
    }
     fprintf (stderr, "\n\n");

     for (int q = 0; q < 20; q++){
        fprintf (stderr,"[%x]  ", arr[q]); 
    }
    fprintf (stderr, "\n");
    fprintf(stderr,"\nNumber AX is {%d}\n", spu->regist[0]);
    fprintf(stderr,"\nNumber AX is {%d}\n", spu->regist[1]);
    fprintf(stderr,"\nNumber AX is {%d}\n", spu->regist[2]);
    fprintf(stderr,"\nNumber AX is {%d}\n\n", spu->regist[3]);

    fprintf (stderr,"STACK:    \n");

    for (int q = 0; q < 20; q++){
        fprintf (stderr,"[%d]  ", spu->stk.storage[q]); 
    }

    fprintf (stderr,"\n");
    fprintf (stderr,"---------------------------------------------------------------------------------------------------------------------------\n");
}