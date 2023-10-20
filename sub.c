#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * sub - function to suntract element
 * @stack: pointer to stack data structure
 * @lin_num: current line number
 */
void sub(stack_t **stack, unsigned int lin_num)
{
	stack_t *tem;

(void)lin_num;
	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", lin_num);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;

	tem = *stack;
	*stack = tem->next;
	free(tem);
}
