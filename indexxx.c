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
    
    int max_bits = 0;
    int max_num = size - 1;

    // Calcular el número máximo de bits necesarios para representar los índices
    while ((max_num >> max_bits) != 0)
        max_bits++;

    // Ordenar por bits (Radix Sort)
    for (int i = 0; i < max_bits; i++) {
        int j = 0;
        while (j < size) {
            // int num = ps->stacka[0];
            int index = indices[0]; // Usar el índice correspondiente

            // Mover a stackb si el bit i-ésimo es 0
            if ((index >> i) & 1) {
                *ps = ra(*ps);
                ft_printf("ra\n");
            } else {
                *ps = pb(*ps);
                ft_printf("pb\n");
            }
            j++;
        }

        // Volver a stacka todo lo de stackb
        while (ps->size_b > 0) {
            *ps = pa(*ps);
            ft_printf("pa\n");
        }
    }

    free(indices);
}

