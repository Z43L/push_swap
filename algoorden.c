#include "pushswap.h"
#include <stdlib.h>



// insertion_sort.c
void	insertion_sort(int *array, int size)
{
    int	i;
    int	key;
    int	j;
    
    i = 1;
    while (i < size)
        {
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > key)
                {
                    array[j + 1] = array[j];
                    j = j - 1;
                }
            array[j + 1] = key;
            i++;
        }
}



// push_bit_to_b.c
void push_bit_to_b(pushswap *ps, int bit) {
    int size;
    int j;

    size = ps->size_a;
    j = 0;
    while (j < size) {
        if (((ps->stacka->index >> bit) & 1) == 0) {
            pb(ps);
            ft_printf("pb\n");
        } else {
            ra(ps);
            ft_printf("ra\n");
        }
        j++;
    }
}


// move_all_b_to_a.c
void move_all_b_to_a(pushswap *ps) {
    while (ps->size_b > 0) {
        pa(ps);
        ft_printf("pa\n");
    }
}


// radix_sort.c
void	radix_sort(pushswap *ps)
{
    int	max_bits;
    int	max_index;
    int	i;
    
    assign_indices(ps);
    max_bits = 0;
    max_index = ps->size_a - 1;
    while ((max_index >> max_bits) != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
        {
            push_bit_to_b(ps, i);
            move_all_b_to_a(ps);
            i++;
        }
}


// push_swap.c
void	push_swap(pushswap *ps)
{
    ps->size_a = get_stack_size(ps->stacka);
    ps->size_b = 0;
    radix_sort(ps);
}
