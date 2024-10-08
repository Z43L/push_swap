#include "pushswap.h"

void sb(pushswap *ps) {
    if (ps->stackb == NULL || ps->stackb->next == NULL) {
        // Si el stack b está vacío o tiene un solo elemento, no hay nada que hacer
        return;
    }
    
    t_node *first = ps->stackb;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    ps->stackb = second;
    
    // Imprimir la operación realizada
    //ft_printf("sb\n");
}