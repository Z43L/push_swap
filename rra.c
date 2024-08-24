#include "pushswap.h"

/* int lenstacka(pushswap pushswap)
{
    int i; 
    i = 0;
    while(pushswap.stacka[i] != '\0')
        i++;
    return i;
} */
pushswap rra(pushswap ps) {
    if (ps.size_a > 1) {
        int last = ps.stacka[ps.size_a - 1];
        for (int i = ps.size_a - 1; i > 0; i--) {
            ps.stacka[i] = ps.stacka[i - 1];
        }
        ps.stacka[0] = last;
    }
    return ps;
}
