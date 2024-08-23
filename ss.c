#include "pushswap.h"

pushswap ss(pushswap pushswap)
{
    int num1;
    int num2;
    int num3;
    int num4;

    num1 = pushswap.stacka[0];
    num2 = pushswap.stacka[1];
    pushswap.stacka[0] = num2;
    pushswap.stacka[1] = num1;
    num3 = pushswap.stacka[0];
    num4 = pushswap.stacka[1];
    pushswap.stackb[0] = num4;
    pushswap.stackb[1] = num3;
    return pushswap;
}