#include "pushswap.h"

pushswap pa(pushswap ps) {
    if (ps.size_b > 0) {
        int first = ps.stackb[0];
        for (int i = 0; i < ps.size_b - 1; i++) {
            ps.stackb[i] = ps.stackb[i + 1];
        }
        ps.size_b--;

        for (int i = ps.size_a; i > 0; i--) {
            ps.stacka[i] = ps.stacka[i - 1];
        }
        ps.stacka[0] = first;
        ps.size_a++;
    }
    return ps;
}
