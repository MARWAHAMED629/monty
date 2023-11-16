#include "monty.h"


/**
 * addstack - Adds a node to the stack.
 * @nw_node: it is a Pointer to the new node.
 * @l_num:the line number of the operation code.
 */
void addstack(stack_t **nw_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *temp;

	if (nw_node == NULL || *nw_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nw_node;
		return;
	}
	temp = head;
	head = *nw_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * custom_pop - it is Adds a node to the stack.
 * @stack: the Pointer to pointing to top node of the stack.
 * @line_num: line number Interger representing the operation code.
 */
void custom_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_myerror(7, line_num);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
