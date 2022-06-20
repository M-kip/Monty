#include "monty.h"
/**
* push - adds an element to the stack
* @stack: doubly linked list
* @line_count: line number
*
* Return: void
*/
void push(stack_t **head, unsigned int line_count)
{
	int i, x;

	if (!globals.arg)
	{
		dprintf(2, "L:%u:", line_count);
		dprintf(2, "usage: push integer\n");
		free_globals();
		exit(EXIT_FAILURE);
	}
	for (i = 0; globals.arg[i] != '\0'; i++)
	{
		if (!isdigit(globals.arg[i]) && globals.arg[i] != '-')
		{
			dprintf(2, "L%u:", line_count);
			dprintf(2, "usage: push integer\n");
			free_globals();
			exit(EXIT_FAILURE);
		}
	}
	x = atoi(globals.arg);

	if (globals.lifo == 1)
		addNode(head, x);
	else
		addNodeEnd(head, x);
}
/**
* pall prints all the values on the stack
* @stack: doubly list
*
* Return: void
*/
void pall(stack_t **stack, unsigned int line_count)
{
	stack_t *temp;
	(void) line_count;
	temp = (*stack);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
* pint - prints the value at the top of the stack
* @head: the head of the linked list
* @line_count: lne number in opcode
*
* Return: void
*/
void pint(stack_t **head, unsigned int line_count)
{
	if (((*head) == NULL))
	{
		dprintf(2, "L%u: ", line_count);
		dprintf(2, "can't pint , stack empty\n");
		free_globals();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
/**
* pop - removes element from the stack
* @head: head of the list
* @line_count: line number of opcodes
*
* Return: void
*/
void pop(stack_t **head, unsigned int line_count)
{
	stack_t *node;

	if ((*head) == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_count);
		free_globals();
		exit(EXIT_FAILURE);
	}

	node = (*head);
	(*head) = (*head)->next;
	free(node);
}
/**
* swap - swaps elements on the stack (list)
* @head: head of the list
* line_count: line number opcode
*
* Return: void
*/
void swap(stack_t **head, unsigned int line_count)
{
	int n = 0;
	stack_t *tempNode;

	tempNode = (*head);
	while (tempNode != NULL)
	{
		tempNode = tempNode->next;
		n++;
	}
	if (n < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_count);
		free_globals();
		exit(EXIT_FAILURE);
	}

	tempNode = (*head);
	(*head) = (*head)->next;
	tempNode->next = (*head)->next;
	tempNode->prev = (*head);
	(*head)->next = tempNode;
	(*head)->prev = NULL;
}
