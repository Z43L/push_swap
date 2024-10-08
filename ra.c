#include "pushswap.h"

void ra(pushswap *ps) {
    if (ps->stacka == NULL || ps->stacka->next == NULL) {
        // Si el stack a está vacío o tiene un solo elemento, no hay nada que hacer
        return;
    }
    
    t_node *first = ps->stacka;
    t_node *current = ps->stacka;
    ps->stacka = first->next;
    
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = first;
    first->next = NULL;
    
    // Imprimir la operación realizada
    //ft_printf("ra\n");
}

