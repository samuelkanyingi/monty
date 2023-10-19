#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pop - function to remove element from stack
 * @stack: pointer to a stack data structure
 * @lin_num: current line number
 */
void pop(stack_t **stack, unsigned int lin_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lin_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}
