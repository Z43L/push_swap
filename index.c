#include "pushswap.h"
// assign_indices.c
void	assign_indices(pushswap *ps)
{
    int		size;
    int		*array;
    t_node	*current;
    int		i;
    int		index;
    
    size = ps->size_a;
    array = malloc(size * sizeof(int));
    if (array == NULL)
        exit(EXIT_FAILURE);
    current = ps->stacka;
    i = 0;
    while (i < size)
        {
            array[i] = current->value;
            current = current->next;
            i++;
        }
    insertion_sort(array, size);
    current = ps->stacka;
    while (current != NULL)
        {
            index = 0;
            while (index < size && array[index] != current->value)
                index++;
            current->index = index;
            current = current->next;
        }
    free(array);
}
// get_stack_size.c
int	get_stack_size(t_node *stack)
{
    int	size;
    
    size = 0;
    while (stack != NULL)
        {
            size++;
            stack = stack->next;
        }
    return (size);
}
