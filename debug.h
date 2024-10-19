#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_PRINT
#ifdef DEBUG_PRINT
    #define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)
#else
    #define DEBUG_PRINT(...) 
#endif

#endif //ASSEMBLER_H