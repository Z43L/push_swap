#include "pushswap.h"
void assign_indices(int *stacka, int *indices, int size) {
    // Copiar los valores y ordenarlos
    for (int i = 0; i < size; i++) {
        indices[i] = stacka[i];
    }

    // Ordenar los índices (Bubble Sort o cualquier otro método)
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (indices[i] > indices[j]) {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
    }

    // Asignar índices a los elementos
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (stacka[i] == indices[j]) {
                stacka[i] = j;
                break;
            }
        }
    }
}



void index_based_sort(pushswap *ps, int size) {
    int *indices = (int *)malloc(size * sizeof(int));
    if (!indices) {
        return;
    }
    
    // Asignar índices a stacka
    assign_indices(ps->stacka, indices, size);

    int i = 0;
    while (i < size) {
        int num = ps->stacka[0];
        if (num < size / 2) {
            *ps = pb(*ps);
            ft_printf("pb\n");
        } else {
            *ps = ra(*ps);
            ft_printf("ra\n");
        }
        i++;
    }

    while (ps->size_b > 0) {
        *ps = pa(*ps);
        ft_printf("pa\n");
    }

    free(indices);
}

