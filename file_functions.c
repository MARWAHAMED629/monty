#include "monty.h"
/**
 * found_funcs - find the appropriate for the operation code.
 * @opcode: THE operation code
 * @val: argument of opcode
 * @form:  storage format. If 0 Nodes will be entered as a stack.
 * @line_n: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void found_funcs(char *opcode, char *val, int line_n, int form)
{
	int c;
	int sign;

	instruction_t list_filefuncs[] = {
		{"push", addstack},
		{"pall", my_print_stack},
		{"pint", custom_print_top},
		{"pop", custom_pop},
		{"nop", no_operation},
		{"swap", swap_stack},
		{"add", addition_mynode},
		{"sub", sub_mynode},
		{"div", div_mynode},
		{"mul", multi_mynode},
		{"mod", modulo_mynode},
		{"pchar", my_print_char},
		{"pstr", my_print_str},
		{"rotl", my_rotl},
		{"rotr", my_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (sign = 1, c = 0; list_filefuncs[c].opcode != NULL; c++)
	{
		if (strcmp(opcode, list_filefuncs[c].opcode) == 0)
		{
			exe_function(list_filefuncs[c].f, opcode, val, line_n, form);
			sign = 0;
		}
	}
	if (sign == 1)
		error(3, line_n, opcode);
}

/**
 * parseline - Separates each line into tokens to determine
 * which function tio call
 * @buff: it is a  line from the file
 * @l_number: the line number
 * @form:  storage format If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: it Return 0 if the opcode is stack. 1 if queue.
 */

int parseline(char *buff, int l_number, int form)
{
	char *opcode, *val;
	const char *separator = "\n ";

	if (buff == NULL)
		error(4);

	opcode = strtok(buff, separator);
	if (opcode == NULL)
		return (form);
	val = strtok(NULL, separator);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	found_funcs(opcode, val, l_number, form);
	return (form);
}

/**
 * exe_function - it Calls the required function.
 * @p: Pointer to the function that is about to be called.
 * @o: string representing the operation code.
 * @value: it  string representing a numeric value.
 * @line_num: line numeber for the instruction.
 * @form: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void exe_function(operation p, char *o, char *value, int line_num, int form)
{
	stack_t *node;
	int sign;
	int a;

	sign = 1;
	if (strcmp(o, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			sign = -1;
		}
		if (value == NULL)
			error(5, line_num);
		for (a = 0; value[a] != '\0'; a++)
		{
			if (isdigit(value[a]) == 0)
				error(5, line_num);
		}
		node = generate_node(atoi(value) * sign);
		if (form == 0)
			p(&node, line_num);
		if (form == 1)
			add_queue(&node, line_num);
	}
	else
		p(&head, line_num);
}
