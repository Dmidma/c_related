#include <stdio.h>
#include <stdlib.h>

// definition of a node
typedef struct node
{
	char value;
	struct node* next;
}node;


int main(void)
{

	// creat first node
	node* firstNode = malloc(sizeof(node));
	firstNode->value = 'a';
	firstNode->next = NULL;

	// creat second node
	node* secondNode = malloc(sizeof(node));
	secondNode->value = 'a';
	secondNode->next = NULL;

	// link the first to the second node
	firstNode->next = secondNode;


	free(secondNode);


	printf("Second node freed.\n");

	return 0;
}