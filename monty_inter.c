#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - function to push element to stack
 * @stack: pointer to a stack data structure
 * @lin_num: current line number on file
 */
void push(stack_t **stack, unsigned int lin_num)
{
	char *args;
	int value;
	stack_t *new_node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push int\n", lin_num);
		exit(EXIT_FAILURE);
	}

	args = strtok(NULL, " \n");
	if (args == NULL)
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
/**
 * pall - function to print elements of a stack
 * @stack: pointer to a stack data structure
 * @lin_num: current line number on file
 */
void pall(stack_t **stack, unsigned int lin_num)
{
	stack_t *current;
	(void)lin_num;

	if (*stack == NULL)
	{
		return;
	}
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - function to print valu eat top of stack
 * @stack: pointer to a stack data structure
 * @lin_num: current line number on file
 */
void pint(stack_t **stack, unsigned int lin_num)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lin_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
