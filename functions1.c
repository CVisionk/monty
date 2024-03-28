#include "monty.h"

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
		fclose(bus.file);
		free(bus.content);
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
		fclose(bus.file);
		free(bus.content);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
* f_pall - print everything in stack
* @head: pointer to pointer of first node
* @counter: line counter (not used)
*
* Return: none
*/

void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
