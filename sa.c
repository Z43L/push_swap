#include "pushswap.h"

void sa(pushswap *ps) {
    if (ps->stacka == NULL || ps->stacka->next == NULL) {
        // Si el stack a está vacío o tiene un solo elemento, no hay nada que hacer
        return;
    }
    
    t_node *first = ps->stacka;
    t_node *second = first->next;
    first->next = second->next;
    second->next = first;
    ps->stacka = second;
    
    // Imprimir la operación realizada
    //ft_printf("sa\n");
}