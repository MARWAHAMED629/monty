#include "monty.h"
/**
 * my_print_stack - it is  Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @l_number: line number of  the opcode.
 */
void my_print_stack(stack_t **stack, unsigned int l_number)
{
	stack_t *temp;

	(void) l_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * custom_print_top - Prints the top node of the stack.
 * @stack: pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void custom_print_top(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
		more_myerror(6, line_num);
	printf("%d\n", (*stack)->n);
}
