#include "pushswap.h"

void rra(pushswap *ps) {
    if (ps->stacka == NULL || ps->stacka->next == NULL) {
        // Si el stack a está vacío o tiene un solo elemento, no hay nada que hacer
        return;
    }
    
    t_node *current = ps->stacka;
    t_node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = ps->stacka;
    ps->stacka = current;
    
    // Imprimir la operación realizada
    //ft_printf("rra\n");
}