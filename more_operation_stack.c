#include "monty.h"

/**
 * no_operation - it Does nothing.
 * @stack:  a pointer pointing to top node of the stack.
 * @line_num:  the line number of the operation code.
 */
void no_operation(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}


/**
 * swap_stack - it is  Swaps the top two elements of the stack.
 * @stack: a pointer pointing to top node of the stack.
 * @line_num:  the line number of of the operation code.
 */
void swap_stack(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_myerror(8, line_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
