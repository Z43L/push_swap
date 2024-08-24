#include "pushswap.h"

int lenstackb(pushswap pushswap)
{
    int i; 
    i = 0;
    while(pushswap.stackb[i] != '\0')
        i++;
    return i;
}

pushswap rb(pushswap ps) {
    if (ps.size_b > 1) { // Asegurarse de que stackb tiene al menos dos elementos
        int temp = ps.stackb[0];
        int i;

        // Rotar los elementos en stackb
        for (i = 0; i < ps.size_b - 1; i++) {
            ps.stackb[i] = ps.stackb[i + 1];
        }
        ps.stackb[ps.size_b - 1] = temp;
    }
    return ps;
}