#include   "pushswap.h"
int get_max_bits(int *stacka, int size) {
    int max = stacka[0];
    for (int i = 1; i < size; i++) {
        if (stacka[i] > max) {
            max = stacka[i];
        }
    }
    int bits = 0;
    while ((max >> bits) != 0) {
        bits++;
    }
    return bits;
}

void radix_sort(pushswap *ps) {
    int max_bits = get_max_bits(ps->stacka, ps->size_a);
    int i = 0;
    int size = ps->size_a;

    while (i < max_bits) {
        int j = 0;

        while (j < size) {
            int num = ps->stacka[0];
            if (((num >> i) & 1) == 1) {
                *ps = ra(*ps);
                ft_printf("ra\n");
            } else {
                *ps = pb(*ps);
                ft_printf("pb\n");
            }
            j++;
        }

        while (ps->size_b > 0) {
            *ps = pa(*ps);
            ft_printf("pa\n");
        }

        i++;
    }
}
