#include "pushswap.h"

/* int lenstacka(pushswap pushswap)
{
    int i; 
    i = 0;
    while(pushswap.stacka[i] != '\0')
        i++;
    return i;
} */
pushswap rra(pushswap pushswap)
{
    int i;
    i = 0;
    int len;
    len =lenstacka(pushswap);
    int firstnum  = pushswap.stacka[len];
    pushswap.stacka[0] = firstnum;
    while(pushswap.stacka[len] != '\0')
    {
        pushswap.stacka[i] =pushswap.stacka[i + 1];
        len--;
        i++;
    }
    return pushswap;
}