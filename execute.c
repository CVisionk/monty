#include "monty.h"

/**
 * execute - execute commands
 * @stack: stack on nums;
 * @line_number: line in file
 * @opcode_input: input
 */

void execute(stack_t **stack, unsigned int line_number, char opcode_input[])
{
	size_t call_length;
	size_t i = 0;
	instruction_t call_functions[] = {
		{"pop", pop_stack_queue},
		{"pall", print_stack_queue},
		{"pint", f_pint},
		{"add", f_add}

	};

	call_length = sizeof(call_functions) / sizeof(call_functions[0]);

	for (i = 0; i < call_length; i++)
	{
		if (strcmp(opcode_input, call_functions[i].opcode) == 0)
		{
			call_functions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode_input);
	free_stack(stack, line_number);
	fflush(stderr);

}

/**
 * free_stack - frees the stack
 * @stack: head of stack
 * @line_number: lines read
 */

void free_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *temp;

	(void)line_number;
	while(head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
