# ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "LIBFT/libft.h"
#include "FT_PRINTF/src/ft_printf.h"


typedef struct pushswap
{
    int *stacka;
    int *stackb;
    int size;
    int size_b;
    int size_a;
}   pushswap;

pushswap pa(pushswap pushswap);
pushswap pb(pushswap pushswap);
pushswap ra(pushswap pushswap);
pushswap rb(pushswap pushswap);
pushswap rr(pushswap pushswap);
pushswap rra(pushswap pushswap);
pushswap rrb(pushswap pushswap);
pushswap rrr(pushswap pushswap);
pushswap sa(pushswap pushswap);
pushswap sb(pushswap pushswap);
pushswap ss(pushswap pushswap);
int get_max_bits(int *stacka, int size);
void radix_sort(pushswap *ps);
int lenstackb(pushswap pushswap);
int lenstacka(pushswap pushswap);
void print_stack(int *stack, int size, char name);
void index_based_sort(pushswap *ps, int size);
void assign_indices(int *stacka, int *indices, int size) ;
#endif