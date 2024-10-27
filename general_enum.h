#ifndef GENERAL_ENUM_H
#define GENERAL_ENUM_H

enum stack_operation
{
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
    my_next               =   23,
    my_hlt                =   100,
    my_poison             =   30924,
};

#endif //GENERAL_ENUM_H