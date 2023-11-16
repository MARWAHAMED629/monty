#include "monty.h"
/**
 * my_print_str - it Prints a string.
 * @stack: Pointer to a pointer pointing to top of the node.
 * @line_c: Interger representing the line number.
 */
void my_print_str(stack_t **stack, __attribute__((unused))unsigned int line_c)
{
	int Ascii;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		Ascii = temp->n;
		if (Ascii <= 0 || Ascii > 127)
			break;
		printf("%c", Ascii);
		temp = temp->next;
	}
	printf("\n");
}


/**
 * my_print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top the node.
 * @line_count: Interger representing the line of the number.
 */
void my_print_char(stack_t **stack, unsigned int line_count)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		str_err(11, line_count);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		str_err(10, line_count);
	printf("%c\n", ascii);
}

/**
 * my_rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node
 * @line_c: Interger representing the line number.
 */
void my_rotr(stack_t **stack, __attribute__((unused))unsigned int line_c)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}

/**
 * my_rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node..
 * @line_count: Interger representing the line number.
 */
void my_rotl(stack_t **stack, __attribute__((unused))unsigned int line_count)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
