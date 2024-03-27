#include <stdio.h>
#include <string.h>
#include "monty.h"
#include <sys/types.h>

/**
 * main - entry point
 * @argc: number of args
 * @argv: array of args
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char line[100];
	unsigned int line_number = 0;
	const char delim[] = " \t\n";
	char *token = NULL;
	stack_t *stack = NULL;
	stack_t *tail = NULL;
	char *while_break = NULL;

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
	while_break = fgets(line, 100, fp);
	while (while_break != NULL)
	{	
		line_number++;

		token = strtok(line, delim);
		if (token != NULL && strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			add_stack(&stack, &tail, line_number, token);
		} else if (token !=NULL)
		{
			execute(&stack, line_number, token);
		}
		memset(line, 0, sizeof(line));
		while_break = fgets(line, 100, fp);
	}
	fclose(fp);

	return (0);
}
