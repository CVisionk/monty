#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_prop - holds constants
 * @stack_length: length of stack
 * @stack_rot_180: something
 * Description: holds constants to operate on
 */

typedef struct stack_prop
{
	int stack_length;
	int stack_is_q;
	int stack_rot_180;
} stack_p;

extern stack_p prop;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void add_stack(stack_t **s, stack_t **t, unsigned int line_number, char sn[]);
void pop_stack_queue(stack_t **stack, unsigned int line_number);
void print_stack_queue(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);

void execute(stack_t **stack, unsigned int line_number, char str[]);

void f_add(stack_t **stack, unsigned int line_number);
#endif
