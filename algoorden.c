#include "pushswap.h"
#include <stdlib.h>


// Funciones básicas de la pila
void push_node(t_node **stack, t_node *new_node) {
    new_node->next = *stack;
    *stack = new_node;
}

t_node *pop_node(t_node **stack) {
    if (*stack == NULL)
        return NULL;
    t_node *temp = *stack;
    *stack = temp->next;
    temp->next = NULL;
    return temp;
}

void swap(t_node **stack) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_node *first = *stack;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void rotate(t_node **stack) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_node *first = *stack;
    t_node *current = *stack;
    while (current->next != NULL)
        current = current->next;
    *stack = first->next;
    first->next = NULL;
    current->next = first;
}

void reverse_rotate(t_node **stack) {
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    t_node *prev = NULL;
    t_node *current = *stack;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev != NULL)
        prev->next = NULL;
    current->next = *stack;
    *stack = current;
}

// Función para asignar índices normalizados
void assign_indices(pushswap *ps) {
    int size = ps->size_a;
    int *array = malloc(size * sizeof(int));
    if (array == NULL)
        exit(EXIT_FAILURE);

    t_node *current = ps->stacka;
    for (int i = 0; i < size; i++) {
        array[i] = current->value;
        current = current->next;
    }

    // Ordenar el array usando Insertion Sort
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        // Mover elementos del array[0..i-1] que son mayores que 'key'
        // una posición adelante para hacer espacio para 'key'
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    // Asignar índices a los valores
    current = ps->stacka;
    while (current != NULL) {
        int index = 0;
        while (index < size && array[index] != current->value)
            index++;
        current->index = index;
        current = current->next;
    }
    free(array);
}


// Función principal de Radix Sort optimizado
void radix_sort(pushswap *ps) {
    assign_indices(ps);
    int max_bits = 0;
    int max_index = ps->size_a - 1;

    // Encontrar el número máximo de bits necesarios
    while ((max_index >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++) {
        int size = ps->size_a;
        for (int j = 0; j < size; j++) {
            if (((ps->stacka->index >> i) & 1) == 0) {
                // Bit es 0, mover a 'b'
                t_node *node = pop_node(&ps->stacka);
                push_node(&ps->stackb, node);
                ps->size_a--;
                ps->size_b++;
                ft_printf("pb\n");
            } else {
                // Bit es 1, rotar 'a'
                rotate(&ps->stacka);
                ft_printf("ra\n");
            }
        }
        // Mover todos los elementos de 'b' de vuelta a 'a'
        while (ps->size_b > 0) {
            t_node *node = pop_node(&ps->stackb);
            push_node(&ps->stacka, node);
            ps->size_a++;
            ps->size_b--;
            ft_printf("pa\n");
        }
    }
}

// Función principal
void push_swap(pushswap *ps) {
    ps->size_a = get_stack_size(ps->stacka);
    ps->size_b = 0;
    radix_sort(ps);
}

// Función para obtener el tamaño de la pila
int get_stack_size(t_node *stack) {
    int size = 0;
    while (stack != NULL) {
        size++;
        stack = stack->next;
    }
    return size;
}
