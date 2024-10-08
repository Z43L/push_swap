#include "pushswap.h"

static int getmin(pushswap **stack, int val)
{
    pushswap *head;
    int min;

    head = *stack;
    min = head->next;
    while(head->next)
    {
        min = head->index;
        if(min > head->index && head->index != val)
            min = head->index;
        
    }
    return min;
}

