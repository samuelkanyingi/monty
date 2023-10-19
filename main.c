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
		if (opcode != NULL)
		{
			(strcmp(opcode, "push") == 0) ? push(&stack, lin_num) :
			(strcmp(opcode, "pall") == 0) ? pall(&stack, lin_num) :
			(strcmp(opcode, "pint") == 0) ? pint(&stack, lin_num) :
			(strcmp(opcode, "pop") == 0) ? pop(&stack, lin_num) :
			(strcmp(opcode, "swap") == 0) ? swap(&stack, lin_num) :
			(strcmp(opcode, "add") == 0) ? add(&stack, lin_num) :
			(strcmp(opcode, "nop") == 0) ? nop(&stack, lin_num) :
			(void)0;
		}
	}
	fclose(file);
	return (0);
}
