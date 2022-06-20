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
typedef instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
typedef global
{
	unsigned int count;
	char *buffer;
	stack_t *head;
	int lifo 
	FILE *fd;
	char *arg;
} global_t;
void push(stack_t **head, unsigned int line_count);
void pall(stack_t **stack, unsigned int line_count);
void pint(stack_t **head, unsigned int line_count);
void _pop(stack_t **head, unsigned int line_count);
void _swap(stack_t **head, unsigned int line_count);
void (*get_opcode(char *opcode))(stack_t **head, unsigned int number)
void push(stack **head, unsigned int line_count)
void pall(stack_t **stack, unsigned int line_count)
void pint(stack_t **head, unsigned int line_count)
void pop(stack_t **head, unsigned int line_count)
void swap(stack_t **head, unsigned int line_count)
stack_t addNode(stack_t **head, int data)
void deleteNode(stack_t *head)
stack_t *addNodeEnd(stack_t **head, int data)
