#include "monty.h"

/**
* execute - execute opcode
* @stack: stack of linked list
* @counter: line counter
* @file: pointer to monty file stream
* @content: line content
*
* Return: none
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *fp)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(fp);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}

/**
 * f_pop - print top node on stack
 * @head: pointer to pointer of first node
 * @counter: line counter
 *
 * Return: none
 */

void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.fp);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	*head = h->next;
	free(h);
}

/**
 * f_pint - print top node on stack
 * @head: pointer to pointer of first node
 * @counter: line counter
 *
 * Return: none
 */

void f_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.fp);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * f_nop - do nothing
 * @head: pointer to pointer of first node
 * @counter: line counter
 *
 * Return: none
 */

void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}

/**
 * f_push - function that adds node to the stack
 * @head: double head pointer to the stack
 * @counter: line count
 *
 * Return: nothing
 */
void f_push(stack_t **head, unsigned int counter)
{
	int i, m = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			m++;
		for (; bus.arg[m] != '\0'; m++)
		{
			if (bus.arg[m] > 57 || bus.arg[m] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.fp);
			free(bus.line);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.fp);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, i);
	else
		addqueue(head, i);
}
