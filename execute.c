#include "monty.h"

/**
 * execute - execute commands
 * @command: command to execute
 * @arg: arguments
 */

void execute(stack_t **stack, unsigned int line_number, char opcode_input[])
{
	size_t call_length;
	instruction_t call_functions[] = 
	{
		{"pop", pop_stack_queue}

	};
	call_length = sizeof(call_functions) / sizeof(call_functions[0]);

	for(int i = 0; i < call_length; i++)
	{
		if (strcmp(opcode_input, call_functions[i].opcode) == 0)
		{
			call_functions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode_input);

}
