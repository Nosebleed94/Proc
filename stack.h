#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <math.h>

#include "processor.h"

void StackCtor   (spu_t* spu, size_t size);
void StackPush   (spu_t* spu, int elem);
int StackPop     (spu_t* spu);
void DedCtor     (spu_t* spu);

#endif //STACK_H