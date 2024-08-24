#include "pushswap.h"

int lenstacka(pushswap pushswap)
{
    int i; 
    i = 0;
    while(pushswap.stacka[i] != '\0')
        i++;
    return i;
}
pushswap ra(pushswap ps) {
    if (ps.size_a > 1) {
        int first = ps.stacka[0];
        for (int i = 0; i < ps.size_a - 1; i++) {
            ps.stacka[i] = ps.stacka[i + 1];
        }
        ps.stacka[ps.size_a - 1] = first;
    }
    return ps;
}

