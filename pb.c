#include "pushswap.h"
pushswap pb(pushswap ps) {
    if (ps.stacka[0] != '\0') {
        int first = ps.stacka[0];
        int i = 0;
        
      
        while (ps.stacka[i + 1] != '\0') {
            ps.stacka[i] = ps.stacka[i + 1];
            i++;
        }
        ps.stacka[i] = '\0';


        i = ps.size - 1;
        while (i > 0) {
            ps.stackb[i] = ps.stackb[i - 1];
            i--;
        }
        ps.stackb[0] = first;
    }
    return ps;
}
