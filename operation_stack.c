#include "monty.h"






/**
 * addition_mynode - it is Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void addition_mynode(stack_t **stack, unsigned int line_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_myerror(8, line_num, "add");

	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_mynode - it is sub of the top two elements of the stack.
 * @stack: it is a  pointer pointing to top node of the stack.
 * @line_num: line number Interger representing  of the operations code.
 */
void sub_mynode(stack_t **stack, unsigned int line_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_myerror(8, line_num, "sub");


	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_mynode - it is division the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void div_mynode(stack_t **stack, unsigned int line_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_myerror(8, line_num, "div");

	if ((*stack)->n == 0)
		more_myerror(9, line_num);
	(*stack) = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * multi_mynode - it is multipled top two elements of the stack.
 * @stack: Pointer  top node of the stack.
 * @line_num: line number Interger of the operation code.
 */
void multi_mynode(stack_t **stack, unsigned int line_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_myerror(8, line_num, "mul");

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * modulo_mynode - modulo the top two elements of the stack.
 * @stack: pointer pointing to top node of the stack.
 * @line_num: the line number of of the operation code.
 */
void modulo_mynode(stack_t **stack, unsigned int line_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_myerror(8, line_num, "mod");


	if ((*stack)->n == 0)
		more_myerror(9, line_num);
	(*stack) = (*stack)->next;
	result = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
