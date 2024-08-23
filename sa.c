#include "pushswap.h"

pushswap sa(pushswap pushswap)
{
    int num1;
    int num2;
    num1 = pushswap.stacka[0];
    num2 = pushswap.stacka[1];
    pushswap.stacka[0] = num2;
    pushswap.stacka[1] = num1;
    return pushswap;
}