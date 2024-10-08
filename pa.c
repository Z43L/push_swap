#include "pushswap.h"


void pa(pushswap *ps) {
    if (ps->stackb == NULL) {
        // Si el stack b está vacío, no hay nada que hacer
        return;
    }
    
    // Tomar el primer elemento del stack b
    t_node *first = ps->stackb;
    ps->stackb = ps->stackb->next;
    
    // Insertar el elemento al inicio del stack a
    first->next = ps->stacka;
    ps->stacka = first;
    
    // Actualizar los tamaños de los stacks
    ps->size_a++;
    ps->size_b--;
    
    // Imprimir la operación realizada
    //ft_printf("pa\n");
}