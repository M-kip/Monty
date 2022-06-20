/**
* get_opcode - return a pointer to a function
* @opcode: opcode passed to function
*
* Return: pointer to the function that executes the opcode
*/
void (*get_opcode(char *opcode))(stack_t **head, unsigned int number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop}
	};
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			break;
	}
	
	return (instructions[i].f);
}
