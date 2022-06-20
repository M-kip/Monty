#include "monty.h"
global_t globals;
/**
* free_globals - free memory
*
* Returns: void
*/
void free_globals(void)
{
	free(globals.buffer);
	fclose(globals.fd);
}
/**
* start_globals - initialize globals
* @fd - file descriptor
*
* Return: always return None
*/
void start_globals(FILE *fp)
{
	globals.count = 1;
	globals.fd = fp;
	globals.buffer = NULL;
	globals.lifo = 1;
	globals.arg = NULL;
	globals.head = NULL;
}
/**
* main - Driver function for the interpreter
* @agrc: integer number of arguments
* @argv: array pointer to arguments
*
* Return: 0
*/
int main(int argc, char *argv[])
{
	FILE *fp;
	size_t size = 1024;
	ssize_t nlines = 0;
	char *tokens[2] = {NULL, NULL};
	void (*func)(stack_t **stack, unsigned int line_number);

	if ((argc == 1 || argc > 2))
	{
		perror("USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(2, "Error can't open %s \n", argv[1]);
		exit(EXIT_FAILURE);
	}
	start_globals(fp);
	nlines = getline(&globals.buffer, &size, fp);

	while (nlines != -1)
	{
		tokens[0] = _strtoky(globals.buffer, " \t\n");
		if (tokens[0] && tokens[0][0] != '#')
		{
			func = get_opcode(tokens[0]);
			if (!func)
			{
				dprintf(2, "L%u: unknown instruction %s\n", globals.count, tokens[0]);
				free_globals();
				exit(EXIT_FAILURE);
			}
			globals.arg = _strtoky(NULL, " \t\n");
			func(&globals.head, globals.count);
		}
		nlines = getline(&globals.buffer, &size, fp);
		globals.count++;
	}
	free_globals();
	return (0);
}
