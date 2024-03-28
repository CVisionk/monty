#include "monty.h"

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
