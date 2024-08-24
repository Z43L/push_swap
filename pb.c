#include "pushswap.h"
pushswap pb(pushswap ps) {
    if (ps.size_a > 0) {
        int first = ps.stacka[0];
        for (int i = 0; i < ps.size_a - 1; i++) {
            ps.stacka[i] = ps.stacka[i + 1];
        }
        ps.size_a--;

        for (int i = ps.size_b; i > 0; i--) {
            ps.stackb[i] = ps.stackb[i - 1];
        }
        ps.stackb[0] = first;
        ps.size_b++;
    }
    return ps;
}
