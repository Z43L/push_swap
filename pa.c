#include "pushswap.h"

pushswap pa(pushswap ps) {
    if (ps.stackb[0] != -1) { // Asegúrate de usar un valor que represente un espacio vacío
        int first = ps.stackb[0];
        int i = 0;
        
        // Mover todos los elementos en stackb hacia arriba
        while (i < ps.size - 1 && ps.stackb[i + 1] != -1) {
            ps.stackb[i] = ps.stackb[i + 1];
            i++;
        }
        ps.stackb[i] = -1; // Indicar que el último lugar está ahora vacío

        // Mover todos los elementos en stacka hacia abajo
        i = ps.size - 1;
        while (i > 0) {
            ps.stacka[i] = ps.stacka[i - 1];
            i--;
        }
        ps.stacka[0] = first; // Colocar el primer elemento de stackb en la parte superior de stacka
    }
    return ps;
}

