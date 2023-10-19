#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - function to swap elements
 * @stack: pointer to a stack data structure
 * @lin_num: current line number
 */
void swap(stack_t **stack, unsigned int lin_num)
{
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lin_num);
		exit(EXIT_FAILURE);

	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
