#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * main - entry point
 * @argc: number of args
 * @argv: array of args
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line;
	size_t size = 0;
	unsigned int line_number = 0;
	const char delim[] = " \t\n";
	char *token = NULL;
	stack_t *stack = NULL;
	stack_t *tail = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		fflush(stderr);
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fflush(stderr);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &size, fp) > 0)
	{
		line_number++;

		token = strtok(line, delim);
		if (token != NULL && strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			add_stack(&stack, &tail, line_number, token);
		} else if (token != NULL)
		{
			execute(&stack, line_number, token);
		}
		line = NULL;
	}
	fclose(fp);
	free_stack(&stack, line_number);

	return (0);
}
