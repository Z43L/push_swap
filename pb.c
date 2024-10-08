#include "pushswap.h"
void pb(pushswap *ps) {
    if (ps->stacka == NULL) {
        // Si el stack a está vacío, no hay nada que hacer
        return;
    }
    
    // Tomar el primer elemento del stack a
    t_node *first = ps->stacka;
    ps->stacka = ps->stacka->next;
    
    // Insertar el elemento al inicio del stack b
    first->next = ps->stackb;
    ps->stackb = first;
    
    // Actualizar los tamaños de los stacks
    ps->size_a--;
    ps->size_b++;
    
    // Imprimir la operación realizada
    //ft_printf("pb\n");
}