#include "pushswap.h"

pushswap sb(pushswap pushswap)
{
    int num1;
    int num2;
    num1 = pushswap.stackb[0];
    num2 = pushswap.stackb[1];
    pushswap.stackb[0] = num2;
    pushswap.stackb[1] = num1;
    return pushswap;
}