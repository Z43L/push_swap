#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"

void init_stack(pushswap *ps, int size, int *values) {
    ps->stacka = NULL;
    ps->stackb = NULL;
    ps->size_a = size;
    ps->size_b = 0;

    for (int i = 0; i < size; i++) {
        push(&ps->stacka, values[i]);
    }
}

void print_stack(t_node *stack, char name) {
    t_node *current = stack;
    printf("Stack %c: ", name);
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(int ac, char **av) {
    if (ac < 2) {
        return 1;
    }

    pushswap ps;
    int size = ac - 1;
    int *values = malloc(size * sizeof(int));
    if (!values) {
        return 1;
    }

    // Convertir los argumentos a enteros y almacenarlos en el array values
    for (int i = 1; i < ac; i++) {
        values[i - 1] = atoi(av[i]);
    }

    // Inicializar stacka con los valores dados
    init_stack(&ps, size, values);
    free(values);

    printf("Antes de ordenar:\n");
    print_stack(ps.stacka, 'A');
    print_stack(ps.stackb, 'B');

    // Ejecutamos el algoritmo push_swap
    push_swap(&ps);

    printf("\nDespués de ordenar:\n");
    print_stack(ps.stacka, 'A');
    print_stack(ps.stackb, 'B');

    return 0;
}