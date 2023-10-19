#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "monty.h"
/**
 * main - entry of program
 * @argc: number of command line arguments
 * @argv: array of strings
 * Return: alaways 0
 */
int main(int argc, char *argv[])
{
	const char *montyFile;
	char line[256];
	unsigned int lin_num = 0;
	FILE *file;
	stack_t *stack = NULL;
	char *opcode = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	montyFile = argv[1];
	file = fopen(montyFile, "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", montyFile);
exit(EXIT_FAILURE);
}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		lin_num++;
		opcode = strtok(line, " \t\n");
		if (opcode != NULL && strcmp(opcode, "push") == 0)
		{
			push(&stack, lin_num);
		}
		else if (opcode != NULL && strcmp(opcode, "pall") == 0)
		{
			pall(&stack, lin_num);
		}


		/*processOpcode(&stack, opcode, lin_num);*/
	}
	fclose(file);
	return (0);
}
/**
 * processOpcode - process opcodes
 * @stack: pointer to a stack
 * @opcode: opcode to be processed
 * @lin_num: current line number
 */
/*
void processOpcode(stack_t **stack, const char *opcode, unsigned int lin_num)
{
	if (opcode != NULL && strcmp(opcode, "push") == 0)
	{
		push(&stack, lin_num);
	}
	else if (opcode != NULL && strcmp(opcode, "pall") == 0)
	{
		pall(&stack, lin_num);
	}
	else if (opcode != NULL && strcmp(opcode, "pint") == 0)
	{
		pint(&stack, lin_num);
	}
	else if (opcode != NULL && strcmp(opcode, "pop") == 0)
	{
		pop(&stack, lin_num);
	}
	else if (opcode != NULL && strcmp(opcode, "swap") == 0)
	{
		swap(&stack, lin_num);
	}
	else if (opcode != NULL && strcmp(opcode, "add") == 0)
	{
		add(&stack, lin_num);
	}
}
*/
