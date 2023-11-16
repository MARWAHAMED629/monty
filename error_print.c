#include "monty.h"


/**
 * str_err - handles errors.
 * @error_c: The error codes are the following
 * (10) ~> A NUMBER inside a node is outside ASCII bounds.
 * (11) ~> THE STACK IS EMPTY.
 */
void str_err(int error_c, ...)
{
	va_list args;
	int line_num;

	va_start(args, error_c);
	line_num = va_arg(args, int);
	switch (error_c)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	frees_node();
	exit(EXIT_FAILURE);
}

/**
 * error - Prints appropiate error messages determined by their error code.
 * @error_c: The error code are the following:
 *
 *   (1) => The user did not provide a file or
 *    provided more than one file to the program.
 *   (2) => The file provided cannot be opened or read
 *   (3) => The file provided contains an invalid instruction.
 *   (4) => The program is unable to allocate more memory (malloc failed).
 *   (5) => The parameter passed to the "push" instruction is not an integer.
 *   (6) => The stack is empty when executing the "pint" instruction.
 *   (7) => The stack is empty when executing the "pop" instruction.
 *   (8) => he stack is too short for the requested operation.
 * @...: Variable arguments for file name, line number, or operation.
 */
void error(int error_c, ...)
{
	va_list a;
	char *operation;
	int line_n;

	va_start(a, error_c);
	switch (error_c)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(a, char *));
			break;
		case 3:
			line_n = va_arg(a, int);
			operation = va_arg(a, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_n, operation);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(a, int));
			break;
		default:
			break;
	}
	frees_node();
	exit(EXIT_FAILURE);
}




/**
 * more_myerror - handles errors.
 * @error_c: The error code are the following:
 * (6) =>  the stack it empty for the pint.
 * (7) => the stack it empty for the pop.
 * (8) =>  stack is too short for  theoperation.
 * (9) => Division by zero.
 */
void more_myerror(int error_c, ...)
{
	va_list a;
	char *operation;
	int line_n;

	va_start(a, error_c);
	switch (error_c)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(a, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(a, int));
			break;
		case 8:
			line_n = va_arg(a, unsigned int);
			operation = va_arg(a, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_n, operation);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(a, unsigned int));
			break;
		default:
			break;
	}
	frees_node();
	exit(EXIT_FAILURE);
}
