#include "monty.h"
#include <string.h>

/**
 * main - entry point
 * @argc: number of args
 * @argv: array of args
 */

void main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t lineSize = 0;
	unsigned int line_number = 0;
	const char delim[] = " \t\n";
	char *token = NULL;
	stack_t *stack = NULL;
	stack_t *tail = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &lineSize, fp) != -1)
	{
		line_number++;

		token = strtok(line, delim);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			add_stack(&stack, &tail, line_number, token);
		} else
			execute(&stack, line_number, token);
	}
	free(line);
	fclose(fp);
}
