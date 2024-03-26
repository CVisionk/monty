#include "monty.h"
#include <string.h>
/**
 * main - entry point
 * @argc: number of args
 * @argv: array of args
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t lineSize = 0;
	const char delim[] = " \t\n";
	char *token = NULL;

	if (argc != 2 )
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
	
	while(getline(&line, &lineSize, fp) != -1)
	{
		printf("%s", line);

		token = strtok(line, delim);	
		printf("$%s$\n", token);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, delim);
			printf("add to stack$%s$\n", token);
		} else
		{
			printf("functionCall$%s$\n", token);
		}
		token = strtok(NULL, delim);
		//printf("%s\n", NULL);
	}
	
	free(line);
	fclose(fp);

}
