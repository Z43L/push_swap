#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"


void init_stack(pushswap *ps, int size, int values[]) {
    int i = 0;
    ps->stacka = (int *)malloc(size * sizeof(int));
    ps->stackb = (int *)ft_calloc(size, sizeof(int));
    while (i < size) {
        ps->stacka[i] = values[i];
        i++;
    }
}


void print_stack(int *stack, int size, char name) {
    int i = 0;
    ft_printf("Stack %c: ", name);
    while (i < size && stack[i] != '\0') {
        ft_printf("%d ", stack[i]);
        i++;
    }
    ft_printf("\n");
}
int main(int ac, char **av) {
    pushswap ps;
    
    if (ac < 2)
        return 1;


    ps.size = ac - 1;


    int *values = (int *)malloc(ps.size * sizeof(int));
    if (!values) {
        return 1; 
    }


    int i = 0;
    while (i < ps.size) {
        values[i] = ft_atoi(av[i + 1]); 
        i++;
    }


    init_stack(&ps, ps.size, values);

    // printf("Antes de ordenar:\n");
    // print_stack(ps.stacka, ps.size, 'A');
    // print_stack(ps.stackb, ps.size, 'B');

    radix_sort(&ps, ps.size);

    // printf("Después de ordenar:\n");
    // print_stack(ps.stacka, ps.size, 'A');
    // print_stack(ps.stackb, ps.size, 'B');

    
    free(ps.stacka);
    free(ps.stackb);
    free(values);

    return 0;
}