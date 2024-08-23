#include "pushswap.h"

int lenstackb(pushswap pushswap)
{
    int i; 
    i = 0;
    while(pushswap.stackb[i] != '\0')
        i++;
    return i;
}
pushswap rb(pushswap pushswap)
{
    int i;
    i = 0;
    int len;
    len =lenstackb(pushswap);
    int firstnum  = pushswap.stackb[len];
    pushswap.stackb[0] = firstnum;
    while(pushswap.stackb[i] != '\0')
    {
        pushswap.stackb[len] =pushswap.stackb[len - 1];
        len--;
        i++;
    }
    return pushswap;
}