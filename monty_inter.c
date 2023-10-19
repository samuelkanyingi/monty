#include <stdio.h>
#include <stdlib.h>
#include "monty.h"


void push (stack_t **stack, unsigned int lin_num)
{
	char *args;
	int value;
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push int\n", lin_num);
		exit(EXIT_FAILURE);
	}

	arg = strtok(NULL, " \n");
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push int\n", lin_num);
		exit(EXIT_FAILURE);
	}
	value = atoi(args);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;

	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
	
}
void pall(stack_t **stack, unsigned int lin_num)
{
	stack_t *current;
	(void)lin_num;

        current	= *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
void pint(stack_t **stack, unsigned int lin_num)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lin_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
