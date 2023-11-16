#include "monty.h"

/**
 * openfile - This functions  opens a files.
 * @f_name: it is  the file name path
 * Return: void
 */

void openfile(char *f_name)
{
	FILE *f_description = fopen(f_name, "r");

	if (f_name == NULL || f_description == NULL)
		error(2, f_name);

	readfile(f_description);
	fclose(f_description);
}

/**
 * readfile - This Functions it reads a file.
 * @f_description: it is a pointer to file descriptor
 * Return: void
 */

void readfile(FILE *f_description)
{
	int line_num, form = 0;
	char *buff = NULL;
	size_t l_lenght = 0;

	for (line_num = 1; getline(&buff, &l_lenght, f_description) != -1; line_num++)
	{
		form = parseline(buff, line_num, form);
	}
	free(buff);
}
