#include "monty.h"
#include <string.h>

/*typedef struct stack_prop
{
        int line_count;
        int stack_length;
        int stack_is_q;
        int stack_rot_180;
} stack_prop;*/

stack_p prop = {0, 0, 0, 0};

stack_t *head = NULL;
stack_t *tail = NULL;
int line_count = 0;

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

			printf("added %d\n", (add_stack(atoi(token)))->n);
		} else
		{
			printf("functionCall$%s$\n", token);
		}
		token = strtok(NULL, delim);
	}
	printf("%d is next element\n", head->next->n);
	printf("%d is next next element\n", head->next->next->n);

	free(line);
	fclose(fp);

}
