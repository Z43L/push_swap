#include "pushswap.h"

void rrb(pushswap *ps) {
    if (ps->stackb == NULL || ps->stackb->next == NULL) {
        // Si el stack b está vacío o tiene un solo elemento, no hay nada que hacer
        return;
    }
    
    t_node *current = ps->stackb;
    t_node *prev = NULL;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    current->next = ps->stackb;
    ps->stackb = current;
    
    // Imprimir la operación realizada
    //ft_printf("rrb\n");
}