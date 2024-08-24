#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"


void init_stack(pushswap *ps, int size, int *values) {
    ps->stacka = (int *)malloc(size * sizeof(int));
    ps->stackb = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        ps->stacka[i] = values[i];
    }
    
    ps->size_a = size;  // Inicializa size_a con el tamaño de la pila inicial
    ps->size_b = 0;     // Inicializa size_b como 0, ya que stackb empieza vacía
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
    if (ac < 2) {
        return 1;
    }

    pushswap ps;
    ps.size = ac - 1;
    ps.size_a = ps.size;
    ps.size_b = 0;
    ps.stacka = (int *)malloc(ps.size * sizeof(int));
    ps.stackb = (int *)malloc(ps.size * sizeof(int));
    if (!ps.stacka || !ps.stackb) {
        return 1;
    }

    // Inicializar stacka con los argumentos
    for (int i = 1; i < ac; i++) {
        ps.stacka[i - 1] = ft_atoi(av[i]);
    }

    // ft_printf("Antes de ordenar:\n");
    // print_stack(ps.stacka, ps.size_a, 'A');
    // print_stack(ps.stackb, ps.size_b, 'B');

    index_based_sort(&ps, ps.size);

    // ft_printf("Después de ordenar:\n");
    // print_stack(ps.stacka, ps.size_a, 'A');
    // print_stack(ps.stackb, ps.size_b, 'B');

    free(ps.stacka);
    free(ps.stackb);

    return 0;
}

