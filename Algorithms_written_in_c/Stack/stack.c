/**
 * 
 * Oussema Hidri
 * d.oussema.d@gmail.com
 *
 *
 * This is the implemantation and usage of a stack of integers.
 * In an other way a stack is a single linked list that can add and retrieve
 * elements only from head.
 */


#include <stdio.h>
#include <stdlib.h>

// defintion of a node in the stack
typedef struct node
{
	int value;
	struct node* next;
}node;


// prototypes
void push(node** stack, int element);
int pop(node** stack);
void printStack(node* stack);
void killStack(node* stack);



int main(void)
{

	// the Famous Stack
	node* stack = NULL;

	restart:
	// prints menu
	printf("Menu:\n");
	printf("1. push value into the stack\n");
	printf("2. pop value from the stack\n");
	printf("3. printf the stack\n");
	printf("4. exit\n");

	int choice = 0;

	while (choice <= 0 || choice > 4)
	{
		scanf("%d", &choice);
	}

	// clearing screen
	system("clear");

	switch (choice)
	{
		case 1:
			printf("value: \n");
			int enter;
			scanf("%d", &enter);

			// push the value
			push(&stack, enter);
		break;
		case 2:
			
			// pop the value and print it
			printf("The poped values is %d\n", pop(&stack));

			// enter 'q' to go back to menu
			char goback = 0;
			while (goback != 'q')
			{
				scanf("%c", &goback);
			}
		break;
		case 3:
			printf("stack:\n");
			printStack(stack);
			printf("\n");
			
			// enter 'q' to go back to menu
			goback = 0;
			while (goback != 'q')
			{
				scanf("%c", &goback);
			}
		break;
		case 4:
			killStack(stack);
			return 0;
		break;
	}

	// clearing screen and go back to menu
	system("clear");
	goto restart;

	return 0;
}

/**
 * push() will add @param value to @param stack.
 */
void push(node** stack, int value)
{
	// create a node and give it the value
	node* elem = malloc(sizeof(node));
	if (elem == NULL)
	{
		printf("Unable to create node\n");
		return;
	}
	elem->value = value;
	elem->next = NULL;

	// check if the stack is empty
	if (*stack == NULL)
	{
		*stack = elem;
	}
	else
	{
		elem->next = *stack;
		*stack = elem;
	}

}
/**
 * pop() will return the first element in the stack and free that node.
 */
int pop(node** stack)
{	
	int valueToReturn;

	// check if the stack is empty
	if (*stack == NULL)
	{	
		printf("Stack kis empty\n");
	}
	else
	{
		// get the value to return
		valueToReturn = (*stack)->value;
		// point to the node to be freed
		node* point = (*stack);
		// stack will point to the next node
		*stack = (*stack)->next;
		// free the node and return value
		free(point);
		return valueToReturn;
	}

	// return in case of the stack is empty
	return 0;
}

/**
 * printStack() will print the content of the stack.
 */
void printStack(node* stack)
{	
	// check if stack is empty
	if (stack == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{	
		// print elements until stack is NULL
		while (stack != NULL)
		{
			printf("%d  |\n", stack->value);
			printf("------\n");
			stack = stack->next;
		}	
	}
}


/**
 * killStack() will free all the stack
 */
void killStack(node* stack)
{	
	node* point = NULL;
	while (stack != NULL)
	{
		point = stack;
		stack = stack->next;
		free(point);
	}
}