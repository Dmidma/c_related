#include <stdio.h>
#include <stdlib.h>



typedef struct
{
	int value;
	struct node* next;
}node;



int main(void)
{
	node* elem = malloc(sizeof(node));

	elem->value = 5;
	elem->next = NULL;

	printf("%d\n", elem->value);

	free(elem);
}