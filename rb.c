#include "pushswap.h"

void rb(pushswap *ps) {
    if (ps->stackb == NULL || ps->stackb->next == NULL) {
        // Si el stack b está vacío o tiene un solo elemento, no hay nada que hacer
        return;
    }
    
    t_node *first = ps->stackb;
    t_node *current = ps->stackb;
    ps->stackb = first->next;
    
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = first;
    first->next = NULL;
    
    // Imprimir la operación realizada
    //ft_printf("rb\n");
}