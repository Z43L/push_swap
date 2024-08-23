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
    if (ps.stacka[0] != '\0') {
        int first = ps.stacka[0];
        int i = 0;
        while (ps.stacka[i + 1] != '\0') {
            ps.stacka[i] = ps.stacka[i + 1];
            i++;
        }
        ps.stacka[i] = first;
    }
    return ps;
}
