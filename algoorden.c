#include   "pushswap.h"

int get_max_bits(int *stacka, int size) 
{
    int max = 0;


    int i = 0;
    while(i < size)
    {
        if (stacka[i] > max)
            max = stacka[i];
        i++;
    }

    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}
void radix_sort(pushswap *ps, int size) 
{
    int max_bits = get_max_bits(ps->stacka, size);
    int i = 0;

    while (i < max_bits)
    {
        int j = 0;

        while (j < size) 
        {
            int num = ps->stacka[0];

            if (((num >> i) & 1) == 1)
            {
                *ps = ra(*ps);
                ft_printf("ra\n");
            } else
            {
                *ps = pb(*ps);
                ft_printf("pb\n");
            }

            j++;
        }

        while (ps->stackb[0] != -1)
        { 
            *ps = pa(*ps);
            ft_printf("pa\n");
        }

        i++;
    }
}
