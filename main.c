#include "monty.h"
#define _GNU_SOURCE

bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - entry point
* @argc: argument counter
* @argv: arguments array
*
* Return: always 0
*/
int main(int argc, char *argv[])
{
	char *line;
	FILE *fp;
	size_t size = 0;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	bus.fp = fp;

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &size, fp) > 0)
	{
		bus.line = line;
		counter++;

		execute(line, &stack, counter, fp);

		free(line);
		line = NULL;
	}

	free_stack(stack);
	fclose(fp);
	return (0);
}
