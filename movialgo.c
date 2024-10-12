#include "pushswap.h"
#include <stdlib.h>

// push_node.c
void	push_node(t_node **stack, t_node *new_node)
{
    new_node->next = *stack;
    *stack = new_node;
}

// pop_node.c
t_node	*pop_node(t_node **stack)
{
    t_node	*temp;
    
    if (*stack == NULL)
        return (NULL);
    temp = *stack;
    *stack = temp->next;
    temp->next = NULL;
    return (temp);
}

// swap.c
void	swap(t_node **stack)
{
    t_node	*first;
    t_node	*second;
    
    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

// rotate.c
void	rotate(t_node **stack)
{
    t_node	*first;
    t_node	*current;
    
    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    first = *stack;
    current = *stack;
    while (current->next != NULL)
        current = current->next;
    *stack = first->next;
    first->next = NULL;
    current->next = first;
}

// reverse_rotate.c
void	reverse_rotate(t_node **stack)
{
    t_node	*prev;
    t_node	*current;
    
    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    prev = NULL;
    current = *stack;
    while (current->next != NULL)
        {
            prev = current;
            current = current->next;
        }
    if (prev != NULL)
        prev->next = NULL;
    current->next = *stack;
    *stack = current;
}