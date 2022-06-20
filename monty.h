#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack ( or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list not structure
* for stack , queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s * prev;
	struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues , LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef struct global
{
	unsigned int count;
	char *buffer;
	stack_t *head;
	int lifo;
	FILE *fd;
	char *arg;
} global_t;
extern global_t globals;
void push(stack_t **head, unsigned int line_count);
void pall(stack_t **stack, unsigned int line_count);
void pint(stack_t **head, unsigned int line_count);
void _pop(stack_t **head, unsigned int line_count);
void _swap(stack_t **head, unsigned int line_count);
void (*get_opcode(char *opcode))(stack_t **head, unsigned int number);
void push(stack_t **head, unsigned int line_count);
void pint(stack_t **head, unsigned int line_count);
void pop(stack_t **head, unsigned int line_count);
void swap(stack_t **head, unsigned int line_count);
stack_t *addNode(stack_t **head, int data);
void deleteNode(stack_t *head);
stack_t *addNodeEnd(stack_t **head, int data);
int _sch(char *s, char c);
char *_strtoky(char *s, char *d);
int _strcmp(char *s1, char *s2);
void free_globals();

#endif
