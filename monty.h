#ifndef MONTY_H
#define MONTY_H

/* headers for standard library functions and file management */
#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* struct type provided for the project */
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

/* custom struct type created for the project */

/**
 * struct absolute_parameters - absolute parameters
 * @cur_line: int; index of current line in monty file
 * @cur_arg: pointer to char; current argument of opcode
 * @stand_buffer: pointer to char; mounty file content in wait
 * @free_buffer: pointer to char; reference for free
 * @instruct: double pointer to instruction_t; list of opcodes
 * with related C functions
 * @init_stack: double pointer to stack_t; stack or queue
 *
 * Description: Absolute variables that are used by different
 * functions in different files
 * TheOwl
 */
typedef struct absolute_parameters
{
	int cur_line;
	char *cur_arg;
	char *stand_buffer;
	char *free_buffer;
	instruction_t instruct[3];
	stack_t **init_stack;
}abs_var;

extern abs_var monty_var;/* global variable */

/* functions to open and read monty files line by line */
char *ck_and_rd_file(int argc, char **argv);
char *read_lines(char *buffer, int l_number);
int line_number(char *buffer);
instruction_t get_instruction(char *l_buffer);

void free_dlistint(stack_t *head);

#endif
