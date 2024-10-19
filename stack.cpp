#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "stack.h"
#include "processor.h"

enum stack_operation { 
    my_poison = 30924,
};

void StackCtor (spu_t* spu, size_t size){
    assert (spu != NULL);
    spu->stk.storage = (Stack_Element*)calloc(size * sizeof(Stack_Element), size);
    spu->stk.curreny_position = 0;
}

void StackPush (spu_t* spu, int elem){
    assert (spu != NULL);
    spu->stk.storage[spu->stk.curreny_position] = elem;
    spu->stk.curreny_position++; 
}

int StackPop (spu_t* spu){
    assert (spu != NULL);
    if (spu->stk.curreny_position == 0){
        int x = spu->stk.storage[spu->stk.curreny_position];
        spu->stk.storage[spu->stk.curreny_position] = my_poison;
        return x;
    }
    else{
        int x = spu->stk.storage[spu->stk.curreny_position];
        spu->stk.storage[spu->stk.curreny_position] = my_poison;
        spu->stk.curreny_position--;
        return x;
    }
}
