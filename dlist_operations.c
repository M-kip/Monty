#include "monty.h"
/**
* push - adds data to a stack abstract type
* @head: pointer to pointer to head of list
* @data: data to be added to the stack
*
* Return: struct
*/
stack_t *addNode(stack_t **head, int data)
{
	stack_t  *node;

	if (head == NULL)
		exit(EXIT_FAILURE);
	node = (stack_t *)malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globals();
		exit(EXIT_FAILURE);
	}
	node->n = data;
	node->next = (*head);
	node->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = node;

	(*head) = node;

	return (node);
}
/**
* deleteNode - removes a node from the doubly linked list
* @head: head of the stack (dlist)
*
* Return: void
*/
void deleteNode(stack_t *head)
{
	stack_t *node;

	while ((node = head) != NULL)
	{
		head = head->next;
		free(node);
	}
}
/**
* addNodeEnd - add node to the end of the doubly linked list
* @head: head of the list
* @data: data to store
*
* Return: list
*/
stack_t *addNodeEnd(stack_t **head, int data)
{
	stack_t *temp;
	stack_t *node;

	if (head == NULL)
		exit(EXIT_FAILURE);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free_globals();
		exit(EXIT_FAILURE);
	}
	node->n = data;
	temp = (*head);
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;

	return (*head);
}
