#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

/**
 * struct instruction_s - opcode and its function
 * @opcode: operation code
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*operation)(stack_t **, unsigned int);



void readfile(FILE *);
int count_line_chars(FILE *);
void founnd_funcs(char *, char *, int, int);
void openfile(char *f_name);
int parseline(char *buff, int l_number, int form);

stack_t *generate_node( int a);
void frees_node(void);
void my_print_stack(stack_t **, unsigned int);
void addstack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void exe_function(operation, char *, char *, int, int);


void my_rotl(stack_t **, unsigned int);
void error(int error_c, ...);
void more_myerror(int error_c, ...);
void str_err(int error_c, ...);
void my_rotr(stack_t **, unsigned int);

void custom_print_top(stack_t **, unsigned int);
void custom_pop(stack_t **, unsigned int);
void no_operation(stack_t **, unsigned int);
void swap_stack(stack_t **, unsigned int);

void addition_mynode(stack_t **, unsigned int);
void sub_mynode(stack_t **, unsigned int);
void div_mynode(stack_t **, unsigned int);
void multi_mynode(stack_t **, unsigned int);
void modulo_mynode(stack_t **, unsigned int);
void my_print_char(stack_t **, unsigned int);
void my_print_str(stack_t **, unsigned int);

#endif
