#include "pushswap.h"

void push(t_node **stack, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    if (new_node == NULL) {
        // Manejo de error de asignación de memoria
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}

int pop(t_node **stack) {
    if (*stack == NULL) {
        // Manejo de error: stack vacío
        exit(EXIT_FAILURE);
    }
    t_node *temp = *stack;
    int value = temp->value;
    *stack = (*stack)->next;
    free(temp);
    return value;
}

void swap(t_node **stack) {
    if (*stack == NULL || (*stack)->next == NULL) return;
    t_node *first = *stack;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void rotate(t_node **stack) {
    if (*stack == NULL || (*stack)->next == NULL) return;
    t_node *first = *stack;
    t_node *current = *stack;
    while (current->next != NULL) current = current->next;
    *stack = first->next;
    current->next = first;
    first->next = NULL;
}

void reverse_rotate(t_node **stack) {
    if (*stack == NULL || (*stack)->next == NULL) return;
    t_node *prev = NULL;
    t_node *current = *stack;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    if (prev != NULL) prev->next = NULL;
    current->next = *stack;
    *stack = current;
}

int find_median(t_node *stack, int size) {
    if (stack == NULL || size <= 0) {
        // Manejo de error
        exit(EXIT_FAILURE);
    }

    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        // Manejo de error de asignación de memoria
        exit(EXIT_FAILURE);
    }

    t_node *current = stack;
    for (int i = 0; i < size; i++) {
        if (current == NULL) {
            // Manejo de error: tamaño incorrecto
            free(array);
            exit(EXIT_FAILURE);
        }
        array[i] = current->value;
        current = current->next;
    }

    // Ordenar el array
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }

    int median = array[size / 2];
    free(array);
    return median;
}

void sort_small_stack_a(pushswap *ps, int size) {
    if (size == 2) {
        if (ps->stacka->value > ps->stacka->next->value) {
            swap(&ps->stacka);
            ft_printf("sa\n");
        }
    } else if (size == 3) {
        int a = ps->stacka->value;
        int b = ps->stacka->next->value;
        int c = ps->stacka->next->next->value;

        if (a > b && b < c && a < c) {
            swap(&ps->stacka);
            ft_printf("sa\n");
        } else if (a > b && b > c) {
            swap(&ps->stacka);
            ft_printf("sa\n");
            reverse_rotate(&ps->stacka);
            ft_printf("rra\n");
        } else if (a > b && b < c && a > c) {
            rotate(&ps->stacka);
            ft_printf("ra\n");
        } else if (a < b && b > c && a < c) {
            swap(&ps->stacka);
            ft_printf("sa\n");
            rotate(&ps->stacka);
            ft_printf("ra\n");
        } else if (a < b && b > c && a > c) {
            reverse_rotate(&ps->stacka);
            ft_printf("rra\n");
        }
    }
}

void sort_small_stack_b(pushswap *ps, int size) {
    if (size == 1) {
        push(&ps->stacka, pop(&ps->stackb));
        ps->size_a++;
        ps->size_b--;
        ft_printf("pa\n");
    } else if (size == 2) {
        if (ps->stackb->value < ps->stackb->next->value) {
            swap(&ps->stackb);
            ft_printf("sb\n");
        }
        while (size-- > 0) {
            push(&ps->stacka, pop(&ps->stackb));
            ps->size_a++;
            ps->size_b--;
            ft_printf("pa\n");
        }
    } else if (size == 3) {
        int a = ps->stackb->value;
        int b = ps->stackb->next->value;
        int c = ps->stackb->next->next->value;

        if (a < b && b > c && a > c) {
            swap(&ps->stackb);
            ft_printf("sb\n");
        } else if (a < b && b < c) {
            swap(&ps->stackb);
            ft_printf("sb\n");
            rotate(&ps->stackb);
            ft_printf("rb\n");
        } else if (a > b && b < c && a < c) {
            reverse_rotate(&ps->stackb);
            ft_printf("rrb\n");
        } else if (a > b && b < c && a > c) {
            rotate(&ps->stackb);
            ft_printf("rb\n");
        } else if (a > b && b > c) {
            swap(&ps->stackb);
            ft_printf("sb\n");
            reverse_rotate(&ps->stackb);
            ft_printf("rrb\n");
        }
        // Después de ordenar, mover a 'a'
        while (size-- > 0) {
            push(&ps->stacka, pop(&ps->stackb));
            ps->size_a++;
            ps->size_b--;
            ft_printf("pa\n");
        }
    }
}

void quicksort_a(pushswap *ps, int size) {
    if (size <= 3) {
        sort_small_stack_a(ps, size);
        return;
    }
    int pivot = find_median(ps->stacka, size);
    int pushed = 0;
    int len = size;

    for (int i = 0; i < len; i++) {
        if (ps->stacka->value < pivot) {
            push(&ps->stackb, pop(&ps->stacka));
            ps->size_a--;
            ps->size_b++;
            pushed++;
            ft_printf("pb\n");
        } else {
            rotate(&ps->stacka);
            ft_printf("ra\n");
        }
    }

    quicksort_a(ps, size - pushed);
    quicksort_b(ps, pushed);
}

void quicksort_b(pushswap *ps, int size) {
    if (size <= 3) {
        sort_small_stack_b(ps, size);
        return;
    }
    int pivot = find_median(ps->stackb, size);
    int pushed = 0;
    int len = size;

    for (int i = 0; i < len; i++) {
        if (ps->stackb->value >= pivot) {
            push(&ps->stacka, pop(&ps->stackb));
            ps->size_a++;
            ps->size_b--;
            pushed++;
            ft_printf("pa\n");
        } else {
            rotate(&ps->stackb);
            ft_printf("rb\n");
        }
    }

    quicksort_a(ps, pushed);
    quicksort_b(ps, size - pushed);
}

void push_swap(pushswap *ps) {
    int size = ps->size_a;
    quicksort_a(ps, size);
}
