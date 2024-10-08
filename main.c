#include "pushswap.h"
#include <stdlib.h>
#include <limits.h>

// Función para validar si una cadena es un número entero
int is_number(const char *str) {
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return 0;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

// Función para convertir cadena a entero largo
long ft_atol(const char *str) {
    int i = 0;
    long sign = 1;
    long result = 0;

    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i++] - '0');
    }
    return result * sign;
}

// Función para verificar duplicados en los argumentos
int has_duplicates(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        for (int j = i + 1; j < argc; j++) {
            if (ft_atol(argv[i]) == ft_atol(argv[j]))
                return 1;
        }
    }
    return 0;
}

// Función para crear un nuevo nodo
t_node *create_node(int value) {
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        exit(EXIT_FAILURE);
    new_node->value = value;
    new_node->index = 0;
    new_node->next = NULL;
    return new_node;
}

// Función para inicializar el stack a partir de los argumentos
int init_stack(pushswap *ps, int argc, char **argv) {
    ps->stacka = NULL;
    ps->stackb = NULL;
    ps->size_a = 0;
    ps->size_b = 0;

    for (int i = argc - 1; i >= 1; i--) {
        if (!is_number(argv[i])) {
            ft_putstr_fd("Error\n", 2);
            return 0;
        }
        long value = ft_atol(argv[i]);
        if (value < INT_MIN || value > INT_MAX) {
            ft_putstr_fd("Error\n", 2);
            return 0;
        }
        t_node *new_node = create_node((int)value);
        if (!new_node)
            return 0;
        new_node->next = ps->stacka;
        ps->stacka = new_node;
        ps->size_a++;
    }
    if (has_duplicates(argc, argv)) {
        ft_putstr_fd("Error\n", 2);
        return 0;
    }
    return 1;
}

// Función para liberar la memoria de los stacks
void free_stack(t_node *stack) {
    t_node *tmp;
    while (stack) {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

// Función principal
int main(int argc, char **argv) {
    if (argc < 2) {
        return 0;
    }

    pushswap ps;

    // Inicializar stacka con los valores dados
    if (!init_stack(&ps, argc, argv))
        return 1;

    // Verificar si el stack ya está ordenado
    t_node *current = ps.stacka;
    while (current && current->next) {
        if (current->value > current->next->value)
            break;
        current = current->next;
    }
    if (!current->next) {
        // El stack ya está ordenado
        free_stack(ps.stacka);
        return 0;
    }

    // Ejecutamos el algoritmo push_swap
    push_swap(&ps);

    // Liberar memoria
    free_stack(ps.stacka);
    free_stack(ps.stackb);

    return 0;
}
