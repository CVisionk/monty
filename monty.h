#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct stack_mode - holds constants
 *
 * Description: holds constants to operate on
 */

typedef struct stack_prop
{
        int line_count;
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
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

extern stack_t *head;
extern stack_t *tail;

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

stack_t *add_stack(const int n);



#endif
