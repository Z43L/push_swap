# ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "LIBFT/libft.h"
#include "FT_PRINTF/src/ft_printf.h"

typedef struct s_node {
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_pushswap {
    t_node *stacka;
    t_node *stackb;
    int size_a;
    int size_b;
} pushswap;
void pa(pushswap *ps);
void pb(pushswap *ps);
void ra(pushswap *ps);
void rb(pushswap *ps);
void rr(pushswap *ps);
void rra(pushswap *ps);
void rrb(pushswap *ps);
void rrr(pushswap *ps) ;
void sa(pushswap *ps);
void sb(pushswap *ps);
void ss(pushswap *ps);
int get_max_bits(int *stacka, int size);
void radix_sort(pushswap *ps);
int lenstackb(pushswap pushswap);
int lenstacka(pushswap pushswap);
void index_based_sort(pushswap *ps, int size);
void assign_indices(int *stacka, int *indices, int size) ;
void push_swap(pushswap *ps);
void print_stack(t_node *stack, char name);
void push(t_node **stack, int value);
void quicksort_b(pushswap *ps, int size);
void quicksort_a(pushswap *ps, int size);
void sort_small_stack_b(pushswap *ps, int size);
void sort_small_stack_a(pushswap *ps, int size);
#endif