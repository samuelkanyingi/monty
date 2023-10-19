#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * add - function to add elements
 * @stack: pointer to a stack data structure
 * @lin_num: current line number
 */
void add(stack_t **stack, unsigned int lin_num)
{
if (!stack || !*stack || !(*stack)->next)
{
fprintf(stderr, "L%u: can't add, stack too short\n", lin_num);
exit(EXIT_FAILURE);
}
(*stack)->next->n += (*stack)->n;
pop(stack, lin_num);
}
